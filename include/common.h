#ifndef COMMON_H
#define COMMON_H

#if defined(PAPI)
#include "papi.h"

#define ROI_BEGIN() int retval = PAPI_hl_region_begin("ROI"); \
                    if (retval != PAPI_OK) { \
                        printf("PAPI_hl_region_begin failed\n"); \
                        return -1; \
                    }

#define ROI_END()   retval = PAPI_hl_region_end("ROI"); \
                    if (retval != PAPI_OK) { \
                        printf("PAPI_hl_region_end failed\n"); \
                        return -1; \
                    }



#elif defined(GEM5)
#include "gem5/m5ops.h"

#define ROI_BEGIN() m5_work_begin(0,0);
#define ROI_END() m5_work_end(0,0);


#else
#include <time.h>

#define ROI_BEGIN() \
    ticks _Time0, _Time1; \
    _Time0 = _ClockGetTime();
#define ROI_END() \
    _Time1 = _ClockGetTime(); \
    printf("_ticks: %llu\n",_Time1 - _Time0);


typedef unsigned long long ticks;
static inline __attribute__((always_inline)) ticks _ClockGetTime()
{
    return 0;
}

#endif //define PAPI

#endif //define COMMON_H
