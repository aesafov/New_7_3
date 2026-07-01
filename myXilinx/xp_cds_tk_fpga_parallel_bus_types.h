#ifndef XP_CDS_TK_FPGA_PARALLEL_BUS_TYPES_H_
#define XP_CDS_TK_FPGA_PARALLEL_BUS_TYPES_H_

#include "x_basic_types.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct {
    // word0
    UInt16  work_key_error_time_min_latch_8_bits    : 8;
    UInt16  work_key_error_time_dead_latch_6_bits   : 6;
    UInt16  stop_key_error_time_min_latch_2_bits    : 2;
    // word1
    UInt16  error_driver_latch_8_bits               : 8;
    UInt16  error_ack_latch_8_bits                  : 8;
    // work2
    UInt16  error_i_latch_8_bits                    : 8;
    UInt16  make_error_internal                     : 1;
    UInt16  error_internal_power_latch              : 1;
    UInt16  error_internal_switch_latch             : 1;
    UInt16  error_internal_sum                      : 1;
    UInt16  error_external_er0_latch                : 1;
    UInt16  error_external_hwp0_latch               : 1;
    UInt16  error_external_hwp1_latch               : 1;
    UInt16  error_sum                               : 1;
    UInt16  to_key_status_8_bits                    : 8;
    UInt16  from_key_status_8_bits                  : 8;
} T_cds_tk_fpga_paralle_bus_read_data;
#ifdef __cplusplus
  }
#endif

#endif // end XP_CDS_TK_FPGA_PARALLEL_BUS_TYPES_H_
