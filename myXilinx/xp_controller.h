#ifndef XP_CONTROLLER_H_
#define XP_CONTROLLER_H_

#include "xp_controller_fpga.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct TS_controller
{
    T_controller_fpga   fpga;
//    T_controller_cpld   cpld;
//    T_component_status  status;
} T_controller;

#ifdef __cplusplus
  }
#endif

#endif // end XP_CONTROLLER_H_
