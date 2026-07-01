#ifndef XP_CONTROLLER_FPGA_H_
#define XP_CONTROLLER_FPGA_H_

#include "x_basic_types.h"
#include "xp_hwp_serial_bus.h"
#include "xp_omega_serial_bus.h"
#include "xp_cds_sp6_cpld_serial_bus.h"
#include "xp_cds_fpga_serial_bus.h"
#include "xp_cds_fpga_parallel_bus.h"
#include "x_timer.h"
#include "x_clock.h"
#include "x_intc.h"
#include "x_input_new.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------


typedef struct TS_controller_fpga_config {
  union {
      UInt16 all;
      struct {
          UInt16 Use_Config_n     : 1;
          UInt16 Type_Of_Plane    : 4;
          UInt16 Type_Of_Project  : 6;
          UInt16 Version_Of_Sheet : 5;
      }field;
  } reg0;

  union {
      UInt16 all;
      struct {
          UInt16 Revision_of_Version  : 4;
          UInt16 unused               :12;
      }field;
  } reg1;

  union {
      UInt16 all;
      struct {
          UInt16 Year     : 7;
          UInt16 Month    : 4;
          UInt16 Day      : 5;
      }field;
  } date_of_generation;

} T_controller_fpga_config;

typedef struct TS_Controller_Fpga_ControlReg0
{
    union
    {
        UInt16 all;
        struct {
/*
            TE_controller_fpga_control_regs0_oe_buf         oe_buf_reg                  : 1;
            TE_controller_fpga_control_regs0_sres           sres_reg                    : 1;
            TE_controller_fpga_control_regs0_int            int_for_XNMI_XINT13_reg     : 1;
            TE_controller_fpga_control_regs0_z_er0_out      line_Z_ER0_OUT_Is           : 1;
            TE_controller_fpga_control_regs0_set_mode       line_SET_MODE_Is            : 1;
            TE_controller_fpga_control_regs0_er0_out_sorce  line_ER0_OUT_Sorce_Is       : 1;
            TE_controller_fpga_control_regs0_er0            line_ER0_OUT_Is             : 1;
            TE_controller_fpga_control_regs0_clks_sorce     line_CLKS_Sorce_Is          : 1;
            TE_controller_fpga_control_regs0_clks           line_CLKS_Is                : 1;
            TE_controller_fpga_control_regs0_p7_4_sorce     line_P7_4_Sorce_Is          : 1;
            UInt16                                          line_P7_4_Is                : 4;    // 4 bits
            UInt16 unused                                                               : 2;    // write has no effect
*/
            UInt16          oe_buf_reg                  : 1;
            UInt16          sres_reg                    : 1;
            UInt16          int_for_XNMI_XINT13_reg     : 1;
            UInt16          line_Z_ER0_OUT_Is           : 1;
            UInt16          line_SET_MODE_Is            : 1;
            UInt16          line_ER0_OUT_Sorce_Is       : 1;
            UInt16          line_ER0_OUT_Is             : 1;
            UInt16          line_CLKS_Sorce_Is          : 1;
            UInt16          line_CLKS_Is                : 1;
            UInt16          line_P7_4_Sorce_Is          : 1;
            UInt16          line_P7_4_Is                : 4;    // 4 bits
            UInt16          unused                      : 2;    // write has no effect

        } bit;
    } write;
    union
    {
        UInt16 all;
        struct {
/*
            TE_controller_fpga_control_regs0_oe_buf         oe_buf_reg                  : 1;
            TE_controller_fpga_control_regs0_sres           sres_reg                    : 1;
            TE_controller_fpga_control_regs0_int            int_for_XNMI_XINT13_reg     : 1;
            TE_controller_fpga_control_regs0_z_er0_out      line_Z_ER0_OUT_Is           : 1;
            TE_controller_fpga_control_regs0_set_mode       line_SET_MODE_Is            : 1;
            TE_controller_fpga_control_regs0_er0_out_sorce  line_ER0_OUT_Sorce_Is       : 1;
            TE_controller_fpga_control_regs0_er0            line_ER0_OUT_Is             : 1;
            TE_controller_fpga_control_regs0_clks_sorce     line_CLKS_Sorce_Is          : 1;
            TE_controller_fpga_control_regs0_clks           line_CLKS_Is                : 1;
            TE_controller_fpga_control_regs0_p7_4_sorce     line_P7_4_Sorce_Is          : 1;
            UInt16                                          line_P7_4_Is                : 4;    // 4 bits
            TE_controller_fpga_control_regs0_er0            line_ER0_IN_Is              : 1;
            TE_controller_fpga_control_regs0_case_xilinx    line_CASE_XILINX_is         : 1;
*/
            UInt16          oe_buf_reg                  : 1;
            UInt16          sres_reg                    : 1;
            UInt16          int_for_XNMI_XINT13_reg     : 1;
            UInt16          line_Z_ER0_OUT_Is           : 1;
            UInt16          line_SET_MODE_Is            : 1;
            UInt16          line_ER0_OUT_Sorce_Is       : 1;
            UInt16          line_ER0_OUT_Is             : 1;
            UInt16          line_CLKS_Sorce_Is          : 1;
            UInt16          line_CLKS_Is                : 1;
            UInt16          line_P7_4_Sorce_Is          : 1;
            UInt16          line_P7_4_Is                : 4;    // 4 bits
            UInt16          line_ER0_IN_Is              : 1;
            UInt16          line_CASE_XILINX_is         : 1;

        } bit;
    } read;
} T_Controller_Fpga_ControlReg0;

typedef struct TS_Controller_Fpga_ControlReg1
{
    union
    {
        UInt16 all;
        struct {
            UInt16 line_spi_sck_out     :  1;
            UInt16 line_spi_mosi_out    :  1;
            UInt16 unused               : 14;
        }bit;
    } write;
    union
    {
        UInt16 all;
        struct
        {
            UInt16 line_spi_miso_in :  1;
            UInt16 unused           : 15;
        }bit;
    } read;
}T_Controller_Fpga_ControlReg1;


typedef struct TS_Controller_Fpga_ControlReg2
{
    union
    {
        UInt16 all;
        struct {
            UInt16 line_uloop3_out  :  1;
            UInt16 unused           : 15;
        }bit;
    } write;
    union
    {
        UInt16 all;
        struct
        {
            UInt16 line_uloop2_in   :  1;
            UInt16 unused           : 15;
        }bit;
    } read;
} T_Controller_Fpga_ControlReg2;

typedef union {
    UInt16 all;
    struct {
        UInt16 er0_in       : 1;
        UInt16 hwp_0_n      : 1;
        UInt16 hwp_1_n      : 1;
        UInt16 unused       :13;
    } bit;
} TU_controller_fpga_error_external_line_status_reg;

typedef union {
    UInt16 all;
    struct {
        UInt16 er0_in       : 1;
        UInt16 hwp_0        : 1;
        UInt16 hwp_1        : 1;
        UInt16 unused       :13;
    } bit;
} TU_controller_fpga_error_external_latch_reg;

typedef union {
    UInt16 all;
    struct {
        UInt16 er0_in       : 1;
        UInt16 hwp_0        : 1;
        UInt16 hwp_1        : 1;
        UInt16 unused       :13;
    } bit;
} TU_controller_fpga_error_external_mask_reg;

typedef struct {
    struct {
        TU_controller_fpga_error_external_mask_reg          mask;       // '1' -> masking
        TU_controller_fpga_error_external_line_status_reg   line_status;
        TU_controller_fpga_error_external_latch_reg         latch;      // '1' -> error
    } read;

    struct {
        TU_controller_fpga_error_external_mask_reg          mask;       // '1' -> masking
        UInt16                                              reset;      // '1' -> reset error_latch
    } write;

} T_controller_fpga_error_external;

typedef union {
    UInt16 all;
    struct {
        UInt16 miso     : 1;
        UInt16 mosi     : 1;
        UInt16 error    : 1;
        UInt16 unused   :13;
    } bit;
} TU_controller_fpga_hwp_plane_select_lines;

typedef struct TS_controller_fpga
{
    T_controller_fpga_config                    config;
    T_Controller_Fpga_ControlReg0               control_reg0;
    T_Controller_Fpga_ControlReg1               control_reg1;
    T_Controller_Fpga_ControlReg2               control_reg2;
    T_controller_fpga_error_external            error_external;
    TU_controller_fpga_hwp_plane_select_lines   hwp_plane_select_lines;
    T_hwp_serial_bus                            hwp_serial_bus;
    T_omega_serial_bus                          omega_serial_bus;
    T_Cds_Cpld_Serial_bus_simple                cds_cpld_bus;
    T_cds_fpga_serial_bus                       cds_fpga_serial_bus;
    T_cds_fpga_parallel_bus                     cds_fpga_parallel_bus;
    XTimer                                      timer_0;
    XTimer                                      timer_1;
    XTimer                                      timer_2;
    XTimer                                      timer_3;
    T_controller_fpga_clock                     clock;
    XIntc                                       intc;
//  Xinput_new_uni                              input_new_uni_0;
    Xinput_new_uni                              input_new_uni_1;
    XSpeed_Sensor*                              pspeed_sensor; // use pointer for allocate object in section fast_vars
//    XKey_all                                    key_all;

    UInt16                                      was_reset;
//    T_component_status                          status;
//    T_controller_fpga_info                      info;

} T_controller_fpga;

#ifdef __cplusplus
  }
#endif

#endif // end XP_CONTROLLER_FPGA_H_
