#ifndef X_ACCESS_UNI_H_
#define X_ACCESS_UNI_H_

#include "x_basic_types.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef enum {
    FpgaFamilyTypee_is_Unknown  = -1,
    FpgaFamilyType_is_Spartan2  = 1,
    FpgaFamilyType_is_Spartan3  = 2,
    FpgaFamilyType_is_Spartan6 = 3
} T_FpgaFamilyType;

typedef enum {
    PlaneType_is_Unknown    = -1,
    PlaneType_is_Controller = 0,
    PlaneType_is_Tk         = 1,
    PlaneType_is_In         = 2,
    PlaneType_is_Out        = 3,
    PlaneType_is_Adc        = 4,
    PlaneType_is_Ds         = 5,
    PlaneType_is_Hwp        = 6,
    PlaneType_is_Pult       = 7,
    PlaneType_is_Analog     = 8,
    PlaneType_is_TestPower  = 9,
    PlaneType_is_SpeedSensor,
    PlaneType_is_Dispatcher,
    PlaneType_is_Cds,
    PlaneType_is_Cds_sp2e,
    PlaneType_is_Cds_sp6,
    PlaneType_is_Omega
} T_PlaneType;

typedef enum {
    ProjectType_is_745          = 0,
    ProjectType_is_ComplexSet   = 1,
    ProjectType_is_21300        = 3,
    ProjectType_is_Balzam       = 4,
    ProjectType_is_745_dot2     = 5,

    ProjectType_is_22220        = C_ProjectType_is_22220,
    ProjectType_is_Balzam_2     = C_ProjectType_is_Balzam_2,
    ProjectType_is_21300_2      = C_ProjectType_is_21300_2,
    ProjectType_is_21180_2      = C_ProjectType_is_21180_2
} T_ProjectType;

typedef struct {
    unsigned int TypeAccess;
    unsigned int AdrPlane;
    unsigned int AdrReg;
    unsigned int DataWr;
    unsigned int DataRd;
} Xmemory_uni;

typedef struct {
    T_PlaneType     plane_type;
    T_DeviceType    device_type;
    T_AccessType    access_type;
    UInt16          plane_address;
} T_access_uni_info;

#ifdef __cplusplus
  }
#endif

#endif // end X_ACCESS_UNI_H_
