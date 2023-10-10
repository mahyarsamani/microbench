#!/bin/bash

benchmarks=(CCa CCe CCh CCh_st CCl CCm CF1 CRd CRf CRm CS1 CS3 DP1d DP1f DPcvt
            DPT DPTd ED1 EF EI EM1 EM5 MC MCS MD M_Dyn MI MIM MIM2 MIP ML2
            ML2_BW_ld ML2_BW_ldst ML2_BW_st ML2_st MM MM_st STL2 STL2b)

for bm in $benchmarks; do
    echo $bm
    export PAPI_EVENTS="PAPI_L1_DCM,PAPI_L1_DCA,PAPI_L2_LDM,PAPI_L2_DCA,PAPI_L2_TCA,PAPI_L1_ICA,PAPI_L1_ICM"
    export PAPI_OUTPUT_DIRECTORY=/home/msamani/darchr/novoverse/microbench_native/$bm/memory_data
    ./$bm/bench.papi
    export PAPI_EVENTS="PAPI_TLB_DM,PAPI_STL_ICY,PAPI_BR_MSP,PAPI_BR_PRC,PAPI_BR_INS,PAPI_TOT_CYC"
    export PAPI_OUTPUT_DIRECTORY=/home/msamani/darchr/novoverse/microbench_native/$bm/pipeline_data
    ./$bm/bench.papi
done




