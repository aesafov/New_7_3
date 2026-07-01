#ifndef XP_CDS_FPGA_SERIAL_BUS_H_
#define XP_CDS_FPGA_SERIAL_BUS_H_

#include "x_basic_types.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct  {
    UInt16                              ready;
    UInt16                              access_is_busy;
    UInt16                              access_errors;
    UInt16                              errors;
} T_cds_fpga_serial_bus;


#ifdef __cplusplus
  }
#endif

#endif // end XP_CDS_FPGA_SERIAL_BUS_H_
