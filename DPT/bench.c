#include "math.h"
#include "roi.h"
#include <stdio.h>

#define ASIZE 8192
#define ITERS 256

float arrA[ASIZE];
float arrB[ASIZE];

__attribute__((noinline)) float loop(int zero) {
  float t1 = zero * zero + zero + 1;

  for (int iters = 0; iters < ITERS; iters += 1) {
    for (int i = 0; i < ASIZE; i += 1) {
      arrB[i] = (arrA[i]) / t1;
    }
    t1 += arrB[ASIZE - 1];
  }

  return t1;
}

int main(int argc, char *argv[]) {
  argc &= 10000;
  annotate_init_();
  roi_begin_();
  int t = loop(argc);
  roi_end_();
  volatile float a = t;
}
