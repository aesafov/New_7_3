#ifndef XP_CDS_FPGA_COMMON_H_
#define XP_CDS_FPGA_COMMON_H_

#include "x_basic_types.h"
#include "x_access_uni.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct {
    UInt16              chip_type;
    UInt16              chip_version;
    UInt16              chip_build;
    T_PlaneType         plane_type;
    T_ProjectType       project_type;
    T_FpgaFamilyType    fpga_family_type;
    UInt16              wrapper_build;
    UInt16              hash;
} T_cds_fpga_common_config_internal;

typedef struct {
    T_cds_fpga_common_config_internal   config_internal;
    UInt16                              test_reg;
    TU_cds_fpga_common_errors_status    errors_status;
    TU_cds_fpga_common_errors           errors_latch;
    TU_cds_fpga_common_internal_status  internal_status;
} T_cds_fpga_common_read;

typedef union {
    UInt16 all;
    struct {
        UInt16  int_power       : 1;
        UInt16  int_switch      : 1;
        UInt16  ext_hwp_0       : 1;
        UInt16  ext_hwp_1       : 1;
        UInt16  ext_er0         : 1;
        UInt16  unused          :11;
    } bit;
} TU_cds_fpga_common_errors;

typedef union {
    UInt16 all;
    struct {
        UInt16  int_error   : 1;
        UInt16  ext_error   : 1;
        UInt16  unused      :14;
    } bit;
} TU_cds_fpga_common_mask_for_er0;

typedef struct {
    UInt16                              test_reg;
    UInt16                              plane_index;
    TU_cds_fpga_common_errors           mask_for_errors;
    TU_cds_fpga_common_mask_for_er0     mask_for_er0;
    UInt16                              make_error_internal_bit;    // 0 to 1
    UInt16                              log0_trigger_event_sorce;   // sorce is clk_en(index); 0 to 15
} T_cds_fpga_common_write;

typedef struct {
    UInt16                  store_access_count;
    UInt16                  store_mask_for_errors;
    UInt16                  store_mask_for_er0;
    UInt16                  was_reset;
    //  T_component_status      status;
} T_cds_fpga_common_info;

typedef struct {
    T_access_uni_info       access_uni_info;
    T_cds_fpga_common_read  read;
    T_cds_fpga_common_write write;
    T_cds_fpga_common_info  soft;
} T_cds_fpga_common;

//------------------------------------------------------------------------------
// Prototypes for the functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Return Type
//------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // end XP_CDS_FPGA_COMMON_H_
