#ifndef X_INPUT_NEW_H_
#define X_INPUT_NEW_H_

#include "x_basic_types.h"
#include "x_access_uni.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct {
    unsigned int use_config                     : 1;    // 1 bit
    unsigned int block_is_master                : 1;    // 1 bit
    unsigned int use_sync_rd_wr                 : 1;    // 1 bit
    unsigned int use_max_lenth                  : 1;    // 1 bit
    unsigned int use_min_lenth                  : 1;    // 1 bit
    unsigned int use_td                         : 1;    // 1 bit
    unsigned int use_test_reg                   : 1;    // 1 bit
    unsigned int use_speed_sensor               : 1;    // 1 bit
    unsigned int use_count_td_for_speed_sensor  : 1;    // 1 bit
    unsigned int use_sp_clk_en                  : 1;    // 1 bit
    unsigned int speed_latch_on_spad            : 1;    // 1 bit
    unsigned int use_run_triggering             : 1;    // 1 bit
    unsigned int range_filtr                    : 4;    // 16 bits, but use 4bits for soft
    unsigned int div_tap                        : 8;    // 16 bits, but use 8bits for soft
    unsigned int frequency                      : 8;    // 16 bits, but use 8bits for soft
    unsigned int case_speed_chanal;                     // 16 bits
} Xinput_new_config;

typedef struct {
    unsigned int filtr_max                          : 8;    // max 8 bits
    unsigned int filtr_high                         : 8;    // max 8 bits

    unsigned int filtr_low                          : 8;    // max 8 bits
    unsigned int case_type_of_error                 : 1;    // 1 bit
    unsigned int mask_er                            : 1;    //  1 bit
    unsigned int mask_er_lenth_under                : 1;    //  1 bit
    unsigned int mask_er_lenth_over                 : 1;    //  1 bit
    unsigned int mask_er_sum_for_er0_line_or_hwp    : 1;    // 1 bit
    unsigned int mask_er_sum_for_own_line_or_int    : 1;    // 1 bit
    unsigned int use_double_sample_in_fifo_line     : 1;    // 1 bit
    unsigned int reset_count_td_one_time_on_period  : 1;    // 1 bit

    unsigned int filtr_clk_en                       : 3;    // 3 bits
    unsigned int td_clk_en                          : 3;    // 3 bits
    unsigned int sp_clk_en                          : 3;    // 3 bits
    unsigned int rd_speed_count_fifo                : 6;    // 6 bits

    unsigned int max_lenth;                                 // 16 bits
    unsigned int min_lenth;                                 // 16 bits
    unsigned int test_reg;                                  // 16 bits

    unsigned int rd_speed_count_forward             : 6;    // 6 bits
    unsigned int rd_speed_count_backward            : 6;    // 6 bits
    unsigned int rd_er                              : 1;    // 1 bit
    unsigned int rd_er_over                         : 1;    // 1 bit
    unsigned int rd_er_under                        : 1;    // 1 bit
    unsigned int rd_status                          : 1;    // 1 bit

    unsigned int rd_count_td_low;                           // 16 bits
    unsigned int rd_count_td_high;                          // 16 bits
    unsigned int rd_speed_fifo_data;                        // 16 bits
    unsigned int rd_test_reg;                               // 16 bits
    unsigned int rd_result_triggering_data;                 // 16 bits
} Xinput_new_chanal;

typedef struct {
    Xinput_new_chanal ChanalPtr[16];
    unsigned int res_er                         : 1;    // 1 bit , reset er, er_over, er_under
    unsigned int res_speed_direction            : 1;    // 1 bit , reset rd_speed_count_forward, rd_speed_count_backward
    unsigned int res_speed_fifos                : 1;    // 1 bit , reset fifo counts
    unsigned int rd_status_er0_line_or_hwp      : 1;    // 1 bit
    unsigned int rd_status_own_line_or_int      : 1;    // 1 bit
    unsigned int rd_ready_triggering            : 1;    // 1 bit
    unsigned int rd_result_triggering_chanals;          // 16 bits
} Xinput_new_all_chanals;

typedef struct {
    Xmemory_uni             Xmemory_uni0;
    unsigned int            BaseAddress;        /* Base address of registers */
    unsigned int            IsReady     : 1;    /* Device is initialized and ready */
    unsigned int            IsStarted   : 1;    /* Device has been started */
    Xinput_new_config       CfgPtr;             /* Pointer to instance config entry */
    Xinput_new_all_chanals  ChanalsPtr;
} Xinput_new_uni;

#ifdef __cplusplus
  }
#endif

#endif // end X_INPUT_NEW_H_
