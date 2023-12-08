#include <stdio.h>
#include "roi.h"
#include <stdlib.h>

#define ASIZE 4096
#define ITERS 512

double loop(int zero) {
  int i, iters;
  double t1;
  float *src = (float*) malloc(sizeof(float) * ASIZE);
  float *dest = (float*) malloc(sizeof(float) * ASIZE);
  for(iters=zero; iters < ITERS; iters+=1) {
    for(i=zero; i < ASIZE; i+=1) {
      dest[i] += 2 * src[i];
    }
    t1 = dest[ASIZE-1];
  }
  return t1;
}

int main(int argc, char* argv[]) {
   argc&=1000;
   annotate_init_();
	roi_begin_();
   int t=loop(argc);
   roi_end_();
   volatile int a = t;
}
