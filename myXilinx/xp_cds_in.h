#ifndef XP_CDS_IN_H_
#define XP_CDS_IN_H_

#include "x_basic_types.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef union {
    UInt16 all;
    struct{
        UInt16 din0     : 1;
        UInt16 din1     : 1;
        UInt16 din2     : 1;
        UInt16 din3     : 1;
        UInt16 din4     : 1;
        UInt16 din5     : 1;
        UInt16 din6     : 1;
        UInt16 din7     : 1;
        UInt16 din8     : 1;
        UInt16 din9     : 1;
        UInt16 din10    : 1;
        UInt16 din11    : 1;
        UInt16 din12    : 1;
        UInt16 din13    : 1;
        UInt16 din14    : 1;
        UInt16 din15    : 1;
    }bit;
} TU_cds_in_fpga_din_reg;

// paralle_bus_read_data
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
        UInt16 mode_is_real         : 1;
        UInt16 unused_all_0         : 8;
    }bit;
} TU_cds_in_fpga_parallel_bus_read_data_1;

typedef struct {
    UInt16  test_reg;
    TU_cds_in_fpga_parallel_bus_read_data_1 data_1;
    TU_cds_in_fpga_din_reg                  din_line_status;
    UInt16  data_3_all_0;
} T_cds_in_fpga_paralle_bus_read_data;

#ifdef __cplusplus
  }
#endif

#endif // end XP_CDS_IN_H_
