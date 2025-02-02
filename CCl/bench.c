#include "randArr.h"
#include "roi.h"
#include <stdio.h>

#define STEP 256
#define ITERS 2048

__attribute__((noinline)) int loop(int zero) {
  int t = 0, i, iter;
  for (iter = 0; iter < ITERS; ++iter) {
    for (i = 0; i < STEP + zero; i += 1) {
      if (randArr[i]) {
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
      } else {
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
        t &= 0xFFF;
        t += 3 + 3 * t;
      }
    }
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
