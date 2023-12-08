#include <stdio.h>
#include "roi.h"
#include "randArr.h"

#define STEP   128
#define ITERS  8192

__attribute__ ((noinline))
int loopy_helper(int i,int zero){
  return (i*2+zero)*3+(i+zero)*(i+zero);
}

__attribute__ ((noinline))
int func_loopy(int i,int zero){
  int l,k=i;
  if(i<16) {
    return loopy_helper(i+4,zero);
  }
  for(l=i-16; l < i+zero; ++l) {
    k+=(k+l+randArr[l])&0x10101;
    randArr[l]=loopy_helper(k,zero);
  }
  return k;
}

__attribute__ ((noinline))
int func_no_loopy(int i ){
  return (i+10+randArr[i])%16;
}

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;

  for(iter=zero; iter < ITERS; ++iter) {
    t+=func_loopy(iter,zero);
  }

  for(iter=zero; iter < ITERS; ++iter) {
    t+=func_no_loopy(iter);
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
