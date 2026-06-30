#include "cntrl_adr.h"

#define ADDR_FOR_ALL_DEF    0x4

// адрес контроллера для посылки всем ячейкам
int ADDR_FOR_ALL = ADDR_FOR_ALL_DEF;

// адрес контроллера
int CNTRL_ADDR=1;

int cntr_addr_c;
int cntr_addr_c_all;

// установка адреса контроллера для прошивки
void set_cntrl_addr (int cntrl_addr,int cntrl_addr_for_all)
{
  CNTRL_ADDR = cntrl_addr;
  ADDR_FOR_ALL = cntrl_addr_for_all;
}
