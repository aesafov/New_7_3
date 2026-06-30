#include "DSP281x_Device.h"
#include "DSP281x_Examples.h"   // DSP281x Examples Include File
#include "DSP281x_SWPrioritizedIsrLevels.h"   // DSP281x Examples Include File


void initialization_app_before_load_xilinx()
{
   KickDog();
   init_flash();

   setup_leds_line();
   setup_adr_pcb_controller();
//
//   init_cntr_addr_c();
//
//   set_cntrl_addr(cntr_addr_c, cntr_addr_c_all);    /*  ”становка адреса контроллера    */
//
//   init_vars_alg();
   KickDog();
//   disable_interrupt_pwm();

}

