#ifndef XP_CDS_TK_H_
#define XP_CDS_TK_H_

#include "x_basic_types.h"
#include "xp_cds_tk_fpga.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct {
    UInt16 last_error_id;
} T_cds_tk_soft;

typedef struct TS_cds_tk{
    T_cds_tk_fpga   fpga;
    T_cds_cpld      cpld;
    T_cds_rom       rom;

    //  UInt16              plane_address; // 0 to 15
    UInt16              useit;
    T_component_status  status;
    T_cds_tk_soft       soft;
} T_cds_tk;

//------------------------------------------------------------------------------
// Prototypes for the functions
//------------------------------------------------------------------------------

#ifdef __cplusplus
  }
#endif

#endif // end XP_CDS_TK_H_
