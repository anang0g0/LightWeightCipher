///////////////////////////////////////////////////////////////////////////
//
// (lema-scheme)
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 32 //order of GF(q)


 void rp(unsigned char* a) {
        int i, j, x;
        time_t t;



        for (i = 0; i < N; i++) {
            a[i] = i;
        }
        for (i = 0; i < N - 2; i++) {
            // rand from i+1 to F-1
            j = (rand() % (N - 1 - i)) + i + 1;

            // swap a[i] and a[j]
            x = a[j];
            a[j] = a[i];
            a[i] = x;
        }
        if (a[N - 1] == N - 1) {
            a[N - 1] = a[N - 2];
            a[N - 2] = N - 1;
        }


 }



int main(){
  
    int i,j;
    int t[N]={0},t2[N]={0},t3[N]={0}; //public
    unsigned char u[N]; //public
    int ss[N]={0},r[N]={0},z[N]={0},e[N],e2[N],xx[N]={0};
    int v[N]={0};
    unsigned long long int l[N]={0},m[N]={0},n[N]={0};
    srand(clock());

    //頂点の値ssはすべて異なるものとする
    for(i=0;i<N;i++){
      e[i]=ss[i]=rand()%256; //secret
      e2[i]=xx[i]=rand()%256;
      printf("%d,%d %d,%d\n",e[i],ss[i],e2[i],xx[i]);
    }

   // exit(1);


      rp(u); //public

  //for(j=0;j<N;j++){
    for(i=0;i<N;i++){
      t[i]+=(ss[i]^ss[(i+1)%N]);
      l[j]^=t[i];
    }
    printf("%llu,",l[j]);
    for(i=0;i<N;i++)
      r[i]=ss[u[i]];

    memcpy(ss,r,sizeof(ss));
//}
printf("\n");

//for(i=0;i<N;i++)
//printf("%u,",t[i]);
//printf("\n\n");


//for(j=0;j<N;j++){
    for(i=0;i<N;i++){
      t2[i]+=(xx[i]^xx[(i+1)%N]);
      m[j]^=t2[i];
    }
    printf("%llu,",m[j]);
    for(i=0;i<N;i++)
      r[i]=xx[u[i]];

      memcpy(xx,r,sizeof(xx));
//}
printf("\n");

//for(i=0;i<N;i++)
//printf("%u,",t2[i]);
//printf("\n\n");

//for(i=0;i<N;i++)
//printf("%d,",u[i]);

for(i=0;i<N;i++)
v[i]=e[i]^e2[i];

//for(j=0;j<N;j++){
    for(i=0;i<N;i++){
      z[i]+=(v[i]^v[(i+1)%N]);
      n[j]^=z[i];
      
    }
    printf("%llu,",n[j]);
    for(i=0;i<N;i++)
      r[i]=v[u[i]];

      memcpy(v,r,sizeof(v));
//}
printf("\n\n");

for(i=0;i<N;i++)
printf("%d,%d\n",t[i]^t2[i],z[i]);
//abs((t[i]-t2[i])));
printf("\n\n");



return 0;
}