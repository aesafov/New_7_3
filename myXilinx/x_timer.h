#ifndef X_TIMER_H_
#define X_TIMER_H_

#include "x_basic_types.h"
#include "x_access_uni.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

union XTimer_CSR_reg {
    unsigned int  all;
    struct {
        unsigned int Timer_Is_Enable:1;
        unsigned int Count_Is_Load:1;
        unsigned int Count_Is_Up:1;
        unsigned int Count_Is_AutoReload:1;
        unsigned int Count_Is_Capture:1;
        unsigned int Int_Is_Enable:1;
        unsigned int Int_Is_Occur:1;
    } bit;
};

union XTimer_Load_reg {
    unsigned long  all;
    struct {
        unsigned int Low;
        unsigned int High;
    } bit;
};

union XTimer_Config_reg {
    unsigned int  all;
    struct {
        unsigned int Use_Config:1;
        unsigned int RangeCount_Is:6;
        unsigned int Use_sync_rd_wr:1;
        unsigned int Use_padding:1;
        unsigned int Version_of_Timer:4;
    } bit;
};

typedef struct {
    Xmemory_uni                 Xmemory_uni0;
    unsigned int                BaseAddress;
    unsigned int                IsReady;
    union XTimer_CSR_reg        CSR;
    union XTimer_Load_reg       Load;
    union XTimer_Config_reg Config;
} XTimer;

#ifdef __cplusplus
  }
#endif

#endif // end X_TIMER_H_
