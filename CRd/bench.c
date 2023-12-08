#include <stdio.h>
#include "roi.h"

#define STEP   128
#define ITERS   20

__attribute__ ((noinline))
int rec(int i){
  if(i==0) return 0;
  if(i==1) return 1;
  if(i<1024) {
    return rec(i-1)+rec(i/2);
  } else {
    return 5;
  }
}

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    t+=rec(iter*8);
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
