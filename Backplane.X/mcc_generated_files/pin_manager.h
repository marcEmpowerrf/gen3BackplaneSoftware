/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18LF47K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SPI1_CHIP_SEL aliases
#define SPI1_CHIP_SEL_TRIS                 TRISAbits.TRISA5
#define SPI1_CHIP_SEL_LAT                  LATAbits.LATA5
#define SPI1_CHIP_SEL_PORT                 PORTAbits.RA5
#define SPI1_CHIP_SEL_WPU                  WPUAbits.WPUA5
#define SPI1_CHIP_SEL_OD                   ODCONAbits.ODCA5
#define SPI1_CHIP_SEL_ANS                  ANSELAbits.ANSELA5
#define SPI1_CHIP_SEL_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SPI1_CHIP_SEL_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SPI1_CHIP_SEL_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SPI1_CHIP_SEL_GetValue()           PORTAbits.RA5
#define SPI1_CHIP_SEL_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SPI1_CHIP_SEL_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SPI1_CHIP_SEL_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SPI1_CHIP_SEL_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SPI1_CHIP_SEL_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SPI1_CHIP_SEL_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SPI1_CHIP_SEL_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define SPI1_CHIP_SEL_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RESET_DEV aliases
#define RESET_DEV_TRIS                 TRISCbits.TRISC0
#define RESET_DEV_LAT                  LATCbits.LATC0
#define RESET_DEV_PORT                 PORTCbits.RC0
#define RESET_DEV_WPU                  WPUCbits.WPUC0
#define RESET_DEV_OD                   ODCONCbits.ODCC0
#define RESET_DEV_ANS                  ANSELCbits.ANSELC0
#define RESET_DEV_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RESET_DEV_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RESET_DEV_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RESET_DEV_GetValue()           PORTCbits.RC0
#define RESET_DEV_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RESET_DEV_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RESET_DEV_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define RESET_DEV_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define RESET_DEV_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define RESET_DEV_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define RESET_DEV_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RESET_DEV_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set RED_LED aliases
#define RED_LED_TRIS                 TRISDbits.TRISD1
#define RED_LED_LAT                  LATDbits.LATD1
#define RED_LED_PORT                 PORTDbits.RD1
#define RED_LED_WPU                  WPUDbits.WPUD1
#define RED_LED_OD                   ODCONDbits.ODCD1
#define RED_LED_ANS                  ANSELDbits.ANSELD1
#define RED_LED_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RED_LED_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RED_LED_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RED_LED_GetValue()           PORTDbits.RD1
#define RED_LED_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RED_LED_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RED_LED_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define RED_LED_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define RED_LED_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define RED_LED_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define RED_LED_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define RED_LED_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set GREEN_LED aliases
#define GREEN_LED_TRIS                 TRISDbits.TRISD2
#define GREEN_LED_LAT                  LATDbits.LATD2
#define GREEN_LED_PORT                 PORTDbits.RD2
#define GREEN_LED_WPU                  WPUDbits.WPUD2
#define GREEN_LED_OD                   ODCONDbits.ODCD2
#define GREEN_LED_ANS                  ANSELDbits.ANSELD2
#define GREEN_LED_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define GREEN_LED_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define GREEN_LED_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define GREEN_LED_GetValue()           PORTDbits.RD2
#define GREEN_LED_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define GREEN_LED_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define GREEN_LED_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define GREEN_LED_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define GREEN_LED_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define GREEN_LED_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define GREEN_LED_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define GREEN_LED_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set BLUE_LED aliases
#define BLUE_LED_TRIS                 TRISDbits.TRISD3
#define BLUE_LED_LAT                  LATDbits.LATD3
#define BLUE_LED_PORT                 PORTDbits.RD3
#define BLUE_LED_WPU                  WPUDbits.WPUD3
#define BLUE_LED_OD                   ODCONDbits.ODCD3
#define BLUE_LED_ANS                  ANSELDbits.ANSELD3
#define BLUE_LED_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define BLUE_LED_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define BLUE_LED_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define BLUE_LED_GetValue()           PORTDbits.RD3
#define BLUE_LED_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define BLUE_LED_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define BLUE_LED_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define BLUE_LED_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define BLUE_LED_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define BLUE_LED_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define BLUE_LED_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define BLUE_LED_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/