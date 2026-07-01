
#ifndef XP_CDS_SP6_CPLD_SERIAL_BUS_H_
#define XP_CDS_SP6_CPLD_SERIAL_BUS_H_

#include "x_basic_types.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef union TU_Cds_Cpld_Serial_bus_simple_Packet{
    UInt16 all;
    struct
    {
        UInt16 data    : 2;
        UInt16 rnw     : 1;
        UInt16 address : 4;
        UInt16 device  : 4;
        UInt16 rezerv  : 5;
    }field;
}T_Cds_Cpld_Serial_bus_simple_Packet;

typedef struct TS_Cds_Cpld_Serial_bus_simple    {
    UInt16 access_is_busy;
    UInt16 access_errors;
    UInt16 errors;
    UInt16 ready;
    T_Cds_Cpld_Serial_bus_simple_Packet packet_write;
    T_Cds_Cpld_Serial_bus_simple_Packet packet_read;
} T_Cds_Cpld_Serial_bus_simple;

#ifdef __cplusplus
  }
#endif

#endif // end XP_CDS_SP6_CPLD_SERIAL_BUS_H_
