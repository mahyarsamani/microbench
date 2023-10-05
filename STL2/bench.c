#include <stdio.h>
#include <stdlib.h> /* malloc, free, rand */

#include "common.h"

#define ASIZE 65536
#define STEP 128
#define ITERS 4096
#define LEN 2048

typedef struct dude
{
    int p1, p2, p3, p4;
} dude;

dude arr[ASIZE];

__attribute__((noinline)) int loop(int zero)
{
    int count = 0;

    unsigned lfsr = 0xACE1u;
    do
    {
        lfsr = (lfsr >> 1) ^ (-(lfsr & 1u) & 0xB400u);
        arr[lfsr].p1 = lfsr;
    } while (++count < ITERS);

    return arr[zero].p1;
}

int main(int argc, char *argv[])
{
    argc &= 10000;
    ROI_BEGIN();
    int t = loop(argc);
    ROI_END();
    volatile int a = t;
}