#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

#include "big_dsp_module.h"
//#include "setpcb.h"
//#include "flash_tools.h"
//#include "x_tools.h"


void setup_oper_line()
{
    EALLOW;

	GpioMuxRegs.GPAMUX.bit.C1TRIP_GPIOA13=0;
	GpioMuxRegs.GPAMUX.bit.C2TRIP_GPIOA14=0;
	GpioMuxRegs.GPAMUX.bit.C3TRIP_GPIOA15=0;
	GpioMuxRegs.GPBMUX.bit.C4TRIP_GPIOB13=0;
	GpioMuxRegs.GPBMUX.bit.C6TRIP_GPIOB15=0;

	GpioMuxRegs.GPADIR.bit.GPIOA13=1;
	GpioMuxRegs.GPADIR.bit.GPIOA14=1;
	GpioMuxRegs.GPADIR.bit.GPIOA15=1;
	GpioMuxRegs.GPBDIR.bit.GPIOB13=1;
	GpioMuxRegs.GPBDIR.bit.GPIOB15=1;

    GpioMuxRegs.GPAQUAL.all=0;
    GpioMuxRegs.GPBQUAL.all=0;
    EDIS;

    write_oper(1,1,1,1);
}

void setup_leds_line()
{
    EALLOW;

	GpioMuxRegs.GPDMUX.bit.T4CTRIP_SOCB_GPIOD6=0;
	GpioMuxRegs.GPDMUX.bit.T3CTRIP_PDPB_GPIOD5=0;

	GpioMuxRegs.GPDDIR.bit.GPIOD6=1;
	GpioMuxRegs.GPDDIR.bit.GPIOD5=1;

    EDIS;
}




void write_oper(unsigned char oper_mode1,unsigned char oper_mode2, unsigned char oper_mode3, unsigned char oper_mode4)
{
     EALLOW;
     GpioDataRegs.GPADAT.bit.GPIOA13=oper_mode1; // pin 122 -> net OPER_MOD1 -> pin 28 XC95144
     GpioDataRegs.GPADAT.bit.GPIOA14=oper_mode2; // pin 123 -> net OPER_MOD2 -> pin 55 XC95144
     GpioDataRegs.GPADAT.bit.GPIOA15=oper_mode3; // pin 124 -> net OPER_MOD3 -> pin 29 XC95144
     GpioDataRegs.GPBDAT.bit.GPIOB13=oper_mode4; // pin 61  -> net OPER_MOD4 -> pin 97 XC95144

     asm(" NOP");
     GpioDataRegs.GPBDAT.bit.GPIOB15=0; // pin 63 -> net WR_OPER -> pin 96 XC95144
     asm(" NOP");
     asm(" NOP");
     asm(" NOP");
     GpioDataRegs.GPBDAT.bit.GPIOB15=1; // pin 63 -> net WR_OPER -> pin 96 XC95144
     asm(" NOP");
     asm(" NOP");
     asm(" NOP");
     GpioDataRegs.GPBDAT.bit.GPIOB15=0; // pin 63 -> net WR_OPER -> pin 96 XC95144
     asm(" NOP");
     asm(" NOP");
     asm(" NOP");

//     GpioDataRegs.GPADAT.bit.GPIOA13=1;
//     GpioDataRegs.GPADAT.bit.GPIOA14=1;
//     GpioDataRegs.GPADAT.bit.GPIOA15=1;
//     GpioDataRegs.GPBDAT.bit.GPIOB13=1;
     EDIS;
}

void xintf_zone6and7_timing(void)
{

    // All Zones---------------------------------
    // Timing for all zones based on XTIMCLK = SYSCLKOUT/2
    XintfRegs.XINTCNF2.bit.XTIMCLK = 1;
    // Buffer up to 0 writes
    XintfRegs.XINTCNF2.bit.WRBUFF = 0;
    // XCLKOUT is enabled
    XintfRegs.XINTCNF2.bit.CLKOFF = 0;
    // XCLKOUT = XTIMCLK
    XintfRegs.XINTCNF2.bit.CLKMODE = 0;
	XintfRegs.XINTCNF2.bit.MPNMC = 0;


    // Zone 6------------------------------------
    // When using ready, ACTIVE must be 1 or greater
    // Lead must always be 1 or greater
    // Zone write timing
    XintfRegs.XTIMING6.bit.XWRLEAD = 3;
    XintfRegs.XTIMING6.bit.XWRACTIVE = 7;
    XintfRegs.XTIMING6.bit.XWRTRAIL = 6;//3;
    // Zone read timing
    XintfRegs.XTIMING6.bit.XRDLEAD = 3;
    XintfRegs.XTIMING6.bit.XRDACTIVE = 3;
    XintfRegs.XTIMING6.bit.XRDTRAIL = 3;

    // do not double all Zone read/write lead/active/trail timing
    XintfRegs.XTIMING6.bit.X2TIMING = 0;

    // Zone will not sample READY
    XintfRegs.XTIMING6.bit.USEREADY = 0;//1;
    XintfRegs.XTIMING6.bit.READYMODE = 0;//1;

    // Size must be 1,1 - other values are reserved
    XintfRegs.XTIMING6.bit.XSIZE = 3;


    // Zone 7------------------------------------
    // When using ready, ACTIVE must be 1 or greater
    // Lead must always be 1 or greater
    // Zone write timing
    XintfRegs.XTIMING7.bit.XWRLEAD = 3;
    XintfRegs.XTIMING7.bit.XWRACTIVE = 7;
    XintfRegs.XTIMING7.bit.XWRTRAIL = 6;
    // Zone read timing
    XintfRegs.XTIMING7.bit.XRDLEAD = 3;
    XintfRegs.XTIMING7.bit.XRDACTIVE = 3;
    XintfRegs.XTIMING7.bit.XRDTRAIL = 3;

    // don't double all Zone read/write lead/active/trail timing
    XintfRegs.XTIMING7.bit.X2TIMING = 0;

    // Zone will not sample XREADY signal
    XintfRegs.XTIMING7.bit.USEREADY = 0;
    XintfRegs.XTIMING7.bit.READYMODE = 0;

    // Size must be 1,1 - other values are reserved
    XintfRegs.XTIMING7.bit.XSIZE = 3;

   //Force a pipeline flush to ensure that the write to
   //the last register configured occurs before returning.
   asm(" RPT #7 || NOP");
}


void xintf_zone2_timing(void)
{

    // All Zones---------------------------------
    // Timing for all zones based on XTIMCLK = SYSCLKOUT/2
    XintfRegs.XINTCNF2.bit.XTIMCLK = 1;
    // Buffer up to 0 writes
    XintfRegs.XINTCNF2.bit.WRBUFF = 0;
    // XCLKOUT is enabled
    XintfRegs.XINTCNF2.bit.CLKOFF = 0;
    // XCLKOUT = XTIMCLK
    XintfRegs.XINTCNF2.bit.CLKMODE = 0;

	XintfRegs.XINTCNF2.bit.MPNMC = 0;


    // Zone 6------------------------------------
    // When using ready, ACTIVE must be 1 or greater
    // Lead must always be 1 or greater
    // Zone write timing
    XintfRegs.XTIMING2.bit.XWRLEAD = 2;//2;
    XintfRegs.XTIMING2.bit.XWRACTIVE = 7;//2;
    XintfRegs.XTIMING2.bit.XWRTRAIL = 2;//2;
    // Zone read timing
    XintfRegs.XTIMING2.bit.XRDLEAD = 2;//2;
    XintfRegs.XTIMING2.bit.XRDACTIVE = 1;//1;
    XintfRegs.XTIMING2.bit.XRDTRAIL = 0;//0;

    // do not double all Zone read/write lead/active/trail timing
    XintfRegs.XTIMING2.bit.X2TIMING = 0;

    // Zone will not sample READY
    XintfRegs.XTIMING2.bit.USEREADY = 0;//1;
    XintfRegs.XTIMING2.bit.READYMODE = 0;//1;

    // Size must be 1,1 - other values are reserved
    XintfRegs.XTIMING2.bit.XSIZE = 3;



   //Force a pipeline flush to ensure that the write to
   //the last register configured occurs before returning.
   asm(" RPT #7 || NOP");
}




void xintf_zone0_timing(void)
{

    // Zone 0------------------------------------
    // When using ready, ACTIVE must be 1 or greater
    // Lead must always be 1 or greater
    // Zone write timing
    XintfRegs.XTIMING0.bit.XWRLEAD = 3;//2;
    XintfRegs.XTIMING0.bit.XWRACTIVE =7;//1; // 1
    XintfRegs.XTIMING0.bit.XWRTRAIL = 3;//1;//0;
    // Zone read timing
#ifdef XLOW_FREQUENCY_MODE
    XintfRegs.XTIMING0.bit.XRDLEAD = 3;
    XintfRegs.XTIMING0.bit.XRDACTIVE = 7; // 4
    XintfRegs.XTIMING0.bit.XRDTRAIL = 3;
#else
    XintfRegs.XTIMING0.bit.XRDLEAD = 3;
    XintfRegs.XTIMING0.bit.XRDACTIVE = 7;//4;//1
    XintfRegs.XTIMING0.bit.XRDTRAIL = 3;//1;//1
#endif

    // do not double all Zone read/write lead/active/trail timing
    XintfRegs.XTIMING0.bit.X2TIMING = 0;

    // Zone will not sample READY
    XintfRegs.XTIMING0.bit.USEREADY = 0;//1;
    XintfRegs.XTIMING0.bit.READYMODE = 0;//1;

    // Size must be 1,1 - other values are reserved
    XintfRegs.XTIMING0.bit.XSIZE = 3;
 

    
   //Force a pipeline flush to ensure that the write to 
   //the last register configured occurs before returning.  
   asm(" RPT #7 || NOP"); 
}

//void xintf_zone0_timing_slow(void)
//{
//
//    // Zone 0------------------------------------
//    // When using ready, ACTIVE must be 1 or greater
//    // Lead must always be 1 or greater
//    // Zone write timing
//
//    XintfRegs.XTIMING0.bit.XWRLEAD = 1;// 1
//    XintfRegs.XTIMING0.bit.XWRACTIVE =1;// 2
//    XintfRegs.XTIMING0.bit.XWRTRAIL = 0;// 1
//    // Zone read timing
//    XintfRegs.XTIMING0.bit.XRDLEAD = 3;// 1
//    XintfRegs.XTIMING0.bit.XRDACTIVE = 7;// 2
//    XintfRegs.XTIMING0.bit.XRDTRAIL = 3;// 1
//
//    // do not double all Zone read/write lead/active/trail timing
//    XintfRegs.XTIMING0.bit.X2TIMING = 0;
//
//    // Zone will not sample READY
//    XintfRegs.XTIMING0.bit.USEREADY = 0;//1;
//    XintfRegs.XTIMING0.bit.READYMODE = 0;//1;
//
//    // Size must be 1,1 - other values are reserved
//    XintfRegs.XTIMING0.bit.XSIZE = 3;
//
//
//
//   //Force a pipeline flush to ensure that the write to
//   //the last register configured occurs before returning.
//   asm(" RPT #7 || NOP");
//}










#pragma CODE_SECTION(led1_toggle,".fast_run");
#pragma CODE_SECTION(led2_toggle,".fast_run");
#pragma CODE_SECTION(led1_on_off,".fast_run");
#pragma CODE_SECTION(led2_on_off,".fast_run");

//void led1_toggle()
//{
//     EALLOW;
//     GpioDataRegs.GPATOGGLE.bit.GPIOA10=1;
//     EDIS;
//}


//void led2_toggle()
//{
//     EALLOW;
//     GpioDataRegs.GPDTOGGLE.bit.GPIOD6=1;
//     EDIS;
//}


//void led1_on_off(int i)
//{
//     EALLOW;
//     if (i) GpioDataRegs.GPASET.bit.GPIOA10=i;
//     else   GpioDataRegs.GPACLEAR.bit.GPIOA10=1;
//     EDIS;
//}

//void led2_on_off(int i)
//{
//     EALLOW;
//     if (i) GpioDataRegs.GPDSET.bit.GPIOD6=i;
//     else   GpioDataRegs.GPDCLEAR.bit.GPIOD6=1;
//     EDIS;
//}

//void led_toggle()
//{
//     EALLOW;
////     GpioDataRegs.GPATOGGLE.bit.GPIOA0=1;
//     GpioDataRegs.GPDTOGGLE.bit.GPIOD5=1;
//     EDIS;
//}

//void unsecure()
//{
//volatile int *CSM = (volatile int *)0x000AE0; //CSM register file
//volatile int *PWL = (volatile int *)0x3F7FF8; //Password location
//volatile int tmp;
//int i ;
//
//// Read the 128-bits of the password location (PWL)
//// in Flash/ROM at address 0x3F7FF8-0x3F7FFF.
//// If the device is secure, then the values read will
//// not actually be loaded into the temp variable, so
//// this is called a dummy read.
//
//for (i = 0; i<8; i++) tmp = *PWL++;
//
//// If the password location (PWL) is all = ones (0xFFFF),
//// then the device will now be unsecure. If the password
//// is not all ones (0xFFFF), then the code below is required
//// to unsecure the CSM.
//// Write the 128-bit password to the KEY registers
//// If this password matches that stored in the
//// PWL then the CSM will become unsecure. If it does not
//// match, then the device will remain secure.
//// An example password of:
//// 0x0123456789ABCDEFCDEF89AB45670123 is used.
//
//EALLOW; // Key registers are EALLOW protected
//
//*CSM++ = 0x0; // Register KEY0 at 0xAE0
//*CSM++ = 0x0; // Register KEY1 at 0xAE1
//*CSM++ = 0x0; // Register KEY2 at 0xAE2
//*CSM++ = 0x0; // Register KEY3 at 0xAE3
//*CSM++ = 0x0; // Register KEY4 at 0xAE4
//*CSM++ = 0x0; // Register KEY5 at 0xAE5
//*CSM++ = 0x0; // Register KEY6 at 0xAE6
//*CSM++ = 0x0; // Register KEY7 at 0xAE7
//
//
//EDIS;
//
//
//}


void setup_adr_pcb_controller()
{
    EALLOW;

	GpioMuxRegs.GPBMUX.bit.TDIRB_GPIOB11=0;
	GpioMuxRegs.GPBDIR.bit.GPIOB11=1; // pin 71 -> 3.3v | GND from jumper

    EDIS;
}


//int get_adr_pcb_controller()
//{
//  return !GpioDataRegs.GPBDAT.bit.GPIOB11;
//}


