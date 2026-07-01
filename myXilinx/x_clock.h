#ifndef X_CLOCK_H_
#define X_CLOCK_H_

#include "x_basic_types.h"
#include "x_timer.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct {
    XTimer  timer;
    UInt16  access_count;
} T_controller_fpga_clock;

#ifdef __cplusplus
  }
#endif

#endif // end X_CLOCK_H_
