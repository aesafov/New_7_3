#ifndef MXP_CDS_TK_FPGA_H_
#define XP_CDS_TK_FPGA_H_

#include "xp_cds_fpga_common.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct {
    T_cds_fpga_common           common;
    T_cds_tk_fpga_logic         logic;
    T_component_status          status;
} T_cds_tk_fpga;

//------------------------------------------------------------------------------
// Prototypes for the functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Return Type
//------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // end XP_CDS_TK_FPGA_H_
