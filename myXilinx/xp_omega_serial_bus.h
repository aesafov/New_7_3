#ifndef XP_OMEGA_SERIAL_BUS_H_
#define XP_OMEGA_SERIAL_BUS_H_

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct  {
    UInt16          ready;
    UInt16          access_is_busy;
    UInt16          access_errors;
    UInt16          errors;
    UInt16          current_plane_index;
} T_omega_serial_bus;

#ifdef __cplusplus
  }
#endif

#endif // end XP_OMEGA_SERIAL_BUS_H_
