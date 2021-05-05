#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define N 256
#define NN 64
#define NB 4 /* 128bit 固定として規格されている(データの長さ) */
#define NBb 16
#define SEED 12345678901234567899ULL

typedef union
{
  unsigned long long int u[NN/8];
  unsigned char d[NN];
} arrayul;

typedef union
{
  unsigned long long int u[N];
  unsigned char d[N * 8];
} arrayull;

typedef union a4
{
  unsigned char ar[4];
  unsigned int n;
} array;

typedef struct a8
{
  unsigned char ar[8];
} array8;

typedef union
{
  unsigned int h[16];
  unsigned char c[64];
} array16;

typedef union aN
{
  unsigned int d[64];
  unsigned long long int u[32];
  unsigned char ar[256];
  //
} arrayn;

typedef struct pub
{
  unsigned char a[NN];
  unsigned char b[NN];
} set;

arrayn c = {0};

#define I8T char
#define U8C(v) (v##U)

#define U8V(v) ((unsigned char)(v)&U8C(0xFF))
#define ROTL8(v, n) \
  (U8V((v) << (n)) | ((v) >> (8 - (n))))

#define R(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

unsigned int rotate_left(unsigned int x, int n)
{
  assert(0 < n && n < 32);
  return (x << n) | (x >> (32 - n));
}

//言わずと知れたxorshift
unsigned int
xorshift()
{
  static unsigned int y = 2463534242;
  //  y = u ^ y;
  y = y ^ (y << 13);
  y = y ^ (y >> 17);
  return y = y ^ (y << 15);
}

unsigned long long int
xorshift64(unsigned long long int u)
{
  static unsigned long long int x = 88172645463325252ULL;
  x = x ^ u;
  x = x ^ (x << 13);
  x = x ^ (x >> 7);
  return x = x ^ (x << 17);
}

array half(unsigned char a)
{
  array b = {0};

  b.ar[0] = a & 0xf;
  a = (a >> 4);
  b.ar[1] = a;
  b.n = 2;

  return b;
}

void rp(unsigned char *a)
{
  unsigned int i, j, x;

  for (i = 0; i < NN; i++)
    a[i] = i;

  for (i = 0; i < NN - 2; i++)
  {
    // rand from i+1 to N-1
    j = (xorshift64(SEED) % (NN - 1 - i)) + i + 1;

    // swap a[i] and a[j]
    x = a[j];
    a[j] = a[i];
    a[i] = x;
  }
  if (a[NN - 1] == NN - 1)
  {
    a[NN - 1] = a[NN - 2];
    a[NN - 2] = NN - 1;
  }
}

/*
 * S-box transformation table
 */
static const unsigned char s_box[256] = {
    // 0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,  // 0
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,  // 1
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,  // 2
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,  // 3
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,  // 4
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,  // 5
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,  // 6
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,  // 7
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,  // 8
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,  // 9
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,  // a
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,  // b
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,  // c
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,  // d
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,  // e
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}; // f

/*
 * Inverse S-box transformation table
 */
static const unsigned char inv_s_box[256] = {
    // 0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,  // 0
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,  // 1
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,  // 2
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,  // 3
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,  // 4
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,  // 5
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,  // 6
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,  // 7
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,  // 8
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,  // 9
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,  // a
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,  // b
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,  // c
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,  // d
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,  // e
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d}; // f

//ハッシュ関数本体
arrayul
chash(unsigned char b[2048])
{
  int i; //, j = 0;
  arrayn n = {0};
  arrayul v = {0};
  static const unsigned char salt[NN] = {148, 246, 52, 251, 16, 194, 72, 150, 249, 23, 90, 107, 151, 42, 154, 124, 48, 58, 30, 24, 42, 33, 38, 10, 115, 41, 164, 16, 33, 32, 252, 143, 86, 175, 8, 132, 103, 231, 95, 190, 61, 29, 215, 75, 251, 248, 72, 48, 224, 200, 147, 93, 112, 25, 227, 223, 206, 137, 51, 88, 109, 214, 17, 172};
  unsigned char key[NN] = {0};
 unsigned char z[NN];
  unsigned char x0[NN] = {0};
  unsigned char inv_x[NN] = {0};
  unsigned char x1[NN] = {0};
unsigned char tmp[NN]={0};
  rp(x0);
  rp(x1);

  for (i = 0; i < NN; i++){
  key[i]=rand()%2;//salt[i];
  inv_x[x0[i]] = i;
  }
  int count = 0;

  //memset(f, 0, sizeof(f));
 while (count < 16)
  {
    //バッファを埋める回数だけ回す
      for (i = 0; i < NN; i++)
        z[i] = x0[x1[inv_x[i]]];

        for(i=0;i<NN;i++)
        key[i]^=key[z[i]];
        //for(i=0;i<NN;i++)
        //printf("%d,",key[i]);
        //printf("\n");
        //for(i=0;i<NN;i++)
        //key[i]=inv_s_box[key[i]];
        //memcpy(key,tmp,sizeof(key));
        //for(i=0;i<NN;i++)
        //printf("%d,",key[i]);
        //printf("\n");
        memcpy(x1,z,sizeof(x1));
/*
//#pragma omp parallel for private(f)
    for(j = 0; j < 2048; j++) //(j = 0; j < 2048 / (NN); j++)
    {

      //for (i = 0; i < NN; i++)
      {
        //mode 2(自己書き換え系)
        f[z[j%(NN)]] ^= b[j]; //(b[j] ^ key[j%NN]) | ROTL8(f[(j + 1) % NN] & salt[j%NN],3); 

      }
      //memcpy(x1, z, sizeof(z));
      // printf("%d,",f[i]);
    }
*/

    count++;
  }
  
    for (i = 0; i < NN; i++){
      v.d[i] = key[i];
      printf("%d,",v.d[i]);
    }
    printf("\n");
    /*
    for (i = 0; i < 8; i++)
      v.u[i] ^= xorshift64(v.u[i]);
    for (i = 0; i < NN; i++)
      v.d[i] |= inv_s_box[v.d[i]];
    */

  //memcpy(n.ar, v.d, sizeof(v.d));


  return v;
}

//ファイル操作
arrayul
hash(char *filename)
{
  int i, k, n,j,count=0;
  array16 h = {0};
  arrayul v={0};
  unsigned char buf[2048] = {0};
  FILE *fp;
  arrayn a = {0};
  static const unsigned char salt[NN] = {148, 246, 52, 251, 16, 194, 72, 150, 249, 23, 90, 107, 151, 42, 154, 124, 48, 58, 30, 24, 42, 33, 38, 10, 115, 41, 164, 16, 33, 32, 252, 143, 86, 175, 8, 132, 103, 231, 95, 190, 61, 29, 215, 75, 251, 248, 72, 48, 224, 200, 147, 93, 112, 25, 227, 223, 206, 137, 51, 88, 109, 214, 17, 172};
  unsigned char key[64] = {0};
 unsigned char z[NN];
  unsigned char f[NN] = {0};
  unsigned char x0[NN] = {0};
  unsigned char inv_x[NN] = {0};
  unsigned char x1[NN] = {0};

for(i=0;i<NN;i++)
  key[i]=i+1;

  rp(x0);
  rp(x1);

  fp = fopen(filename, "rb");
  if (fp == NULL)
  {
    printf("no file\n");
    exit(1);
  }

  while ((n = fread(buf, 1, 2048, fp)) >= 0)
  {
    //paddaing
    if (n < 2048)
    {
      for (i = n; i < 2048; i++)
      {
        buf[i] = 0xc6;
        //printf("%d,",buf[i]);
      }
    }
    count=0;
    //while(count<16){
        //バッファを埋める回数だけ回す
      for (i = 0; i < NN; i++)
        z[i] = x0[x1[inv_x[i]]];

    for(i=0;i<NN;i++)
    key[i]^=s_box[ROTL8(key[i],3)];
    for(j = 0; j < 2048; j++) //(j = 0; j < 2048 / (NN); j++)
    {


        //mode 2(自己書き換え系)
        f[z[j%(NN)]] += (s_box[buf[j] & key[j%NN]]) ^ (inv_s_box[ROTL8(f[(j + 1) % NN] | salt[j%NN],3)]); 

      //
      // printf("%d,",f[i]);
    }
    //for(i=0;i<NN;i++)
    //key[i]^=inv_s_box[ROTL8(key[i],3)];
    count++;
//    printf("%d\n",count);
    memcpy(x1, z, sizeof(z));
    //}
    //printf("\n");
    //a = chash(buf);
    
      for (i = 0; i < NN; i++)
      v.d[i] &= s_box[f[i]];
      for (i = 0; i < 8; i++)
      v.u[i] ^= xorshift64(v.u[i]);
      //for (i = 0; i < NN; i++)
      //v.d[i] |= s_box[v.d[i]];
      //count++;
      
    //}
/*
    for (k = 0; k < NN / 64; k++)
    {
      for (i = 64 / 4 * k; i < 64 / 4 * k + 64 / 4; i++)
        h.h[i - 64 / 4 * k] ^= a.d[i];
    }
    */
    if (n == 0)
      break;
  }

  return v;
}

//蛇足
arrayul
crand(unsigned char u[NN])
{
  arrayn a = {0};
  arrayul b = {0};

  b = chash(u);

  //memset(b.u, 0, sizeof(b.u));
  //memcpy(b.d, a.ar, sizeof(unsigned char) * NN);

  return b;
}

int main(int argc, char *argv[])
{
  int i;
  arrayul t={0};
 // unsigned char u[NN]={0};
  //  time_t o;

while(1){
t=chash(t.d);
  //慎ましくここは256ビットだけ
  //for (i = 0; i < NN; i++)
    //printf("%02x", t.d[i]);
    //printf("\n");
}

 t = hash(argv[1]);
  for (i = 0; i < NN; i++)
    printf("%02x", t.d[i]);
    printf("\n");
 
  //  srand (clock () + time (&o));
  printf(" %s", argv[1]);
  printf("\n");

  return 0;
}
