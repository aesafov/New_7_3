#ifndef XP_CDS_OUT_H_
#define XP_CDS_OUT_H_

#include "x_basic_types.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef union {
    UInt16 all;
    struct {
        UInt16 error_latch_er0_in   : 1;
        UInt16 error_er0_out        : 1; // sum of error
        UInt16 line_status_er0      : 1;
        UInt16 line_status_set_mode : 1;
        UInt16 error_latch_power    : 1;
        UInt16 error_latch_switch   : 1;
        UInt16 use_shared_lines     : 1;
        UInt16 unused_all_0         : 9;
    }bit;
} TU_cds_out_fpga_parallel_bus_read_data_1;

typedef struct {
    UInt16  test_reg;
    TU_cds_out_fpga_parallel_bus_read_data_1    data_1;
    UInt16  data_2_all_0;
    UInt16  data_3_all_0;
} T_cds_out_fpga_paralle_bus_read_data;

#ifdef __cplusplus
  }
#endif

#endif // end XP_CDS_OUT_H_
