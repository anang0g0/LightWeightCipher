#include <stdio.h>
#include <math.h>


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

int main(void)
{
    int n;
    scanf("%d", &n);//入力された数値をnに代入
    printf("%d is a prime number : %s\n", n, IsPrime(n) == 0 ? "true" : "false");//結果を出力
    return 0;
}
