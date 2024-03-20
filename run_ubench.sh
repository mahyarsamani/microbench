#!/bin/bash
export LD_LIBRARY_PATH=${PWD}/../roi/papi/install/lib:$LD_LIBRARY_PATH

benchmarks=(DPcvt CCm CF1 MM EM5 ML2 MCS ED1 MM_st CRd MIM2 CS3 ML2_st MD
            SVE_SAXPY M_Dyn EI DP1f EM1 MI MC CRm STL2 STL2b CCa ML2_BW_st
            DP1d MIM DPT EF STc CCl CS1 CCh SVE_SUM DPTd CRf ML2_BW_ldst
            CCh_st MIP ML2_BW_ld CCe CCa_aligned CCe_aligned
            CCh_aligned CCh_st_aligned CCl_aligned CCm_aligned)

for bm in ${benchmarks[@]}; do
    echo $bm
    export PAPI_EVENTS="PAPI_LD_INS,PAPI_SR_INS,PAPI_BR_INS,PAPI_TOT_INS"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../data/azacca/single-core/microbench/$bm/instruction_data
    ./$bm/bench.papi
    export PAPI_EVENTS="PAPI_L1_ICM,PAPI_L1_ICA,PAPI_L1_DCM,PAPI_L1_DCA,PAPI_L2_LDM,PAPI_L2_DCA,PAPI_L2_TCA"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../data/azacca/single-core/microbench/$bm/memory_data
    ./$bm/bench.papi
    export PAPI_EVENTS="PAPI_BR_MSP,PAPI_BR_PRC,PAPI_RES_STL,PAPI_STL_ICY,PAPI_TOT_CYC"
    export PAPI_OUTPUT_DIRECTORY=${PWD}/../data/azacca/single-core/microbench/$bm/pipeline_data
    ./$bm/bench.papi
done
