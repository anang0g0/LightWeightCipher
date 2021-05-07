#include "global.h"
#include "struct.h"
#include "chash.c"

//324653895787272357988410799554010136716 225417171295519776360510534481775431469
//real	1m12.468s
//324653895787272357988410799554010136716 225417171295519776360510534481775431469
//real	1m21.364s

int main()
{
    //arrayul aa={0},
    arrayul n = {0};
    arrayul key = {0};
    int count = 0, i;
    unsigned char a = 111, b = 222, c;
    // time_t t;

    c = a * b;
    printf("%d\n", c);
    c = a * b % 256;
    printf("%d\n", c);
    //exit(1);

    rp2(x0);
    rp2(x1);
    //exit(1);

    key.x[0] = 12345; //(unsigned int)time(&t);
    key.x[1] = 54321; //(unsigned long)clock();

/*
    for (i = 0; i < NN; i++)
        printf("%d,", key.d[i]);
    printf("\n");
*/
    //for(i=0;i<NN/16;i++)
    //key.z[i]=n.z[i];

    for (i = 0; i < NN; i++)
        inv_x[x0[i]] = i;

    while (1)
    {
    for (i = 0; i < NN; i++)
        printf("%d,", key.d[i]);
    printf("\n");

        //i=rand();
        chash(&key);
        /*
        for(i=0;i<NN/16;i++){
        print_uint128(key.z[i]);
        printf(" ");
        }
        printf("\n");
        */
        count++;
        if (count == 10000000)
            break;
    }

    return 0;
}