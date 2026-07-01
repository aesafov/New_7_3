#ifndef XP_CDS_FPGA_PARALLEL_BUS_H_
#define XP_CDS_FPGA_PARALLEL_BUS_H_

#include "x_basic_types.h"
#include "xp_cds_tk_fpga_parallel_bus_types.h"
#include "xp_cds_in.h"
#include "xp_cds_out.h"
#include "xp_adc.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

// paralle_bus_read_data
typedef struct {
    T_cds_tk_fpga_paralle_bus_read_data     tk[4];
    T_cds_in_fpga_paralle_bus_read_data     in[3];
    T_cds_out_fpga_paralle_bus_read_data    out[3];
    T_adc_fpga_paralle_bus_read_data        adc[2];
    //  T_speed_fpga_paralle_bus_read_data      speed;
    UInt16                                  unused[8]; // 4 of speed + 4 reserve
} T_cds_paralle_bus_read_data;

typedef struct {
    UInt16  unused_0;
    UInt16  unused_1;
    UInt16  in_0;
    UInt16  in_1;
    UInt16  in_2;
    UInt16  tk_0;
    UInt16  tk_1;
    UInt16  adc_0;
    UInt16  adc_1;
    UInt16  tk_2;
    UInt16  tk_3;
    UInt16  out_0;
    UInt16  out_1;
    UInt16  out_2;
    UInt16  speed;
    UInt16 unused_15;
} T_cds_paralle_bus_read_counts;

typedef union {
    UInt16 all;
    struct {
        UInt16 timeout  : 1;
        UInt16 size     : 1;
        UInt16 crc      : 1;
        UInt16 unused   :13;
    } bit;
} TU_cds_parallel_bus_read_error_reg;

typedef struct {
    TU_cds_parallel_bus_read_error_reg  unused_0;
    TU_cds_parallel_bus_read_error_reg  unused_1;
    TU_cds_parallel_bus_read_error_reg  in_0;
    TU_cds_parallel_bus_read_error_reg  in_1;
    TU_cds_parallel_bus_read_error_reg  in_2;
    TU_cds_parallel_bus_read_error_reg  tk_0;
    TU_cds_parallel_bus_read_error_reg  tk_1;
    TU_cds_parallel_bus_read_error_reg  adc_0;
    TU_cds_parallel_bus_read_error_reg  adc_1;
    TU_cds_parallel_bus_read_error_reg  tk_2;
    TU_cds_parallel_bus_read_error_reg  tk_3;
    TU_cds_parallel_bus_read_error_reg  out_0;
    TU_cds_parallel_bus_read_error_reg  out_1;
    TU_cds_parallel_bus_read_error_reg  out_2;
    TU_cds_parallel_bus_read_error_reg  speed;
    TU_cds_parallel_bus_read_error_reg unused_15;
} T_cds_paralle_bus_read_errors;

typedef struct {
    T_cds_paralle_bus_read_data     data;
    T_cds_paralle_bus_read_counts   packet_received_counts;
    T_cds_paralle_bus_read_counts   error_counts;
    T_cds_paralle_bus_read_errors   errors;
} T_cds_paralle_bus_read_all;

typedef struct  {
    T_cds_paralle_bus_read_all*     pread;
    UInt16                          enable; // 1 => yes, 0 => no
    UInt16                          ready;
} T_cds_fpga_parallel_bus;

#ifdef __cplusplus
  }
#endif

#endif // end XP_CDS_FPGA_PARALLEL_BUS_H_
