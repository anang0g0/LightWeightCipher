/* C++ program to find a prime factor of composite using
   Pollard's Rho algorithm */
#include<stdio.h>
#include <math.h>

// GCD
long long int gcd(long long int xx,long long int yy){
  long long int tt;

  while (yy != 0){
    tt = xx % yy;
    xx = yy;
    yy = tt;
    }

  return xx;
  
}

int isqrt(int x){
int t,s;

/*
if(x==0)
return0;
*/
s=1;
t=x;
while(s<t){
s<<=1;
t>>=1;
}
while(s<t){
t=s;
s=(x/s+s)>>1;
}

return t;

}

int IsPrime(int n)//0なら素数
{
    if (n == 2)
    {
        return 0;
    }
    else if (n % 2 == 0 || n < 2)
    {
        return 1;
    }
    else
    {
        for (int i = 3; i <= isqrt(n); i += 2)
        {
            if (n % i == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}


/* Function to calculate (base^exponent)%modulus */
long long int modular_pow(long long int base, int exponent,
                          long long int modulus)
{
    /* initialize result */
    long long int result = 1;
 
    while (exponent > 0)
    {
        /* if y is odd, multiply base with result */
        if (exponent & 1)
            result = (result * base) % modulus;
 
        /* exponent = exponent/2 */
        exponent = exponent >> 1;
 
        /* base = base * base */
        base = (base * base) % modulus;
    }
    return result;
}
 
/* method to return prime divisor for n */
long long int PollardRho(long long int n)
{
    /* initialize random seed */
    srand (time(NULL));
 
    /* no prime divisor for 1 */
    if (n==1) return n;
 
    /* even number means one of the divisors is 2 */
    if (n % 2 == 0) return 2;

    if (n % 3 == 0) return 3;
    if (n % 5 == 0) return 5;
    if (n % 7 == 0) return 7;
    
    /* we will pick from the range [2, N) */
    long long int x = (rand()%(n-2))+2;
    long long int y = x;
 
    /* the constant in f(x).
     * Algorithm can be re-run with a different c
     * if it throws failure for a composite. */
    long long int c = (rand()%(n-1))+1;
 
    /* Initialize candidate divisor (or result) */
    long long int d = 1;  
 
    /* until the prime factor isn't obtained.
       If n is prime, return n */
    while (d==1)
    {
        /* Tortoise Move: x(i+1) = f(x(i)) */
        x = (modular_pow(x, 2, n) + c + n)%n;
 
        /* Hare Move: y(i+1) = f(f(y(i))) */
        y = (modular_pow(y, 2, n) + c + n)%n;
        y = (modular_pow(y, 2, n) + c + n)%n;
 
        /* check gcd of |x-y| and n */
        d = gcd(abs(x-y), n);
 
        /* retry if the algorithm fails to find prime factor
         * with chosen x and c */
        if (d==n) return PollardRho(n);
    }
 
    return d;
}
 
/* driver function */
int main()
{
    long long int n;  // = 10967535067;
    long long int x;
scanf("%lld",&n);


while(x!=1){

if(IsPrime(n)==0){
printf("n is Prime %d\n",n);
return 0;
}

    printf("One of the divisors for %lld.\n", n);

x=PollardRho(n);
n/=x;
    printf("One of the divisors for %lld is %lld.\n", n, x);
}

    return 0;
}