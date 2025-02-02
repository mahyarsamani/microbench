#include "roi.h"
#include <stdio.h>

#define ASIZE (65536 * 4)
#define STEP 1280
#define ITER 2

float arr[ASIZE];
float arr1[ASIZE];
float arr2[ASIZE];
float arr3[ASIZE];
float arr4[ASIZE];
float arr5[ASIZE];
float arr6[ASIZE];
float arr7[ASIZE];
float arr8[ASIZE];
float arr9[ASIZE];

__attribute__((noinline)) float loop3(int zero) {
  float f = 0;
  for (int k = 0; k < ITER; k++) {
    for (int i = 0; i < ASIZE; i += 1) {
      int ind = i & (STEP - 1);
      arr1[ind] = i;
      arr2[ind] = i;
      arr3[ind] = i;
      arr4[ind] = i;
      arr5[ind] = i;
      arr6[ind] = i;
      arr7[ind] = i;
      arr8[ind] = i;
      arr9[ind] = i;
      //f=f*f*f*f*f*f*f*f*f*f*f;
    }
  }
  return f;
}

int main(int argc, char *argv[]) {
  argc &= 10000;
  //loop0(argc);
  //loop1(argc);
  //loop2(argc);

  annotate_init_();
  roi_begin_();
  float f = loop3(argc);
  roi_end_();
  volatile float a = f;
}
