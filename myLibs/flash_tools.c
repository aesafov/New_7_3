#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File
#include "flash_tools.h"
#include "big_dsp_module.h"

void init_flash()
{
   setup_oper_line();

   select_strob_67_for_flash();

   xintf_zone6and7_timing();
   select_work_with_flash();
}
