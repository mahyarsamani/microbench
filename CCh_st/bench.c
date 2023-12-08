#include <stdio.h>
#include "roi.h"
#include "randArr.h"

#define ASIZE 2048
#define STEP   256
#define ITERS 8192

int arr[ASIZE];

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    for(i=0; i < STEP + zero; i+=1) {
      if(randArr[i])  {
        t+=3+3*t;
        arr[i]=t;
      } else {
        t-=1-5*t;
      }
    }
  }
  return arr[zero]+t;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   annotate_init_();
	roi_begin_(); 
   int t=loop(argc); 
   roi_end_();
   volatile int a = t;
}
