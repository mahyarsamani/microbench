#include <stdio.h>
#include "roi.h"

#define ASIZE  8192
#define ITERS   128

float arrA[ASIZE];
float arrB[ASIZE];

__attribute__ ((noinline))
float loop(int zero) {
  int i, iters;
  float t1;

  for(iters=0; iters < ITERS; iters+=1) {
    for(i=0; i < ASIZE; i+=1) {
      arrA[i] += arrB[i]*3.2f ;
    }
    t1+=arrA[ASIZE-1];
  }

  return t1;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   annotate_init_();
	roi_begin_();
   int t=loop(argc);
   roi_end_();
   volatile float a = t;
}
