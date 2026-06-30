#ifndef MAIN_MAIN_APP_H_
#define MAIN_MAIN_APP_H_

#ifdef __cplusplus
  extern "C" {
#endif

void initialization_app_load_xilinx();
void initialization_app_before_load_xilinx();
void initialization_app_after_load_xilinx();
void initialization_app_before_init_all_interrupts();
void initialization_app_after_init_all_interrupts();
void initialization_app_before_main_while();
void initialization_app_interrupts();
void run_app_main_while();
void run_rs_bios_main_while();

#ifdef __cplusplus
  }
#endif

#endif // end  MAIN_MAIN_APP_H_
