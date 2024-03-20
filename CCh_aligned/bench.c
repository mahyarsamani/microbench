#include "randArr.h"
#include "roi.h"
#include <stdio.h>

#define STEP 16384
#define ITERS 128

__attribute__((aligned(64), noinline)) int loop(int zero) {
  int t = 0, i, iter;
  for (iter = 0; iter < ITERS; ++iter) {
    for (i = 0; i < STEP + zero; i += 1) {
      if (randArr[i]) {
        t += 3 + 3 * t;
      } else {
        t -= 1 - 5 * t;
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
