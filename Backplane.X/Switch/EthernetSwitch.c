/* 
 * File:   switch.c
 * Author: mobbad
 *
 * Created on June 22, 2020, 2:51 PM
 */

#include "EtherenetSwitch.h"
#include "../mcc_generated_files/mcc.h"

/*
 * 
 */




unsigned char read_switch_reg ( unsigned short reg_adr )
{
    SPI_MESSAGE msg;
    int i =0;
    unsigned char value;
    msg.cmd = SPI_READ << 5;
    msg.a0_a2   =  ( unsigned char ) ((reg_adr & 0x7) << SPI_TURNAROUND_SHIFT);
    msg.a3_a10  = ( unsigned char ) ((reg_adr >> 3) & 0xFF);
    msg.a11_a16 = ( unsigned char ) ( (reg_adr >> 11) & 0xFF);

   spiMessage_U msgU;
   msgU.Message_T =msg;

    SPI1_CHIP_SEL_SetHigh(); 
    __delay_us(10);
    SPI1_CHIP_SEL_SetLow();
    
    for (i=0; i < 5 ; i++ ) 
    {
        // send read command
       // SPI1_WriteByte(  msgU.P[i]  );
        value = SPI1_ExchangeByte(msgU.P[i]);
    }
    
    // value = SPI1_ReadByte();
  
 
    SPI1_CHIP_SEL_SetHigh(); 
           
   return value;
}


unsigned char write_switch_reg ( unsigned short reg_adr, unsigned char val )
{
    SPI_MESSAGE msg;
    int i =0;
     unsigned char value;
    //unsigned char dataOut[5];
    msg.cmd = SPI_WRITE << 5;
    msg.a0_a2   = ( unsigned char ) ((reg_adr & 0x7) << SPI_TURNAROUND_SHIFT);
    msg.a3_a10  = ( unsigned char ) ((reg_adr >> 3) & 0xFF);
    msg.a11_a16 = ( unsigned char ) ((reg_adr >> 11) & 0xFF);
    msg.data = val;

    spiMessage_U msgU;
    msgU.Message_T =msg;

    SPI1_CHIP_SEL_SetLow();
    
    for ( i=0; i < 5; i++ ) 
    {
        value = SPI1_ExchangeByte(msgU.P[i]);
    }
 
    SPI1_CHIP_SEL_SetHigh(); 
 
    return 0;

}
//
unsigned short read_switch_reg16 ( unsigned short reg_adr )
{
    SPI_MESSAGE msg;
    int i =0;
    unsigned char val1, val2;
    unsigned short value;
    msg.cmd = SPI_READ << 5;
    msg.a0_a2   = ( unsigned char ) ((reg_adr & 0x7) << SPI_TURNAROUND_SHIFT);
    msg.a3_a10  = ( unsigned char ) ((reg_adr >> 3) & 0xFF);
    msg.a11_a16 = ( unsigned char ) ((reg_adr >> 11) & 0xFF);

   spiMessage_U msgU;
   msgU.Message_T =msg;

    SPI1_CHIP_SEL_SetLow();
    
    for (i=0; i < 5 ; i++ ) 
    {
        // send read command

        val1 = SPI1_ExchangeByte(msgU.P[i]);
    }
    // Add one more  read
    
    val2 = SPI1_ExchangeByte(0);
    
#ifdef SWAP_16   
    value = val1;
    value = (value << 8) + val2;
#else
    value= val2;
    value = val1 + ( value << 8 );
#endif
  
 
    SPI1_CHIP_SEL_SetHigh(); 
           
   return value;
}

void read_switch_reg32 ( unsigned short reg_adr, unsigned short *msb, unsigned short *lsb )
{
    SPI_MESSAGE msg;
    int i =0;
    unsigned char val1, val2, val3, val4;
    unsigned short value;
    msg.cmd = SPI_READ << 5;
    msg.a0_a2   = ( unsigned char ) ((reg_adr & 0x7) << SPI_TURNAROUND_SHIFT);
    msg.a3_a10  = ( unsigned char ) ((reg_adr >> 3) & 0xFF);
    msg.a11_a16 = ( unsigned char ) ((reg_adr >> 11) & 0xFF);

   spiMessage_U msgU;
   msgU.Message_T =msg;

    SPI1_CHIP_SEL_SetLow();
    
    for (i=0; i < 5 ; i++ ) 
    {
        // send read command

        val1 = SPI1_ExchangeByte(msgU.P[i]);
    }
    // Add one more  read
    
    val2 = SPI1_ExchangeByte(0);
    
     val3 = SPI1_ExchangeByte(0);
     
     val4 = SPI1_ExchangeByte(0);
     
     SPI1_CHIP_SEL_SetHigh(); 
     
#ifdef SWAP_16   
    value = val1;
    value = (value << 8) + val2;
    //
     *msb = value;
     value = val3;
    value = (value << 8) + val4;
     *lsb = value;
    
#else
    value= val2;
    value = val1 + ( value << 8 );
    *msb = value;
     value= val4;
    value = val3 + ( value << 8 );
     *lsb = value;
    
#endif
  
 
    
           
 
}

unsigned char write_switch_reg16 ( unsigned short reg_adr, unsigned short val )
{
    SPI_MESSAGE msg;
    int i =0;
    unsigned char value;
    //unsigned char dataOut[5];
    msg.cmd = SPI_WRITE << 5;
    msg.a0_a2   = ( unsigned char ) ((reg_adr & 0x7) << SPI_TURNAROUND_SHIFT);
    msg.a3_a10  = ( unsigned char ) ((reg_adr >> 3) & 0xFF);
    msg.a11_a16 = ( unsigned char ) ((reg_adr >> 11) & 0xFF);
 
#ifdef SWAP_16   
    msg.data = (val >> 8) & 0xFF ;
    msg.data1 = val &0xFF;
#else
      msg.data = (val & 0xFF ) ;
    msg.data1 = (( val >> 8 ) & 0xFF );
#endif

    spiMessage_U msgU;
    msgU.Message_T =msg;

    SPI1_CHIP_SEL_SetLow();
    
    for ( i=0; i < 6; i++ ) 
    {
        value = SPI1_ExchangeByte(msgU.P[i]);
    }
 
    SPI1_CHIP_SEL_SetHigh(); 
 
    return 0;

}
//
//
void write_mmd_device(unsigned short port, unsigned char device, 
        unsigned short regoffset, unsigned value)
{
    unsigned char tmp;
    MMDST  data_s;

    unsigned short portmmdsetup = MMD_SETUP |  (port << 12);
    unsigned short portmmddata  = MMD_DATA  |  (port << 12);
    // Write device id to setup
    
    data_s.dev = device;
    data_s.op= 0;
    MMDST_U mmstu;
    mmstu.regS=data_s;
    

    tmp = write_switch_reg16 ( portmmdsetup, mmstu.reg16);

     // 
    tmp = write_switch_reg16 ( portmmdsetup, regoffset);

    //
    data_s.op= 0x40;
      
    tmp = write_switch_reg16 ( portmmdsetup, mmstu.reg16);

    tmp = write_switch_reg16(portmmddata, value);

}   


unsigned short read_mmd_device(unsigned short port, unsigned char device, 
        unsigned short regoffset)
{
    unsigned char tmp;
    MMDST  data_s;
    unsigned short val1=0,val2=0;

    unsigned short portmmdsetup = MMD_SETUP |  (port << 12);
    unsigned short portmmddata  = MMD_DATA  |  (port << 12);
    // Write device id to setup
    
    data_s.dev = device;
    data_s.op= 0;
   MMDST_U mmstu;
    mmstu.regS=data_s;
    

    tmp = write_switch_reg16 ( portmmdsetup, mmstu.reg16);
    tmp = write_switch_reg16 ( portmmdsetup, regoffset);
    //
    data_s.op= 0x40;
 
    tmp = write_switch_reg16 ( portmmdsetup, mmstu.reg16);

  
    val1 =  read_switch_reg16(portmmddata);

       
    return ( val1 + (val2 << 8));
      //
}

unsigned short  configure_switch()
{
    unsigned short port;
    int  cfgIndex;
    unsigned short rvalue;
    unsigned short error = 0;
    unsigned char  spiReg ;
    
    for (port = 1; port <=5; port ++ ) 
    {
        
        for (cfgIndex=0; cfgIndex < SW_MAX_CFG  ; cfgIndex++)
        {
            write_mmd_device(port, 
                    SW_CONFIG[cfgIndex].device, 
                    SW_CONFIG[cfgIndex].regoffset , 
                    SW_CONFIG[cfgIndex].val);
            //
            rvalue = read_mmd_device(port, 
                    SW_CONFIG[cfgIndex].device, 
                    SW_CONFIG[cfgIndex].regoffset);

            if ( rvalue != SW_CONFIG[cfgIndex].val )
            {
                error++;
            }
                       
                
        }
    
    }
    
#ifdef MOD_3  
      spiReg = read_switch_reg (0x6301 );
      // Set Bit 4 --- 0x10
      spiReg |= 0x10;
      write_switch_reg ( 0x6301 , spiReg );
      //
#endif
      
#ifdef Module_10      
      
     spiReg  =  write_switch_reg16 ( 0x03C0 , 0x4090 );
     spiReg  =  write_switch_reg16 ( 0x03C2 , 0x0080 );
     spiReg  =  write_switch_reg16 ( 0x03C4 , 0x2000 );
     
#endif      
    return error;
}


void resetPort( int port, bool hardReset) 
{
   unsigned short phyCR = (unsigned short) (0x0100 |  (port << 12));
   unsigned short reg16, cr;
   
   printf("!!!!! Resetting port %d  !!!!!\n", port);
   cr = reg16 =  read_switch_reg16(phyCR);
   reg16 |= 0x8000;
   if (hardReset) {
    reg16 |= 0x0800;
   }
   write_switch_reg16 ( phyCR,reg16);
     __delay_ms(1000); 
   write_switch_reg16 ( phyCR,cr);
    __delay_ms(1000); 
   
}

bool getPortLink(int port )
{
    bool linkup = false;
    unsigned short phyCR = (unsigned short) (0x0102 |  (port << 12));
     unsigned short reg16;

    reg16 =  read_switch_reg16(phyCR);
    if (reg16 & 0x0004) {
       linkup = true;
    }
   // printf(" Port %d is %s \n", port, linkup==true? "UP" :"Down");
    return linkup ;
}

bool isAnyLinkUp(int *nbPort)
{
    int port;
    int nb = 0;
 
    bool anyLinkUp = false;
    for (port =1; port <5; port ++) 
    {
       if( getPortLink(port)) 
       {
           nb++;
         anyLinkUp = true;  
       }
    }
    *nbPort= nb;
    return (anyLinkUp);
}

unsigned short getPortReg( int port ,  unsigned short reg)
{
     unsigned short phyreg = (unsigned short) (reg | (unsigned short)( (port << 12)) );
     unsigned short reg16;
     reg16 =  read_switch_reg16(phyreg);
     return reg16;
}

unsigned short getPhyBaseReg( int port )
{
    return (getPortReg( port ,  0x0100));
   
}

unsigned short getPhyStatusReg( int port )
{
     return (getPortReg( port ,  0x0102));
   
}

unsigned short get1000baseTPhy( int port )
{
     return (getPortReg( port ,  0x0112));
   
}


void configclock( bool enableClkPin, bool clk25M) 
{
   unsigned short regOffset = 0x0103;
   unsigned char  regval = 0;
   regval = read_switch_reg (regOffset );
   
   regval= 0;
   if (!clk25M) { regval |= 0x01; }
   if (enableClkPin) {  regval |= 0x02; }
}

void disableAuto( int port,  bool isGig) 
{
   unsigned short phyCR = (unsigned short) (0x0100 |  (port << 12));
   unsigned short reg16;
   
   printf("!!!!! Disabling Auto negotiation for  port %d  !!!!!\n", port);
   if (isGig) {
       reg16 = 0x0140;
   }
   else {
          reg16 = 0x2100;
   }
   write_switch_reg16 ( phyCR,reg16);
   
}

void regdump( ) 
{
 
  unsigned short lsb, msb, reg16;
   
 
  read_switch_reg32 ( 0x0120, &msb, &lsb );
  printf("LED override (0x0120)--> msb=0x%x  -- lsb= 0x%x \n",msb, lsb);
 //
   read_switch_reg32 ( 0x0210, &msb, &lsb );
  printf("LED conf strap (0x210)---> msb=0x%x  -- lsb= 0x%x \n",msb, lsb);
 
   
}

void getPortStatus(int port)
{

     unsigned short phyreg = (unsigned short) (0x0030 | (unsigned short) ( (port << 12)));
     unsigned short reg8;
     reg8 =  read_switch_reg(phyreg);
     printf("port %d -- ", port );
     if (reg8 &0x04) {
             printf("Full Duplex --" );
     } else {
         printf("Half Duplex --" );
     }
     reg8 = reg8 >> 3 & 0x3;
     if (reg8 == 0 )     printf("10Mb/s" );
     if (reg8 == 1 )     printf("100Mb/s" );
     if (reg8 == 2 )     printf("1000Mb/s" );
      printf("\n" );
}

void disable1000BaseT(unsigned short  port)
{
    unsigned short regAddr = (unsigned short) (0x0112 |  (port << 12));
    unsigned short reg16 = read_switch_reg16 ( regAddr );
    reg16 &=  ~DISABLE_1000BASE_T;
    write_switch_reg16 ( regAddr , reg16);
}