#include <stdio.h>

const int n = 1018, N = n + 1;  /* N = 2017 -- prime     */
const int alpha = 2;            /* generator             */
const int beta = 5;             /* 2^{11} = 2048 = 31 (N) */

void new_xab(int *x, int *a, int *b) {
  switch (*x % 3) {
  case 0: *x = *x * *x     % N;  *a =  *a*2  % n;  *b =  *b*2  % n;  break;
  case 1: *x = *x * alpha % N;  *a = (*a+1) % n;                  break;
  case 2: *x = *x * beta  % N;                  *b = (*b+1) % n;  break;
  }
}

int main(void) {
unsigned  int x = 1, a = 0, b = 0;
unsigned int X = x, A = a, B = b;
  for (int i = 1; i < n; ++i) {
    new_xab(&x, &a, &b);
    new_xab(&X, &A, &B);
    new_xab(&X, &A, &B);
    printf("%3d  %4d %3d %3d  %4d %3d %3d\n", i, x, a, b, X, A, B);
    if (x == X) break;
  }
  printf("%d=(%d-%d)r=%d-%d=%d\n",(B-b)%2017,B,b,a,A,a-A);
for(int i=0;i<N;i++)
if(((B-b))*i%(N)==(a-A)%N)
printf("%d\n",i);

  return 0;
}
