#include <stdio.h>
#include <stdlib.h>

#include "common.h"

#define AMULT 65536
#define ASIZE 32
#define AMASK (ASIZE - 1)
#define ITERS 4096

int arr1[ASIZE * AMULT];
int arr2[ASIZE * AMULT];

__attribute__((noinline)) int loop(int zero)
{
    int acc1 = 1, count = 0;
    int acc2 = 2;

    unsigned lfsr = 0xACE1u;
    unsigned lfsr2 = 0x0143u;

    do
    {
        lfsr = (lfsr >> 1) ^ (-(lfsr & 1u) & 0xB400u);
        acc1 += arr1[(lfsr & AMASK) * AMULT];

        lfsr2 = (lfsr2 >> 1) ^ (-(lfsr2 & 1u) & 0xB400u);
        acc2 += 1;
        arr1[(lfsr2 & AMASK) * AMULT] = acc2;

    } while (++count < ITERS);

    return acc1;
}

int main(int argc, char *argv[])
{
    argc &= 10000;
    ROI_BEGIN();
    int t = loop(argc);
    ROI_END();
    volatile int a = t;
}
