#include <stdio.h>
#include "roi.h"

#define STEP   128
#define ITERS  28

__attribute__ ((noinline))
int fib(int i ){
  if(i==0) return 0;
  if(i==1) return 1;
  return fib(i-1) + fib(i-2);
}

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    t+=fib(iter);
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
