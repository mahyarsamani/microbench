#include <stdio.h>
#include "roi.h"

#define ITERS 16384 * 32

__attribute__ ((noinline))
int loop(int zero) {
  int t1 = zero*zero+zero+1;

  int i;
  for(i=zero; i < ITERS; i+=1) {
    t1=t1/(zero+1);
  }
  return t1;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   annotate_init_();
	roi_begin_(); 
   int t=loop(argc); 
   roi_end_();
   volatile int a = t;
}
