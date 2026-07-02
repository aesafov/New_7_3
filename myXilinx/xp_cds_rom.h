#ifndef XP_CDS_ROM_H_
#define XP_CDS_ROM_H_

#include "x_basic_types.h"
#include "xp_cds_flash.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef enum {
     Cds_Rom_ProtocolType_is_Unknown = 0,
     Cds_Rom_ProtocolType_is_Seeprom,
     Cds_Rom_ProtocolType_is_SpiFlash
} T_Cds_Rom_ProtocolType;

typedef struct TS_cds_rom{
    T_cds_flash flash;

    struct T_cds_seeprom
    {
        UInt16 x;
    }seeprom;

    T_Cds_Rom_ProtocolType protocol_type;

    UInt16 device_address;
} T_cds_rom;

#ifdef __cplusplus
  }
#endif

#endif // end XP_CDS_ROM_H_
