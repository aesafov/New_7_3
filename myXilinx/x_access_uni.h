#ifndef X_ACCESS_UNI_H_
#define X_ACCESS_UNI_H_

#include "x_basic_types.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct {
    unsigned int TypeAccess;
    unsigned int AdrPlane;
    unsigned int AdrReg;
    unsigned int DataWr;
    unsigned int DataRd;
} Xmemory_uni;

#ifdef __cplusplus
  }
#endif

#endif // end X_ACCESS_UNI_H_
