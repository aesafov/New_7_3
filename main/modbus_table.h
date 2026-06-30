#ifndef MODBUS_TABLE_H_
#define MODBUS_TABLE_H_

#include "modbus_reg.h"

#ifdef __cplusplus
  extern "C" {
#endif

#define SIZE_OPTIONS_TABLE 200

extern MODBUS_REG options_controller[SIZE_OPTIONS_TABLE];

#ifdef __cplusplus
  }
#endif

#endif // end MODBUS_TABLE_H_
