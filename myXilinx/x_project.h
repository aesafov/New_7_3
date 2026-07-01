#ifndef X_PROJECT_H_
#define X_PROJECT_H_

#include "xp_controller.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct TS_project{
    T_controller        controller;
//    T_adc               adc[C_adc_number];
//    T_cds_tk            cds_tk[C_cds_tk_number];
//    T_cds_in            cds_in[C_cds_in_number];
//    T_cds_out           cds_out[C_cds_out_number];
//    T_hwp_soft          hwp[C_hwp_number];
//    T_omega             omega[C_omega_number];
//    T_dispatcher        dispatcher;
//
//    T_project_soft_info soft_info;

} T_project;

union TU_project_useit_part0 {
    UInt16 all;
    struct {
        UInt16 tk0          : 1;
        UInt16 tk1          : 1;
        UInt16 tk2          : 1;
        UInt16 tk3          : 1;
        UInt16 tk4          : 1;
        UInt16 tk5          : 1;
        UInt16 tk6          : 1;
        UInt16 tk7          : 1;

        UInt16 in0          : 1;
        UInt16 in1          : 1;
        UInt16 in2          : 1;
        UInt16 in3          : 1;

        UInt16 out0         : 1;
        UInt16 out1         : 1;
        UInt16 out2         : 1;
        UInt16 out3         : 1;
    } plane;
};

union TU_project_useit_part1 {
    UInt16 all;
    struct {
        UInt16 adc0         : 1;
        UInt16 adc1         : 1;
        UInt16 adc2         : 1;
        UInt16 adc3         : 1;

        UInt16 hwp0         : 1;
        UInt16 hwp1         : 1;
        UInt16 hwp2         : 1;
        UInt16 hwp3         : 1;

        UInt16 dispatcher   : 1;

        UInt16 omega0       : 1;
        UInt16 omega1       : 1;
    } plane;
};

typedef struct TS_project_useit {
    UInt16 enable;
    union TU_project_useit_part0 part0;
    union TU_project_useit_part1 part1;
} T_project_useit;

//------------------------------------------------------------------------------
// Prototypes for the functions
//------------------------------------------------------------------------------
void project_clear();

#ifdef __cplusplus
  }
#endif

#endif // end X_PROJECT_H_
