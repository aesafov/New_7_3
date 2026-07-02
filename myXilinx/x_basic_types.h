#ifndef X_BASIC_TYPES_H_
#define X_BASIC_TYPES_H_

#include "x_parameters.h"

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

#ifdef C_SystemC_Simulation
typedef signed char         Int8;
typedef signed short        Int16;
typedef signed int          Int32;
typedef signed long long    Int64;

typedef unsigned char       UInt8;
typedef unsigned short      UInt16;
typedef unsigned int        UInt32;
typedef unsigned long long  UInt64;
#endif

#ifdef C_Tms_28xx
typedef signed char         Int8;
typedef signed int          Int16;
typedef signed long         Int32;
typedef signed long long    Int64;

typedef unsigned char       UInt8;
typedef unsigned int        UInt16;
typedef unsigned long       UInt32;
typedef unsigned long long  UInt64;

#ifndef real
typedef float real;
#endif

#endif

typedef enum {
    component_NotReady  = 0,
    component_Ready     = 0x1111,
    component_Started   = 0x2222
} T_component_status;

typedef enum {
   status_Success = 0,
   status_Failed  = 1
} T_status_ReturnType;

typedef UInt16 T_Status;

#endif // end X_BASIC_TYPES_H_
