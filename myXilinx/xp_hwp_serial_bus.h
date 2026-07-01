#ifndef XP_HWP_SERIAL_BUS_H_
#define XP_HWP_SERIAL_BUS_H_

#include "x_basic_types.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

struct XSerialBusSimple_ControlRd_bit {
    unsigned int tr_ready:1; // 0
    unsigned int rec_ready:1;
    unsigned int rec_error:1;
    unsigned int timeout_error:1;
    unsigned int rec_per_error:1; // error of receiving  in slave
};

typedef volatile union  {
    unsigned int        all;
    struct XSerialBusSimple_ControlRd_bit  bit;
}XSerialBusSimple_ControlRd_reg;

struct XSerialBusSimple_ControlWr_bit {
    unsigned int res_rec:1; // 0
    unsigned int case_bypass:1;
};

union XSerialBusSimple_ControlWr_reg {
   unsigned int        all;
   struct XSerialBusSimple_ControlWr_bit  bit;
};

struct XSerialBusSimple_Config1_bit {     // bits  description
    unsigned int UseConfig_n:1;      //0
    unsigned int RangeData:4;
    unsigned int Frequency:7;
    unsigned int UseCorrectionOut:1;
    unsigned int UseCorrectionIn:1;
    unsigned int SyncRdWrLine:1;
    unsigned int UsePaddingZero:1;
};

union XSerialBusSimple_Config1_reg {
   unsigned int                all;
   struct XSerialBusSimple_Config1_bit   bit;
};

struct XSerialBusSimple_Config2_bit {     // bits  description
    unsigned int Period_TrRec:8;      //0
    unsigned int UseTimer_TrRec:1;
    unsigned int UseTimer_Response:1;
    unsigned int RangeTimer_Response:5;
};

union XSerialBusSimple_Config2_reg {
   unsigned int                all;
   struct XSerialBusSimple_Config2_bit   bit;
};

struct XSerialBusSimple_CorrectSignal_bit {
    unsigned int value:15; // 0-14
    unsigned int make_this_level_more_on_value:1;
};

union XSerialBusSimple_CorrectSignal_reg {
   unsigned int        all;
   struct XSerialBusSimple_CorrectSignal_bit  bit;
};

typedef struct {
   unsigned int mask_er_ack;
   unsigned int mask_data;
}XSerialBusSimple_Masks;

typedef struct {
    //  unsigned int TypeAccess;
    //  unsigned int AdrPlane;
    unsigned int BaseAddress;      /* Base address of registers */
    unsigned int IsReady:1;        /* Device is initialized and ready */
    unsigned int DataWr;
    unsigned int DataRd;
    XSerialBusSimple_ControlRd_reg              Control_Rd;
    union XSerialBusSimple_ControlWr_reg        Control_Wr;
    union XSerialBusSimple_Config1_reg          Config1;
    union XSerialBusSimple_Config2_reg          Config2;
    union XSerialBusSimple_CorrectSignal_reg    Correct_Tr;
    union XSerialBusSimple_CorrectSignal_reg    Correct_Rec;
    XSerialBusSimple_Masks  Masks;
    UInt16          current_plane_index;
} T_hwp_serial_bus;


#ifdef __cplusplus
  }
#endif

#endif // end XP_HWP_SERIAL_BUS_H_
