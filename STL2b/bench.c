#include <stdio.h>
#include "roi.h"

#define ASIZE    131072
#define STEP     512
#define ITERS    8192

int arr[ASIZE];

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    for(i=iter; i < ASIZE; i+=STEP) {
      arr[i]=i;
    }
    t+=arr[zero];
  }
  return t+arr[zero];
}

int main(int argc, char* argv[]) {
   argc&=10000;
   annotate_init_();
	roi_begin_(); 
   int t=loop(argc); 
   roi_end_();
   volatile int a = t;
}
