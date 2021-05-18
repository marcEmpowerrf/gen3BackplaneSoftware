/* 
 * File:   spi_util.h
 * Author: mobbad
 *
 * Created on June 23, 2020, 2:51 PM
 */

#ifndef SPI_UTIL_H
#define	SPI_UTIL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#include "../mcc_generated_files/mcc.h"


#define SPI_TIMEOUT_MS              5

#define SPI_TXR_BIT                 1   //bit number in register SPI1CON2
#define SPI_RXR_BIT                 0   //bit numbr in register SPI1CON2
#define SPI_CKE_BIT                 6   //bit number in register SPI1CON1
#define SPI_CKP_BIT                 5   //bit number in register SPI1CON1
#define SPI_TXBE_BIT                5   //bit number in register SPI1STATUS
#define SPI_EN_BIT                  7   //bit number in register SPI1CON0
#define SPI_BUSY_BIT                7   //bit number in register SPI1CON2

//SPI Data Registers
#define SPI_TX_DATA_REG             SPI1TXB
#define SPI_RX_DATA_REG             SPI1RXB
#define SPI_STATUS_REG              SPI1STATUS
#define SPI_TXCNTL_REG              SPI1TCNTL
#define SPI_TXCNTH_REG              SPI1TCNTH

#define SPI_ENABLE()                (SPI1CON0 |= (1 << SPI_EN_BIT))
#define SPI_DISABLE()               (SPI1CON0 &= ~(1 << SPI_EN_BIT))
#define SPI_RX_INT_ENABLE()         (PIE2bits.SPI1RXIE = 1)
#define SPI_RX_INT_DISABLE()        (PIE2bits.SPI1RXIE = 0)
#define SPI_TX_INT_DISABLE()        (PIE2bits.SPI1TXIE = 0)
#define SPI_RX_INT_CLEAR()          (PIR2bits.SPI1RXIF = 0)
#define SPI_TX_INT_CLEAR()          (PIR2bits.SPI1TXIF = 0)
#define SPI_INT_CLEAR()             (PIR2bits.SPI1IF = 0)
#define SPI_FULL_DUPLEX_MODE()      (SPI1CON2 |= (1 << SPI_TXR_BIT) | (1 << SPI_RXR_BIT))   
#define SPI_RX_ONLY_MODE()          (SPI1CON2 |= (1 << SPI_RXR_BIT));(SPI1CON2 &= ~(1 << SPI_TXR_BIT))
#define SPI_TX_ONLY_MODE()          (SPI1CON2 |= (1 << SPI_TXR_BIT));(SPI1CON2 &= ~(1 << SPI_RXR_BIT))
#define SPI_TX_COUNTER_SET(x)       SPI1TCNTL=x
#define SPI_IS_TXFIFO_EMPTY()       (SPI1STATUS & (0x20))
#define SPI_IS_TXFIFO_WRITE_ERR()   (SPI1STATUS & (0x80))
#define SPI_GET_TX_COUNT()          SPI1TCNTL
#define SPI_IS_BUSY()               (SPI1CON2 & (0x80))
#define SPI_SMP_MID()               (SPI1CON1 &= ~(1 << _SPI1CON1_SMP_POSN)) 
#define SPI_SMP_END()               (SPI1CON1 |= (1 << _SPI1CON1_SMP_POSN))
/*
 * SPI Master Clock Modes
 */
//Clock Polarity Idle:Low, Active:High; Clock Edge Active to low
#define SPI_CLK_MODE_0()            (SPI1CON1 |= (1 << SPI_CKE_BIT));(SPI1CON1 &= ~(1 << SPI_CKP_BIT)) 
//Clock Polarity Idle:Low, Active:High; Clock Edge Idle to active
#define SPI_CLK_MODE_1()            (SPI1CON1 &= ~(1 << SPI_CKE_BIT));(SPI1CON1 &= ~(1 << SPI_CKP_BIT))
//Clock Polarity Idle:High, Active:Low; Clock Edge Active to Idle
#define SPI_CLK_MODE_2()            (SPI1CON1 |= (1 << SPI_CKE_BIT));(SPI1CON1 |= (1 << SPI_CKP_BIT))
//Clock Polarity Idle:High, Active:Low; Clock Edge Idle to active
#define SPI_CLK_MODE_3()            (SPI1CON1 &= ~(1 << SPI_CKE_BIT));(SPI1CON1 |= (1 << SPI_CKP_BIT))     


//for the mode definitions refer to the comments above
typedef enum 
{
    SPI_MODE_0 = 0,
    SPI_MODE_1,
    SPI_MODE_2,
    SPI_MODE_3,
} SPI_MODE;

typedef enum
{
    SPI_SS_BP_SWITCH = 0,
    SPI_SS_FP_TS,  
} spiSlaveSelectEnum_t;


extern void  SetSpiMode( SPI_MODE mode );

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_UTIL_H */

