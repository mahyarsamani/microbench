#include "roi.h"
#include <stdio.h>
#include <stdlib.h> /* malloc, free, rand */

#define ASIZE 65536
#define STEP 128
#define ITERS 8
#define LEN 2048

typedef struct dude {
  int p1, p2, p3, p4;
} dude;

dude arr[ASIZE];
__attribute__((noinline)) int loop(int zero) {
  int t = 0, count = 0;
  for (int iter = 0; iter < ITERS; iter++) {
    unsigned lfsr = 0xACE1u;
    do {
      /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
      lfsr = (lfsr >> 1) ^ (-(lfsr & 1u) & 0xB400u);

      arr[lfsr].p4 = lfsr;

      lfsr = lfsr + arr[lfsr].p1;

      //} while(++count < ITERS);
    } while (lfsr != 0xACE1u);
  }
  return t;
}

int main(int argc, char *argv[]) {
  argc &= 10000;
  annotate_init_();
  roi_begin_();
  int t = loop(argc);
  roi_end_();
  volatile int a = t;
}
