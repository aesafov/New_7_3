#ifndef BIG_DSP_MODULE_H_
#define BIG_DSP_MODULE_H_

#ifdef __cplusplus
  extern "C" {  
#endif

#include "DSP281x_Device.h"
//#include "setpcb.h"
//#include "x_tools.h"

#define select_strob_67_for_flash()   	write_oper(1,0,1,0)
#define select_work_with_flash()   		write_oper(0,0,0,0)
#define select_reset28_for_load67()   	write_oper(0,0,1,0)
#define inc_count_mode_28()   			write_oper(1,1,0,0)
#define select_nothing()   				write_oper(1,1,1,1)
#define select_reset28()   				write_oper(1,1,1,0)
#define select_load_xilinx()			write_oper(0,0,0,1)
#define reset_xilinx()					write_oper(1,1,0,1)

#define set_load28_from_reset_internal_flash() \
											select_nothing(); \
											inc_count_mode_28();

#define set_load28_from_reset_sci_rs232()  \
											select_nothing(); \
                                           	inc_count_mode_28(); \
                                           	inc_count_mode_28(); \
                                           	inc_count_mode_28();

#define set_load28_from_reset_external_flash()  \
											select_nothing(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28();

#define set_load28_from_reset_ram()  \
											select_nothing();    \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28();
											 

#define set_load28_from_reset_stop()  \
											select_nothing();    \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28(); \
											inc_count_mode_28();






void led2_on_off(int i);
void led1_on_off(int i);
void led2_toggle();
void led1_toggle();
void led_toggle();



void setup_leds_line();

void xintf_zone6and7_timing(void);


void xintf_zone0_timing(void);
void xintf_zone0_timing_slow(void);
void xintf_zone2_timing(void);



void write_oper(unsigned char oper_mode1,unsigned char oper_mode2,
unsigned char oper_mode3, unsigned char oper_mode4);
void setup_oper_line();


#define N_CHANNEL_ADC0 13
#define N_CHANNEL_ADC1 14
#define N_CHANNEL_ADC2 15
#define N_CHANNEL_ADC3 12
#define N_CHANNEL_ADC4 11
#define N_CHANNEL_ADC5 8
#define N_CHANNEL_ADC6 9
#define N_CHANNEL_ADC7 10
#define N_CHANNEL_ADC8 3
#define N_CHANNEL_ADC9 1
#define N_CHANNEL_ADC10 2
#define N_CHANNEL_ADC11 0
#define N_CHANNEL_ADC12 4
#define N_CHANNEL_ADC13 5
#define N_CHANNEL_ADC14 6
#define N_CHANNEL_ADC15 7




//inline void i_led2_on_off(int i)
//{
//     EALLOW;
//
// 	 if (i) GpioDataRegs.GPDSET.bit.GPIOD6=i;
//     else   GpioDataRegs.GPDCLEAR.bit.GPIOD6=1;
//
//
//     EDIS;
//}


//inline void i_led1_on_off(int i)
//{
//     EALLOW;
//	 if (i) GpioDataRegs.GPASET.bit.GPIOA10=i;
//     else   GpioDataRegs.GPACLEAR.bit.GPIOA10=1;
//
//     EDIS;
//}


void setup_adr_pcb_controller();
//int get_adr_pcb_controller();



#ifdef __cplusplus
  }
#endif

#endif  // end BIG_DSP_MODULE_H_
