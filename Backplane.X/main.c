/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18LF47K42
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "../Backplane.X/Switch/EtherenetSwitch.h"
#include "../Backplane.X/spi_util/spi_util.h"

/*
                         Main application
 */

//#define RESET_SWITCH_PHYS
//#define CONFIGURE_SWITCH
//#define RESET_CHIP
 //#define RESET_SWITCH
//#define RESET_SWITCH_PORT 
//#define Force_100
//#define Force_1GB
#define TOGGLE_LED
#define TOGGLE_LED_COUNT 5

#define DISABLE_1000BASE_T ( ( unsigned short) 0x0300 )

void setLedGreen( bool on)
{
    if (on)
    {
      GREEN_LED_SetLow();
    }
    else
    {
     GREEN_LED_SetHigh();   
    }
}

void setLedRed( bool on)
{
    if (on)
    {
      RED_LED_SetLow();
    }
    else
    {
     RED_LED_SetHigh();   
    }
}

void setLedBlue( bool on)
{
    if (on)
    {
      BLUE_LED_SetLow();
    }
    else
    {
     BLUE_LED_SetHigh();   
    }
}

void main(void)
{
    int i=0;
    SPI_MODE mode;
    SPI_MODE bp_Spi_mode;
    unsigned char  spiReg ;
    bool link = false;
    unsigned short port;
    bool resetAll = false, isLink =false;
    unsigned short reg16, regAddr;

#ifdef TOGGLE_LED
    int toggleLedcnt = TOGGLE_LED_COUNT;
    bool solidGreen = false;
#endif
    
    
    
    // Initialize the device
    SYSTEM_Initialize();
    SPI1_CHIP_SEL_SetHigh();
    SPI1_Open(SPI1_DEFAULT);

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();


    //RESET_DEV_SetLow() ;  L:ow by default
   setLedRed(true);
    for (i=0; i<9; i++)
    {
      __delay_ms(1000);      
    }
    RESET_DEV_SetHigh() ; 
    
    setLedRed(false);  
    // Let the switch configure itself.
    
    
#if 0   
    spiReg = read_switch_reg ( 0x010D );
    printf(" Switch register 1: %x \n", spiReg);
    spiReg   |= 0x70;  
    
    write_switch_reg(0x010D, spiReg);
    
      spiReg = read_switch_reg ( 0x010D );
    printf(" Switch register 1: %x \n", spiReg);

    for (port=1; port < 5; port ++)
    {
         regAddr =  port << 12 | 0x0112;
         reg16 = read_switch_reg16 ( regAddr );
        reg16 &=  ~DISABLE_1000BASE_T;
       write_switch_reg16 ( regAddr , reg16);
    }
  #endif

    // Disable 1000BaseT AutoNeg
    for (port=1; port< 5; port++)
    {
        disable1000BaseT(port);
    }
    
    __delay_ms(100);      
    reg16 = read_switch_reg16 ( 0x1112 );
    
    if ( (reg16 != 0xFFFF)  &&(reg16 & DISABLE_1000BASE_T)  ) 
    {
       reg16 &= ~DISABLE_1000BASE_T;
       write_switch_reg16 ( 0x1112,  reg16);
    }
     __delay_ms(100);      
     reg16 = read_switch_reg16 ( 0x2112 );
    if ( (reg16 != 0xFFFF)  &&(reg16 & DISABLE_1000BASE_T)  ) 
    {
      reg16 &= ~DISABLE_1000BASE_T;
       write_switch_reg16 ( 0x2112,  reg16);
    }
      __delay_ms(100);      
     reg16 = read_switch_reg16 ( 0x3112 );
    if ( (reg16 != 0xFFFF)  &&(reg16 & DISABLE_1000BASE_T)  ) 
    {
        reg16 &= ~DISABLE_1000BASE_T;
       write_switch_reg16 ( 0x3112,  reg16);
    }
      __delay_ms(100);      
      reg16 = read_switch_reg16 ( 0x4112 );
    if ( (reg16 != 0xFFFF)  &&(reg16 & DISABLE_1000BASE_T)  ) 
    {
       reg16 &= ~DISABLE_1000BASE_T;
       write_switch_reg16 ( 0x4112,  reg16);;    
    }
    
       
    while (1)
    {
        
 #ifdef TOGGLE_LED
      if (!solidGreen)
      {
         if (toggleLedcnt-- != 0 )
         {
             setLedGreen(true);  
             __delay_ms(1000);  
              setLedGreen(false);
              __delay_ms(1000);  
         } 
         else
         {
            setLedGreen(true);
            solidGreen = true;
         }
      }
      else {
           __delay_ms(1000);  // Let the switch configure itself.
            setLedGreen(true);
           
            reg16 = read_switch_reg16 ( 0x1112 );
            if ( (reg16 != 0xFFFF)  &&(reg16 & DISABLE_1000BASE_T)  ) 
            {
                 reg16 &= ~DISABLE_1000BASE_T;
                write_switch_reg16 ( 0x1112,  reg16);
            }
            
            
      }
#endif
    }
  
#ifdef  CKECK_PORT_STATUS
    spiReg = read_switch_reg ( 0x01 );
    if (spiReg !=  0) 
    {
        printf(" Switch register 1: %x \n", spiReg);
    }
    reg16 = read_switch_reg16 ( 0x01 );
    if (reg16 !=  0) 
    {
        printf(" Switch register 1: %x \n", reg16);
    }
    
#ifdef RESET_SWITCH_PHYS  
    
        do {
            __delay_ms(1000); 
             isLink= isAnyLinkUp(&nport);
        } while (!isLink);
                 
       __delay_ms(2*1000); 
        for (port =1; port < 5; port ++)
        {
            resetPort(port, false);  
        }
#endif
      
//configclock(true, false);        
// write_switch_reg (0x010D, 0x77);

#ifdef CONFIGURE_SWITCH        
      
        printf(" Configuring the switch \n");
        unsigned short err = configure_switch();
        if (err > 0 )
             printf(" Unable to configure the switch \n");
    __delay_ms(1000); 
#endif
 
#ifdef  Force_1GB
    for (port=1; port < 5; port++) {
        //resetPort(port, false);  
        disableAuto( port,  true) ;
        resetPort(port, false);  
    }
#endif
 #ifdef  Force_100
    for (port=1; port < 5; port++) {
         disableAuto( port,  false) ;
         resetPort(port, false);  
    }
    
#endif
    
   printf(" Main Loop \n");
   
   while (1)
    {
         printf("\n=======\n");
        __delay_ms(500);  
        BLUE_LED_SetLow();
       __delay_ms(500);
      //  LCD_CHIP_SEL_SetLow();

        GREEN_LED_SetHigh();
         __delay_ms(500);
        GREEN_LED_SetLow();
             __delay_ms(500);
        BLUE_LED_SetHigh();
        __delay_ms(500);
        BLUE_LED_SetLow();
        
#ifdef  RESET_SWITCH 
        nport = 0;
        link =  isAnyLinkUp(&nport);
        if (link) 
        {
      
            if (!resetAll) {
                 isLink = false;
                   for (port =1; port < 5; port ++)
                   {
                        resetPort(port, false);  
                   }
                 
                   configure_switch();
                 // wait for any Link 
                 do {
                     __delay_ms(1000); 
                   isLink= isAnyLinkUp(&nport);
                 } while (!isLink);
                 
                 resetAll =true;
              
            }
        }
#endif
            //
       
           for (port =1; port < 5; port ++)
           {
               unsigned short phybr, physr, base100Reg;
               phybr = getPhyBaseReg(port);
               physr = getPhyStatusReg(port);
               base100Reg = get1000baseTPhy(port);
               
              // printf(" Port %d -- Phy BCR =%x -- Phy SR=%x  --baseT=%x\n", port, phybr,physr, base100Reg );
               
               if (!getPortLink(port))
               {
                   printf(" Port %d -- Link is down \n", port );
               }
               else
               {
                 printf(" Port %d -- Link is Up \n", port );
               }
           
#ifdef RESET_SWITCH_PORT  
               if ( (!getPortLink(port)) && (isAnyLinkUp(&nport))  )
               {
                   printf(" Port %d -- Link is down  -- Resetting port \n", port );
                   resetPort(port,false);
               }
         
         
#endif
           }
           
          regdump();
         for (port =1; port < 5; port ++)
            getPortStatus(port);

        }
#endif
}
/**
 End of File
*/
