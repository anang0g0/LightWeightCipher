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
    unsigned short t[N]={0};
    double b[4],k=0;
    unsigned char u[N],u2[N],inv_u[N];
    unsigned char ss[N]={0},r[N]={0},z[N];

    srand(clock());

    //頂点の値ssはすべて異なるものとする
    for(i=0;i<N;i++)
      ss[i]=i;
  
      rp(u);
      rp(u2);
      for(i=0;i<N;i++)
      inv_u[u[i]]=i;

for(j=0;j<N;j++){
    for(i=0;i<N;i++)
      t[j]+=ss[i]^ss[(i+1)%N];
    for(i=0;i<N;i++)
      r[i]=ss[u2[i]];
    for(i=0;i<N;i++)
      z[i]=u[u2[inv_u[i]]];
      memcpy(u2,z,sizeof(u));
      memcpy(ss,r,sizeof(ss));
}
for(i=0;i<N;i++)
printf("%u,",t[i]);
printf("\n");


return 0;
}