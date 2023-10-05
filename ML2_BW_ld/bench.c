#include <stdio.h>
#include <stdlib.h> /* malloc, free, rand */

#include "common.h"

#define ASIZE 65536
#define STEP 128
#define ITERS 65536
#define LEN 2048

typedef struct dude
{
    int p1, p2, p3, p4;
} dude;

dude arr[ASIZE];
__attribute__((noinline)) int loop(int zero)
{
    int t = 0, count = 0;

    unsigned lfsr = 0xACE1u;
    do
    {
        count++;
        lfsr = (lfsr >> 1) ^ (-(lfsr & 1u) & 0xB400u);
        t += arr[lfsr].p1 + arr[lfsr].p2 + arr[lfsr].p3;

    } while (++count < ITERS);

    return t;
}

int main(int argc, char *argv[])
{
    argc &= 10000;
    ROI_BEGIN();
    int t = loop(argc);
    ROI_END();
    volatile int a = t;
}