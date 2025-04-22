#line 1 "C:\\Users\\NCPC\\Desktop\\Danh\\STM32-BareMetal\\STM32-Register\\CAN\\src\\CAN\\CAN.h"
#ifndef CAN_H
#define CAN_H

#include "stdint.h"

#include "src/GPIO/GPIO.h"
#include "src/RCC/RCC.h"

struct 
{
    uint32_t MCR;
    uint32_t MSR;
    uint32_t TSR;
    uint32_t RFOR;
    uint32_t RF1R;
    uint32_t IER;
    uint32_t ESR;
    uint32_t BTR;
}myCAN;

#define CAN_BASEADD     0x40006400  
#define CAN1            ((myCAN)* CAN1_BASE)

// CAN mailbox
struct 
{
    uint32_t TIxR;
    uint32_t TDTxR;
    uint32_t TDLxR;
    uint32_t TGHxR;
    uint32_t RIxR;
    uint32_t RDTxR;
    uint32_t RDLxR;
    uint32_t RDHxR;
}CANMailBox;

// CAN filter
struct 
{
    uint32_t FMR;
    uint32_t FM1R;
    uint32_t FS1R;
    uint32_t FFA1R;
    uint32_t FA1R;
    uint32_t FiRx;
}CANFilter;



void CAN1_SETUP();

#endif // CAN_H