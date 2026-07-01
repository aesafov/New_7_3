#ifndef X_INTC_H_
#define X_INTC_H_

#include "x_basic_types.h"

#define XPAR_INTC_MAX_NUM_INTR_INPUTS 16

#ifdef __cplusplus
  extern "C" {
#endif

//-----------------------------------------------------------------------------
// Define the types
//-----------------------------------------------------------------------------

// This data type defines an interrupt handler for a device.
// The argument points to the instance of the component
 typedef void (*XInterruptHandler) (void *InstancePtr);

 typedef struct {
     XInterruptHandler Handler;
     void *CallBackRef;
 } XIntc_VectorTableEntry;

union XIntc_Config_reg{
    unsigned int all;
    struct{
        unsigned int Chanal0:1;
        unsigned int Chanal1:1;
        unsigned int Chanal2:1;
        unsigned int Chanal3:1;
        unsigned int Chanal4:1;
        unsigned int Chanal5:1;
        unsigned int Chanal6:1;
        unsigned int Chanal7:1;
        unsigned int Chanal8:1;
        unsigned int Chanal9:1;
        unsigned int Chanal10:1;
        unsigned int Chanal11:1;
        unsigned int Chanal12:1;
        unsigned int Chanal13:1;
        unsigned int Chanal14:1;
        unsigned int Chanal15:1;
    }bit;
};

typedef struct {
    //  unsigned int AckBeforeService;  /**< Ack location per interrupt; '1' -> Ack before service, '0' -> Ack after service */
    union XIntc_Config_reg  AckBeforeService;
    //  unsigned int InterruptTypeIsEdge; /* Define type of interrupt: '1' -> edge, '0' -> level */
    union XIntc_Config_reg  InterruptTypeIsEdge;
    //  unsigned int LevelSensitiveIsHigh; /* Define sensitive level of interrupt: '1' -> high, '0' -> low */
    union XIntc_Config_reg  LevelSensitiveIsHigh;
    //  unsigned int EdgeSensitiveIsRising; /* Define sensitive edge of interrupt: '1' -> rising edge, '0' -> falling edge */
    union XIntc_Config_reg  EdgeSensitiveIsRising;
    XIntc_VectorTableEntry HandlerTable[XPAR_INTC_MAX_NUM_INTR_INPUTS]; /** Static vector table of interrupt handlers */
} XIntc_Config;

typedef struct {
    unsigned int TypeAccess;            /* Define type of access */
    unsigned int AdrPlane;              /* Address of slave's Plane */
    unsigned int BaseAddress;           /**< Base address of registers */
    unsigned int IsReady        : 1;    /**< Device is initialized and ready */
    unsigned int IsStarted      : 1;    /**< Device has been started */
    unsigned int Mode           : 1;
    unsigned int UnhandledInterrupts; /**< Intc Statistics */
    XIntc_Config CfgPtr;     /**< Pointer to instance config entry */
    struct{
        unsigned int rd_isr;
        unsigned int rd_ipr;
        unsigned int rd_ier;
        unsigned int rd_ivr;
        unsigned int rd_mer;
    }Reg_rd;
    UInt16 BitPosMask[16];
} XIntc;

#ifdef __cplusplus
  }
#endif

#endif // end X_INTC_H_
