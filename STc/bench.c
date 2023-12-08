#include <stdio.h>
#include "roi.h"

#define ASIZE   2048
#define STEP    1024
#define ITERS   2048

int arr[ASIZE];

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    for(i=zero; i < STEP; ++i) {
      arr[i]=i; 
    }
    t+=arr[ASIZE-1-zero];
  }
  return t;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   annotate_init_();
	roi_begin_(); 
   int t=loop(argc); 
   roi_end_();
   volatile int a = t;
}