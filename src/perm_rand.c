#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 64
#define NN 4

unsigned char x0[N] = {0};
unsigned char x1[N] = {0};
unsigned char x2[N] = {0};

void rp(unsigned char *a)
{
  int i, j, x;
  for (i = 0; i < N; i++)
  {
    a[i] = i;
  }
  for (i = 0; i < N - 2; i++)
  {
    // rand from i+1 to N-1
    j = (rand() % (N - 1 - i)) + i + 1;

    // swap a[i] and a[j]
    x = a[j];
    a[j] = a[i];
    a[i] = x;
  }
  if (a[N - 1] == N - 1)
  {
    a[N - 1] = a[N - 2];
    a[N - 2] = N - 1;
  }
}

unsigned int cnt = 0;

void data()
{
  unsigned long long int i, j = 0, k = 0;
  unsigned char a[N] = {0, 166, 108, 148, 136, 242, 113, 68, 172, 152, 19, 72, 49, 199, 89, 13, 23, 210, 214, 187, 77, 68, 204, 4, 150, 239, 243, 60, 165, 236, 121, 206, 226, 180, 26, 143, 162, 169, 124, 58, 94, 148, 232, 95, 227, 204, 18, 170, 34, 249, 221, 20, 138, 84, 147, 71, 131, 190, 225, 166, 114, 133, 31, 252}; //{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
  unsigned short aa = 0;

  unsigned char z[N];
  unsigned char w[N];
  unsigned char ww[N] = {0};

  for (i = 0; i < N; i++)
    x2[x0[i]] = i;

  while (j < 100000000)
  {

    for (i = 0; i < N; i++)
      ww[i] = a[x1[i]];
    for (i = 0; i < N; i++)
      a[i] ^= ww[i];
    if (a[0] % 2 == 0)
      cnt++;

    /*
    aa=0;
    for(cnt=0;cnt<NN;cnt++){
      
      for(i=cnt*8;i<8*cnt+8;i++){
	aa=aa<<1;
	aa^=a[i];
      }
    }

	  fwrite(&aa,NN,1,fp);
  */

    for (i = 0; i < N; i++)
      w[i] = x0[x1[x2[i]]];

    //for (i = 0; i < N; i++)
    //  x1[i] = w[i];

    memcpy(x1,w,sizeof(x1));

    j++;
  }
}

int main()
{
  FILE *fp;
  time_t t;
  int i;

  //srand(clock() + time(&t));
  //初期化しないとひどいことになる謎
  srand(2);

  rp(x0);
  rp(x1);
for(i=0;i<N;i++)
printf("%d,",x0[i]);
printf("\n");
for(i=0;i<N;i++)
printf("%d,",x1[i]);
printf("\n");
  //  fp = fopen("rand.dat", "wb");
  data();
  printf("count=%d\n",cnt);
  //  fclose(fp);

  return 0;
}
