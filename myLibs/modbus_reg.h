#ifndef MODBUS_REG_H_
#define MODBUS_REG_H_

struct  MODBUS_WORD {       // bit   description
   unsigned int     LB:8;     // 16:23 High word low byte
   unsigned int     HB:8;     // 24:31 High word high byte
};


struct  MODBUS_BITS {       // bit   description
        unsigned int bit0:  1;
        unsigned int bit1:  1;
        unsigned int bit2:  1;
        unsigned int bit3:  1;
        unsigned int bit4:  1;
        unsigned int bit5:  1;
        unsigned int bit6:  1;
        unsigned int bit7:  1;
        unsigned int bit8:  1;
        unsigned int bit9:  1;
        unsigned int bit10: 1;
        unsigned int bit11: 1;
        unsigned int bit12: 1;
        unsigned int bit13: 1;
        unsigned int bit14: 1;
        unsigned int bit15: 1;
};

typedef union {
   unsigned int        all;
   struct MODBUS_BITS  bit;
   struct  MODBUS_WORD byte;
} MODBUS_REG;

#endif // end MODBUS_REG_H_
