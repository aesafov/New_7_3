#include "DSP281x_Device.h"
#include "DSP281x_Examples.h"   // DSP281x Examples Include File
#include "DSP281x_SWPrioritizedIsrLevels.h"   // DSP281x Examples Include File

#include "main_app.h"
#include "cntrl_adr.h"
#include "modbus_table.h"

#include "x_basic_types.h"
#include "x_project.h"

#define CNTRL_ADDR_FIRST 0x5
#define CNTRL_ADDR_SECOND 0x6
#define CNTRL_ADDR_FOR_ALL_DEF 0x4

void initialization_app_before_load_xilinx()
{
   KickDog();
   init_flash();

   setup_leds_line();
   setup_adr_pcb_controller();

   init_cntr_addr_c();

   set_cntrl_addr(cntr_addr_c, cntr_addr_c_all);    /*  ”становка адреса контроллера    */

   init_vars_alg();
   KickDog();
//   disable_interrupt_pwm();
}

int init_cntr_addr_c(void)
{

    cntr_addr_c = 0;//options_controller[0].all;

    if (cntr_addr_c==0 || cntr_addr_c==0xff  || cntr_addr_c>20)
    {
      if (get_adr_pcb_controller()==0)
      {
          cntr_addr_c = CNTRL_ADDR_FIRST;
      }
      if (get_adr_pcb_controller()==1)
      {
          cntr_addr_c = CNTRL_ADDR_SECOND;
      }
    }

    cntr_addr_c_all = options_controller[1].all;

    if (cntr_addr_c_all==0 || cntr_addr_c_all==0xff)
      cntr_addr_c_all = CNTRL_ADDR_FOR_ALL_DEF;

    return cntr_addr_c;
}

void init_vars_alg()
{

}

void initialization_app_load_xilinx()
{
    T_Status result;
    T_project_useit useit;
/*------------------------------------------
        initiate project
--------------------------------------------*/

    // init result to Success
    result = status_Success;

    // clear object project
    project_clear();
//    project.soft_info.debug.estop0_useit = 1;
//
//
//    // init
//    if (result == status_Success)
//    {
//    //  useit.part0.all = 0;
//    //  useit.part1.all = 0;
//        useit.enable = 0;
//        result = project_init(useit);
//    }
//
//    // start
//    if (result == status_Success)
//    {
//        result = project_start();
//    }
//    else
//    {
//            X_ASSERT_ALWAYS_V3(result, "project was not init!")
//            X_ASSERT_ESTOP0(1)
//    }
}
