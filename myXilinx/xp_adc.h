#ifndef XP_ADC_H_
#define XP_ADC_H_

#include "x_basic_types.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

// paralle_bus_read_data
typedef struct {
    Int16   acc_short[16];
} T_adc_fpga_paralle_bus_read_data;

#ifdef __cplusplus
  }
#endif

#endif // end XP_ADC_H_
