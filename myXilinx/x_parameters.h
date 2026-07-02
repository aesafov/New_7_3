#ifndef X_PARAMETERS_H_
#define X_PARAMETERS_H_

//------------------------------------------------------------------------------
// Platfortm
//------------------------------------------------------------------------------
//  #define C_Microblaze
    #define C_Tms_28xx
//  #define C_Stm
//  #define C_SystemC_Simulation

//------------------------------------------------------------------------------
//    Project type
//------------------------------------------------------------------------------
#define C_ProjectType_is_22220      10
#define C_ProjectType_is_Balzam_2   11
#define C_ProjectType_is_21300_2    12
#define C_ProjectType_is_21180_2    13

#define C_project_type  C_ProjectType_is_21180_2


//------------------------------------------------------------------------------
// Plane number
//------------------------------------------------------------------------------

#define C_cds_tk_number     4
#define C_cds_in_number     3
#define C_cds_out_number    3
#define C_adc_number        2
#define C_hwp_number        2
#define C_omega_number      2


//------------------------------------------------------------------------------
// Plane address
//------------------------------------------------------------------------------
#define C_controller_address        1
#define C_cds_in0_address           2
#define C_cds_in1_address           3
#define C_cds_in2_address           4
#define C_cds_tk0_address           5
#define C_cds_tk1_address           6
#define C_cds_tk2_address           9
#define C_cds_tk3_address           10
#define C_cds_out0_address          11
#define C_cds_out1_address          12
#define C_cds_out2_address          13
#define C_adc0_address              7
#define C_adc1_address              8
#define C_cds_speed_sensor_address  14
#define C_hwp0_address              16
#define C_hwp1_address              17

//------------------------------------------------------------------------------
// default value for test_reg
//------------------------------------------------------------------------------
#define C_test_reg_value_default            0x5678
#define C_test_reg_value_after_init         0x9abc
//------------------------------------------------------------------------------
// Return code offset
//------------------------------------------------------------------------------
#define C_transactor_Status_offset              0x0000
#define C_access_Status_offset                  0x0010
#define C_access_uni_Status_offset              0x0020
#define C_command_Status_offset                 0x0030
#define C_direct_bus_t2_v1_Status_offset        0x0040
#define C_clock_t1_v4_Status_offset             0x0050
#define C_serial_bus_t2_v1_Status_offset        0x0060
#define C_serial_bus_t3_v1_Status_offset        0x0070
#define C_serial_bus_t4_v1_Status_offset        0x0080
#define C_memory_t2_v2_Status_offset            0x0090

#define C_serial_bus_simple_t2_v1_Status_offset 0x00a0
#define C_parallel_bus_t3_v7_Status_offset      0x00b0
#define C_soft_fifo_Status_offset               0x00c0
#define C_string_Status_offset                  0x00d0
#define C_printf_Status_offset                  0x00c0

#define C_fpga_sim_t1_v1_Status_offset          0x0100
#define C_fpga_sim_t2_v2_Status_offset          0x0110

#define C_controller_fpga_sim_Status_offset                 0x0430
//  #define C_cds_sp6_cpld_serial_bus_Status_offset             0x0440
#define C_cds_fpga_serial_bus_Status_offset                 0x0450
#define C_cds_fpga_parallel_bus_Status_offset               0x0460
#define C_cds_sp2e_cpld_serial_bus_Status_offset            0x0470
#define C_cds_sp2e_seeprom_i2c_Status_offset                0x0480
#define C_cds_sp6_flash_spi_Status_offset                   0x0490
#define C_controller_fpga_control_regs0_Status_offset       0x04a0

#define C_controller_parallel_bus_Status_offset         0x0530
#define C_controller_fpga_serial_bus_Status_offset      0x0540
#define C_controller_cpld_serial_bus_Status_offset      0x0550

#define C_cds_sp2e_cpld_Status_offset       0x0600
#define C_cds_sp2e_seeprom_Status_offset    0x0610
#define C_cds_sp2e_tk_fpga_Status_offset    0x0620
#define C_cds_sp2e_tk_Status_offset         0x0630

#define C_x_timer_Status_offset             0x0800
#define C_intc_Status_offset                0x0810
#define C_x_input_new_Status_offset         0x0820
#define C_x_speed_sensor_Status_offset      0x0830
#define C_x_tools_Status_offset             0x0840
#define C_cds_sp6_cpld_serial_bus_Status_offset 0x0850
#define C_crc_Status_offset                 0x0860

#define C_project_Status_offset             0x0880
#define C_project_plane_Status_offset       0x0890
#define C_project_selftest_Status_offset    0x08a0
#define C_project_test_hwp_adc_Status_offset 0x08b0

#define C_controller_memory_Status_offset   0x0900
#define C_controller_Status_offset          0x0910
#define C_controller_tms_Status_offset      0x0920
#define C_controller_fpga_Status_offset     0x0930
#define C_controller_fpga_Status_offset_2   0x0940
#define C_controller_cpld_Status_offset     0x0950
#define C_controller_ram_Status_offset      0x0960
#define C_controller_flash_Status_offset    0x0970
#define C_cds_Status_offset                 0x0980
#define C_cds_fpga_Status_offset            0x0990
#define C_cds_cpld_Status_offset            0x09a0
#define C_cds_seeprom_Status_offset         0x09b0
#define C_cds_flash_Status_offset           0x09c0

#define C_cds_in_Status_offset              0x0a20
#define C_cds_in_fpga_Status_offset         0x0a30

#define C_cds_out_Status_offset             0x0a40
#define C_cds_out_fpga_Status_offset        0x0a50

#define C_adc_Status_offset                 0x0a60
#define C_adc_cpld_Status_offset            0x0a70
#define C_adc_fpga_Status_offset            0x0a80
#define C_adc_fpga_Status_offset_2          0x0a90

#define C_cds_rom_Status_offset             0x0aa0

#define C_cds_sp6_cpld_Status_offset        0x0ac0
#define C_cds_flash_serialize_Status_offset 0x0ad0
#define C_cds_flash_c2082_Status_offset     0x0ae0
#define C_key_Status_offset                 0x0af0

#define C_hwp_serial_bus_Status_offset      0x0b00
#define C_hwp_Status_offset                 0x0b10

#define C_controller_fpga_handler_Status_offset 0x0b20
#define C_dispatcher_Status_offset          0x0b30
#define C_error_buffer_Status_offset        0x0b40
#define C_omega_serial_bus_Status_offset    0x0b50
#define C_omega_Status_offset               0x0b60
#define C_omega_cpld_Status_offset          0x0b70
#define C_omega_adc_Status_offset           0x0b80

#define C_controller_fpga_clock_Status_offset 0x0b90

#define C_controller_fpga_test_io_Status_offset 0x0c00

#define C_project_test_tk_Status_offset     0x0c10
#define C_project_test_in_Status_offset     0x0c20
#define C_project_test_out_Status_offset    0x0c30
#define C_project_test_adc_Status_offset    0x0c40
#define C_project_test_hwp_Status_offset    0x0c50

#define C_cds_fpga_common_Status_offset     0x0d00
#define C_cds_fpga_common_Status_offset_2   0x0d10
#define C_cds_tk_fpga_logic_Status_offset   0x0d20
#define C_cds_tk_fpga_Status_offset         0x0d30
#define C_cds_tk_Status_offset              0x0d40

//------------------------------------------------------------------------------
// Plane Controller, memory map for parallel bus
//------------------------------------------------------------------------------
#define C_controller_tms_parallel_bus_offset        0x3f0000
#define C_controller_fpga_parallel_bus_offset       0x002000
#define C_controller_ram_parallel_bus_offset        0x080000
#define C_controller_flash_parallel_bus_offset      0x100000

#define C_controller_tms_parallel_bus_length        0x010000
#define C_controller_fpga_parallel_bus_length       0x000200
#define C_controller_ram_parallel_bus_length        0x080000
#define C_controller_flash_parallel_bus_length      0x080000

//------------------------------------------------------------------------------
// Plane Controller, memory map for fpga_serial bus
//------------------------------------------------------------------------------
#define C_controller_fpga_serial_bus_length 0x000200

//------------------------------------------------------------------------------
// Plane Controller, memory map for cpld_serial bus
//------------------------------------------------------------------------------
#define C_controller_cpld_serial_bus_length 0x0004

#define C_controller_fpga_serial_bus_use_as_direct_bus
#define C_controller_cpld_serial_bus_use_as_direct_bus

//------------------------------------------------------------------------------
// Plane Cds, memory map for fpga_serial_bus
//------------------------------------------------------------------------------
#define C_cds_fpga_serial_bus_length    0x10000

//------------------------------------------------------------------------------
// Plane Cds sp6, memory map for cpld_serial_bus
//------------------------------------------------------------------------------
#define C_cds_sp6_cpld_serial_bus_length    0x0008

//------------------------------------------------------------------------------
// Plane Cds sp2e, memory map for cpld_serial_bus
//------------------------------------------------------------------------------
#define C_cds_sp2e_cpld_serial_bus_length   0x0001

//------------------------------------------------------------------------------
// Plane Cds sp2e, memory map for seeprom_i2c, bytes
//------------------------------------------------------------------------------
//#define C_cds_sp2e_seeprom_i2c_length 0x20000
#define C_cds_seeprom_length_bytes      0x20000

//------------------------------------------------------------------------------
// Plane Cds sp6, memory map for flash_spi, bytes
//------------------------------------------------------------------------------
//#define C_cds_sp6_flash_spi_length    0x80000

//------------------------------------------------------------------------------
// Plane Cds, memory map for fpga_serial_bus
//------------------------------------------------------------------------------
#define C_omega_serial_bus_length   0x10

#endif // end X_PARAMETERS_H_
