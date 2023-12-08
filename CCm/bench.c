#include <stdio.h>
#include "roi.h"

#define STEP   256
#define ITERS  4096 

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    for(i=0; i < STEP; i+=1) {
      if(i==zero+2)  {
        t+=3+3*t;
      } else {
        t-=1-5*t;
      }
    }
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
