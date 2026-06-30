#ifndef CNTRL_ADR_H_
#define CNTRL_ADR_H_

#ifdef __cplusplus
  extern "C" {
#endif

#define CNTRL_ADDR_FOR_ALL_DEF 0x4

// адрес контроллера для посылки всем ячейкам
extern int ADDR_FOR_ALL;

// адрес контроллера
extern int CNTRL_ADDR;

// установка адреса контроллера для прошивки
void set_cntrl_addr (int cntrl_addr,int cntrl_addr_for_all);

extern int cntr_addr_c;
extern int cntr_addr_c_all;

#ifdef __cplusplus
  }
#endif

#endif // end CNTRL_ADR_H_
