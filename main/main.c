
/********************************************************************
* User’s source file
********************************************************************/


#include "DSP281x_Device.h"
#include "DSP281x_Examples.h"   // DSP281x Examples Include File
#include "DSP281x_SWPrioritizedIsrLevels.h"   // DSP281x Examples Include File

#include "big_dsp_module.h"
#include "main_app.h"

//#include "cntrl_adr.h"
//#include "RS485.h"



//#include "bios_dsp.h"
//#include "flash_tools.h"


//#include "spise2p.h"
//#include "ADC.h"
//#include "tkak.h"
//#include "dig_io.h"


//#include "vector_20180.h"

//#include "watchdog.h"   // WatchDog Include File
//#include "manch.h"   
//#include "store_flash.h"

//#include "lamp_door.h"
//#include "can_20180.h"
//#include "can_21300.h"
//#include "can_setup_21300.h"

//#include "params.h"
//#include "message_modbus.h"
//#include "test_pwm.h"
/*
#include "xset_active_project.h"
#include "xinit.h"
#include "xtools.h"
#include "xerror.h"

#include "xproject21300.h"
#include "xproject21300_speed_sensor.h"
#include "xproject21300_tk_plane.h"
#include "xproject21300_in_plane.h"
#include "xproject21300_out_plane.h"
#include "xtools.h"
#include "RS485.h"
#include "modbus_can.h"
#include <stdio.h>
#include <string.h>
#include "update_lamp.h"
#include "flags_status.h"
#include "setup_digio.h"
#include "v_rotor.h"
#include "v_error.h"
#include "update_modbus_table.h"
#include "test_ukss.h"
#include "v_decr_mzz.h"
#include "update_from_svu_manch.h"

//#include "tools_dac.h"

#include "logs_temper.h"
#include "log_to_mem_v2.h"

#include "temperature_ain.h"

#include "super_can.h"
#include "can_message2test.h"

#include "err_slow_logs.h"




//int cntr_addr_c=CNTRL_ADDR_SECOND;

//extern volatile struct GPIO_MUX_REGS GpioMuxRegs;
//extern volatile struct GPIO_DATA_REGS GpioDataRegs;

*/


/*#pragma DATA_SECTION(prev_reset,".myvars");
char prev_reset[0x0f];
*/











//#pragma CODE_SECTION(main,".fast_run");
void main()
{
// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the DSP281x_SysCtrl.c file.


   InitSysCtrl();

   xintf_zone0_timing();
   xintf_zone6and7_timing();
   xintf_zone2_timing();




// Step 2. Initalize GPIO: 
// This example function is found in the DSP281x_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
// InitGpio();  // Skipped for this example
 
// For this example use the following configuration:
  
   
//   Gpio_select();	  



// Step 3. Clear all interrupts and initialize PIE vector table:
// Disable CPU interrupts 
   DINT;

// Initialize PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags
// are cleared.  
// This function is found in the DSP281x_PieCtrl.c file.

   InitPieCtrl();



// Disable CPU interrupts and clear all CPU interrupt flags:
   IER = 0x0000;
   IFR = 0x0000;

// Initialize the PIE vector table with pointers to the shell Interrupt 
// Service Routines (ISR).  
// This will populate the entire table, even if the interrupt
// is not used in this example.  This is useful for debug purposes.
// The shell ISR routines are found in DSP281x_DefaultIsr.c.
// This function is found in DSP281x_PieVect.c.

   InitPieVectTable();

	
// Step 4. Initialize all the Device Peripherals:
// This function is found in DSP281x_InitPeripherals.c
// InitPeripherals(); // Not required for this example


///////////////////////////////////////////////////////////
 

   initialization_app_before_load_xilinx();
   //***   initialization_app_load_xilinx();
   //***   initialization_app_after_load_xilinx();

   //***   initialization_app_before_init_all_interrupts();
   //***   initialization_app_interrupts();

   //***   EnableInterrupts();
    
   //***   ERTM;          // Enable Global realtime interrupt DBGM


   //***   initialization_app_after_init_all_interrupts();


   //***   initialization_app_before_main_while();



   	while (1)
   	{




   	 //***	   run_app_main_while();

   	 //***	   run_rs_bios_main_while();

	}

   

}


