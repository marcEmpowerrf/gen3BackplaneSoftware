/* 
 * File:   switch.h
 * Author: mobbad
 *
 * Created on June 22, 2020, 2:50 PM
 */

#ifndef SWITCH_H
#define	SWITCH_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include "../mcc_generated_files/mcc.h"

    
#define REGISTER_ADDRESS(p,f,a)  (( unsigned short )( ( p & 0x0F << 12) | ( f & 0x0F << 8) | ( a & 0xFF ) ))

#define SPI_READ                  3
#define SPI_WRITE                 2

#define SPI_TURNAROUND_SHIFT        5
#define MMD_SETUP    0x011A   // and 0x011B
#define MMD_DATA     0x011C

#define DISABLE_1000BASE_T ( ( unsigned short) 0x0300 )
    
#define SWAP_16

typedef struct __attribute__((__packed__)) spiMessage {
    unsigned char cmd ;
    unsigned char a11_a16 ;     //xx65  4321
    unsigned char a3_a10;       //a987 6543
    unsigned char a0_a2;        // a2a1a0x xxxx
    unsigned char data;
    unsigned char data1;
} SPI_MESSAGE;

typedef union {
    SPI_MESSAGE Message_T;
    unsigned char P[6];
}spiMessage_U;

typedef struct __attribute__((__packed__))  MMDST {
        unsigned char dev;
        unsigned char op;
} MMDST;

typedef union {
    MMDST regS;
    unsigned short  reg16;
}MMDST_U;

unsigned char read_switch_reg ( unsigned short reg_adr );
unsigned char write_switch_reg ( unsigned short reg_adr, unsigned char val );

unsigned short read_switch_reg16 ( unsigned short reg_adr );
unsigned char write_switch_reg16 ( unsigned short reg_adr, unsigned short val );

//
void write_mmd_device(unsigned short port, unsigned char device, 
        unsigned short regoffset, unsigned value);

unsigned short read_mmd_device(unsigned short port, unsigned char device, 
        unsigned short regoffset);

unsigned short configure_switch();
bool getPortLink(int port );
void resetPort( int port, bool hardReset);
bool isAnyLinkUp(int *nbPort);
unsigned short getPhyBaseReg( int port );
unsigned short getPhyStatusReg( int port );
unsigned short get1000baseTPhy( int port );
void configclock( bool enable, bool clk25M) ;
void disableAuto( int port,  bool isGig) ;
void regdump( ) ;
void getPortStatus(int port);
void disable1000BaseT(unsigned short port);

typedef struct  {
unsigned char device;
unsigned short regoffset;
unsigned short val;
} SW_ERR_S;

#define SW_MAX_CFG    22
SW_ERR_S SW_CONFIG[SW_MAX_CFG] =
{
// Improve The Phy--MOD 1
{0x01   ,   0x6F    ,   0xDD0B  },
{0x01   ,   0x8F    ,   0x6032  },
{0x01   ,   0x9D    ,   0x248C  },
{0x01   ,   0x75    ,   0x0060  },
{0x01   ,   0xD3    ,   0x7777  },
{0x1C   ,   0x06    ,   0x3008  },
{0x1C   ,   0x08    ,   0x2001  },
//Transmit Wave Amplitude improvement - MOD2
{0x1C   ,   0x4     ,   0x00D0  },
// Energy efficient Ethernet - MOD4
{0x07   ,   0x3C    ,   0x0000  }
#ifdef APPLY_MOD_7
,
// Power Supply setup  - MOD7
{0x1C   ,   0x13    ,    0x6EFF },
{0x1C   ,   0x14    ,    0xE6FF },
{0x1C   ,   0x15    ,    0x6EFF },
{0x1C   ,   0x16    ,    0xE6FF },
{0x1C   ,   0x17    ,    0x00FF },
{0x1C   ,   0x18    ,   0x43FF  },
{0x1C   ,   0x19    ,   0xC3FF  },
{0x1C   ,   0x1A    ,   0x6FFF  },
{0x1C   ,   0x1B    ,    0x07FF },
{0x1C   ,   0x1C    ,    0x0FFF },
{0x1C   ,   0x1D    ,    0xE7FF },
{0x1C   ,   0x1E    ,    0xEFFF },
{0x1C   ,   0x20    ,    0xEEEE }
#endif 
};


#ifdef	__cplusplus
}
#endif

#endif	/* SWITCH_H */

