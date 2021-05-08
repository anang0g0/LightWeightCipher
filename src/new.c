#include "global.h"
#include "struct.h"
#include "chash.c"



int main()
{
    arrayul key={0}; 
    unsigned char salt[NN]= {125,166,108,148,136,242,113,68,172,152,19,72,49,199,89,13,23,210,214,187,77,68,204,4,150,239,243,60,165,236,121,206,226,180,26,143,162,169,124,58,94,148,232,95,227,204,18,170,34,249,221,20,138,84,147,71,131,190,225,166,114,133,31,252};
    int count = 0, i;
    //time_t t;

    rp2(x0);
    rp2(x1);
    //exit(1);
    memcpy(key.d,salt,sizeof(salt));
    //key.u[0] = 0xdeadbeef; //4567890; //(unsigned int)time(&t);
    //key.u[1] = 0xff11face;        //ff11face; //9876543210; //(unsigned long)clock();
    printf("%lld, %lld\n", key.u[0], key.u[1]);
    nonce.u[0]=3; //0x1234567890abcdef;
    

    for (i = 0; i < NN; i++)
    {
        printf("%d,", key.d[i]);
    }
    printf("\n");

    for (i = 0; i < NN; i++)
        inv_x[x0[i]] = i;
/*
    for (i = 0; i < 8; i++)
    {
        chash(&key);
    }
    for (i = 0; i < NN; i++)
        printf("%d,", key.d[i]);
    printf("\n");
*/
    //exit(1);

    while (1)
    {
        //i=rand();
        for (i = 0; i < NN; i++)
            z[i] = x0[x1[inv_x[i]]];

        chash(&key);

        count++;
        if (count == 1000000)
            break;
    

    for (i = 0; i < NN / 16; i++)
    {
        print_uint128(key.z[i]);
        printf(" ");
    }
    printf("\n");

    }
    for (i = 0; i < NN / 16; i++)
    {
        print_uint128(key.z[i]);
        printf(" ");
    }
    printf("\n");
    printf("counter2=%d\n",counter2);

    return 0;
}