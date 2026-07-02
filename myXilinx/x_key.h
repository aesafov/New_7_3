#ifndef X_KEY_H_
#define X_KEY_H_

struct XKey_array{
    unsigned int key0;
    unsigned int key1;
    unsigned int key2;
    unsigned int key3;
    unsigned int key4;
    unsigned int key5;
    unsigned int key6;
    unsigned int key7;
    unsigned int key8;
    unsigned int key9;
    unsigned int key10;
    unsigned int key11;
    unsigned int key_stop0;
    unsigned int key_stop1;
    unsigned int key_stop2;
    unsigned int key_stop3;
};

union XKey_reg{
    unsigned int all;
    struct {
        unsigned int key0:1;
        unsigned int key1:1;
        unsigned int key2:1;
        unsigned int key3:1;
        unsigned int key4:1;
        unsigned int key5:1;
        unsigned int key6:1;
        unsigned int key7:1;
        unsigned int key8:1;
        unsigned int key9:1;
        unsigned int key10:1;
        unsigned int key11:1;
        unsigned int key_stop0:1;
        unsigned int key_stop1:1;
        unsigned int key_stop2:1;
        unsigned int key_stop3:1;
    }bit;
};

union XKey_long_reg{
  unsigned long all;
  struct {
   unsigned int key0:2;
   unsigned int key1:2;
   unsigned int key2:2;
   unsigned int key3:2;
   unsigned int key4:2;
   unsigned int key5:2;
   unsigned int key6:2;
   unsigned int key7:2;
   unsigned int key8:2;
   unsigned int key9:2;
   unsigned int key10:2;
   unsigned int key11:2;
   unsigned int key_stop0:2;
   unsigned int key_stop1:2;
   unsigned int key_stop2:2;
   unsigned int key_stop3:2;
  }bit;
};

union XKeyXilinxPWMControll{
  unsigned int all;
  struct {
    unsigned int CountEnOnRise:1;
    unsigned int CountRes:1;
    unsigned int DirD_Config:1;
    unsigned int DirEN_Config:1;
    unsigned int DirEn_ConfigIsStrob:1;
    unsigned int DirEnPipe:1;
    unsigned int ModeIsConfig:1;
    unsigned int GlobalMask:1;
    unsigned int Reset:1;
    unsigned int Rezerv:7;
  }bit;
};

union XKeyXilinxPWMMasksBit{
  unsigned int all;
  struct {
   unsigned int IntTop:1;
   unsigned int IntBottom:1;
   unsigned int UpdateTop:1;
   unsigned int UpdateBottom:1;
   unsigned int Rezerv:12;
  }bit;
};

struct XKeyXilinxPWMMasksReg{
    union XKeyXilinxPWMMasksBit key0;
    union XKeyXilinxPWMMasksBit key1;
    union XKeyXilinxPWMMasksBit key2;
    union XKeyXilinxPWMMasksBit key3;
    union XKeyXilinxPWMMasksBit key4;
    union XKeyXilinxPWMMasksBit key5;
    union XKeyXilinxPWMMasksBit key6;
    union XKeyXilinxPWMMasksBit key7;
    union XKeyXilinxPWMMasksBit key8;
    union XKeyXilinxPWMMasksBit key9;
    union XKeyXilinxPWMMasksBit key10;
    union XKeyXilinxPWMMasksBit key11;
    union XKeyXilinxPWMMasksBit key_stop0;
    union XKeyXilinxPWMMasksBit key_stop1;
    union XKeyXilinxPWMMasksBit key_stop2;
    union XKeyXilinxPWMMasksBit key_stop3;
};

struct XKeyXilinxPWM{
    struct {
        struct XKey_array  Period_us;
        struct XKey_array  Tay_us;
        struct XKey_array  Phase_deg;
        union XKey_reg   MaskIntTop;
        union XKey_reg   MaskIntBottom;
        union XKey_reg   MaskUpdateTop;
        union XKey_reg   MaskUpdateBottom;
        union XKey_reg   MaskTk;
        union XKey_reg   InvTk;
        union XKey_reg   IARTop;
        union XKey_reg   IARBottom;
    } Setup;
    struct {
    union XKey_reg IPRTop;
    union XKey_reg IPRBottom;
    } Read;
    struct {
        union XKeyXilinxPWMControll Controll;
        unsigned int       CountB;
        struct XKey_array  Period_tic;
        struct XKey_array  Tay_tic;
        struct XKey_array  Phase_tic;
        union  XKey_reg    DirNow;
        struct  XKeyXilinxPWMMasksReg Masks;
} Tune;
};

struct XKey_RW{
  union XKey_reg Write;
  union XKey_reg Read;
};

typedef volatile struct {
    struct XKeyXilinxPWM XilinxPWM;
    struct XKey_RW       Reg;
    struct XKey_RW       Sorce_Is_Reg;
    struct XKey_RW       Sorce_Is_Xilinx;
    union XKey_long_reg  Sorce_Is;
    struct XKey_RW       Use_HW_blocking;
    union  XKey_reg      Status;
    unsigned int IsReady:1;
} XKey_all;

#endif // end X_KEY_H_
