#ifndef XP_CDS_FLASH_H_
#define XP_CDS_FLASH_H_

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

typedef enum {
    Cds_Falsh_is_M25P32,
    Cds_Flash_is_AT25F4046
} T_Cds_Flash_Manufacture;

typedef struct TS_cds_flash {
    T_Cds_Flash_Manufacture type;
} T_cds_flash;

#ifdef __cplusplus
  }
#endif

#endif // end XP_CDS_FLASH_H_
