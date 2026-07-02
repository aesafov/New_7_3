#ifndef XP_ADC_H_
#define XP_ADC_H_

#include "x_basic_types.h"
#include "x_access_uni.h"
#include "xp_cds_rom.h"

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef struct {
    UInt16 type;
    UInt16 version;
    UInt16 wrapper_build;
    UInt16 build;
    UInt16 pause_range;
    UInt16 coef_range;
    UInt16 acc_short_range;
    UInt16 acc_short_sell_max;
    UInt16 coef_level_range;
    UInt16 use_min_max;
    UInt16 use_min;
    UInt16 use_max;
} T_adc_fpga_config;

typedef union {
    UInt16 all;
    struct{
        UInt16  msb     : 1;
        UInt16  rang    : 1;
        UInt16  a       : 1;
        UInt16  ab      : 1;
        UInt16  unused  :12;
    }bit;
}TU_adc_fpga_adc_error;

typedef union {
    UInt16 all;
    struct{
        UInt16  value   :12;
        UInt16  ab      : 1;
        UInt16  a       : 1;
        UInt16  rang    : 1;
        UInt16  msb     : 1;
    }bit;
}TU_adc_fpga_adc_data;

typedef struct {
    struct TS_adc_fpga_channel_read_error {
        struct TS_adc_fpga_channel_read_error_status {
            TU_adc_fpga_adc_error   adc;
            UInt16                  min : 1;
            UInt16                  max : 1;
        } status;

        struct TS_adc_fpga_channel_read_error_latch {
            TU_adc_fpga_adc_error   adc;
            UInt16                  min : 1;
            UInt16                  max : 1;
        } latch;
    } error;

    struct TS_adc_fpga_channel_read_value {
        TU_adc_fpga_adc_data        data_fast_current;
        Int16                       acc_short;
    } value;
}T_adc_fpga_channel_read;

#define C_adc_fpga_coef_size_max 64

typedef struct {
    UInt16  coef_size;
    Int16   coef[C_adc_fpga_coef_size_max]; // -2*15 <= (coef[i] * norma) < 2^15
    struct {
        UInt16  id;         // unique id
        UInt32  coef_abs_sum;
        UInt16  coef_abs_sum_range;
        Int32   coef_sum;
        UInt16  coef_sum_range;
        float   norma_coef;
        float   norma_sum;
        float   norma;      // norma = norma_coef * norma_sum
        float   norma_error;
    } info;

    struct {
        UInt16 normalize_coef_enable        : 1;
        UInt16 normalize_coef_sum_enable    : 1;
    } option;

} T_adc_fpga_channel_filter;

typedef struct {
    UInt16 store_access_count;
    UInt16 store_mask;
} T_adc_fpga_info;

typedef struct {

    struct TS_adc_fpga_channel_write_mask {
        UInt16          error_adc   : 1;
        UInt16          error_min   : 1;
        UInt16          error_max   : 1;
    } mask;

    struct TS_adc_fpga_channel_write_tune {
        UInt16          pause           : 8;
        UInt16          acc_short_sell  : 5;
        UInt16          coef_level      : 6;
        UInt16          min             ; // :12;
        UInt16          max             ; // :12;
    } tune;

    T_adc_fpga_channel_filter       filter;

}T_adc_fpga_channel_write;

typedef struct {
    struct TS_adc_fpga_read {

        T_adc_fpga_config   config;

        struct TS_adc_fpga_read_selftest {
            UInt16 test_reg[16];
        } selftest;

        struct TS_adc_fpga_read_simulation {
            UInt16  mode_is_simulation  : 1;
        } simulation;

        struct TS_adc_fpga_read_status {
            UInt16 er0_line         : 1;
            UInt16 set_mode_line    : 1;
        } status;

        struct TS_adc_fpga_read_error {
            UInt16 er0_in       : 1;
            UInt16 adc_sum      : 1;
            UInt16 min_max_sum  : 1;
            UInt16 er0_out      : 1;
        } error;

        T_adc_fpga_channel_read     channels[16];

    } read;

    struct TS_adc_fpga_write {

        struct TS_adc_fpga_write_selftest {
            UInt16 make_error_on_er0_out : 1;
            UInt16 test_reg[16];
        } selftest;

        union TU_adc_fpga_write_mask {
            UInt16 all;
            struct TS_adc_fpga_write_mask {
                UInt16 er0_in                           : 1;
                UInt16 er0_out                          : 1;
                UInt16 error_adc_sum_for_er0_out        : 1;
                UInt16 error_min_max_sum_for_er0_out    : 1;
                UInt16 unused                           :12;
            } bit;
        } mask;

        struct TS_adc_fpga_write_reset {
            UInt16 error_er0_in         : 1;
            UInt16 error_adc            : 1;
            UInt16 error_adc_sum        : 1;
            UInt16 error_min_max        : 1;
            UInt16 error_min_max_sum    : 1;
        } reset;

        struct TS_adc_fpga_write_simulation {
            UInt16                  mode_is_simulation  : 1;
            UInt16                  address             : 4;
            TU_adc_fpga_adc_data    data;
            TU_adc_fpga_adc_error   error;
        } simulation;

        struct TS_adc_fpga_write_adc_tune {
            UInt16 count_div        : 5;
            UInt16 enable_work      : 1;
            UInt16 sclk_delay       : 4;
        } adc_tune;

        T_adc_fpga_channel_write    channels[16];

    } write;

    Xmemory_uni         memory_uni;
    UInt16              plane_index; // 0 or 1
    T_component_status  status;
    UInt16              was_reset;
    T_adc_fpga_info     info;
} T_adc_fpga;

typedef struct TS_adc{
    T_adc_fpga  fpga;
    T_cds_rom   rom;

    UInt16              plane_address; // 0 to 15
    UInt16              useit;
    T_component_status  status;
} T_adc;

// paralle_bus_read_data
typedef struct {
    Int16   acc_short[16];
} T_adc_fpga_paralle_bus_read_data;

#ifdef __cplusplus
  }
#endif

#endif // end XP_ADC_H_
