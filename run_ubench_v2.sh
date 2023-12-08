#!/bin/bash

export LD_LIBRARY_PATH=${PWD}/../roi/papi/install/lib:$LD_LIBRARY_PATH

benchmarks=(CCh ED1 CCa EM5 EM1 EI DPTd ML2_st CCh_st DPT MM DP1d CRf STL2
        MIM2 CCe ML2 ML2_BW_ldst MI MC CRd CCl MIM M_Dyn MM_st ML2_BW_st DP1f
        MD STc CS3 STL2b CCm CS1 SVE_SAXPY MIP EF SVE_SUM MCS ML2_BW_ld DPcvt)

for bm in ${benchmarks[@]}; do
    echo $bm
    export PAPI_EVENTS="PAPI_L1_DCR,PAPI_L1_DCW,PAPI_L1_DCM,PAPI_L1_DCA,PAPI_TLB_DM"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../microbench-data-grace/$bm/backend0_data
    echo "backend0"
    ./$bm/bench.papi
    export PAPI_EVENTS="PAPI_L2_TCR,PAPI_L2_TCW,PAPI_L2_TCM,PAPI_L2_TCA,PAPI_L3_DCM,PAPI_L3_TCA"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../microbench-data-grace/$bm/backend1_data
    echo "backend1"
    ./$bm/bench.papi
    export PAPI_EVENTS="PAPI_L1_ICM,PAPI_L1_ICH,PAPI_L1_ICA,PAPI_TLB_IM"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../microbench-data-grace/$bm/frontend_data
    echo "frontend"
    ./$bm/bench.papi
    export PAPI_EVENTS="PAPI_TOT_INS,PAPI_INT_INS,PAPI_FP_INS,PAPI_LD_INS"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../microbench-data-grace/$bm/inst0_data
    echo "inst0"
    ./$bm/bench.papi
    export PAPI_EVENTS="PAPI_SR_INS,PAPI_BR_INS,PAPI_VEC_INS"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../microbench-data-grace/$bm/inst1_data
    echo "inst1"
    ./$bm/bench.papi
    export PAPI_EVENTS="PAPI_STL_ICY,PAPI_STL_CCY,PAPI_BR_MSP,PAPI_BR_PRC,PAPI_RES_STL,PAPI_TOT_CYC,PAPI_LST_INS"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../microbench-data-grace/$bm/pipe0_data
    echo "pipe0"
    ./$bm/bench.papi
    export PAPI_EVENTS="PAPI_SYC_INS,PAPI_FP_OPS,PAPI_REF_CYC"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../microbench-data-grace/$bm/pipe1_data
    echo "pipe1"
    ./$bm/bench.papi
done
