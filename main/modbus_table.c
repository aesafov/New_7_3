#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

#include "big_dsp_module.h"
#include "modbus_table.h"
#include "modbus_table.h"

#pragma DATA_SECTION(options_controller,".logs");
MODBUS_REG options_controller[SIZE_OPTIONS_TABLE];
