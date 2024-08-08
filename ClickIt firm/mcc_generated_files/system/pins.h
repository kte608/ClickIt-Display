/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 aliases
#define CA1_PIN_TRIS                 TRISAbits.TRISA2
#define CA1_PIN_LAT                  LATAbits.LATA2
#define CA1_PIN_PORT                 PORTAbits.RA2
#define CA1_PIN_WPU                  WPUAbits.WPUA2
#define CA1_PIN_OD                   ODCONAbits.
#define CA1_PIN_ANS                  ANSELAbits.ANS2
#define CA1_PIN_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define CA1_PIN_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define CA1_PIN_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define CA1_PIN_GetValue()           PORTAbits.RA2
#define CA1_PIN_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define CA1_PIN_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define CA1_PIN_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define CA1_PIN_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define CA1_PIN_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define CA1_PIN_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define CA1_PIN_SetAnalogMode()      do { ANSELAbits.ANS2 = 1; } while(0)
#define CA1_PIN_SetDigitalMode()     do { ANSELAbits.ANS2 = 0; } while(0)

// get/set RA4 aliases
#define F_PIN_TRIS                 TRISAbits.TRISA4
#define F_PIN_LAT                  LATAbits.LATA4
#define F_PIN_PORT                 PORTAbits.RA4
#define F_PIN_WPU                  WPUAbits.WPUA4
#define F_PIN_OD                   ODCONAbits.
#define F_PIN_ANS                  ANSELAbits.ANS3
#define F_PIN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define F_PIN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define F_PIN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define F_PIN_GetValue()           PORTAbits.RA4
#define F_PIN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define F_PIN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define F_PIN_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define F_PIN_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define F_PIN_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define F_PIN_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define F_PIN_SetAnalogMode()      do { ANSELAbits.ANS3 = 1; } while(0)
#define F_PIN_SetDigitalMode()     do { ANSELAbits.ANS3 = 0; } while(0)

// get/set RA5 aliases
#define DP_PIN_TRIS                 TRISAbits.TRISA5
#define DP_PIN_LAT                  LATAbits.LATA5
#define DP_PIN_PORT                 PORTAbits.RA5
#define DP_PIN_WPU                  WPUAbits.WPUA5
#define DP_PIN_OD                   ODCONAbits.
#define DP_PIN_ANS                  ANSELAbits.
#define DP_PIN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define DP_PIN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define DP_PIN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define DP_PIN_GetValue()           PORTAbits.RA5
#define DP_PIN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define DP_PIN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define DP_PIN_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define DP_PIN_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define DP_PIN_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define DP_PIN_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define DP_PIN_SetAnalogMode()      do { ANSELAbits. = 1; } while(0)
#define DP_PIN_SetDigitalMode()     do { ANSELAbits. = 0; } while(0)

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.
#define IO_RB4_ANS                  ANSELBbits.ANS10
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANS10 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANS10 = 0; } while(0)

// get/set RB5 aliases
#define C_PIN_TRIS                 TRISBbits.TRISB5
#define C_PIN_LAT                  LATBbits.LATB5
#define C_PIN_PORT                 PORTBbits.RB5
#define C_PIN_WPU                  WPUBbits.WPUB5
#define C_PIN_OD                   ODCONBbits.
#define C_PIN_ANS                  ANSELBbits.ANS11
#define C_PIN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define C_PIN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define C_PIN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define C_PIN_GetValue()           PORTBbits.RB5
#define C_PIN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define C_PIN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define C_PIN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define C_PIN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define C_PIN_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define C_PIN_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)
#define C_PIN_SetAnalogMode()      do { ANSELBbits.ANS11 = 1; } while(0)
#define C_PIN_SetDigitalMode()     do { ANSELBbits.ANS11 = 0; } while(0)

// get/set RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.
#define IO_RB6_ANS                  ANSELBbits.
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits. = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits. = 0; } while(0)

// get/set RB7 aliases
#define CA4_PIN_TRIS                 TRISBbits.TRISB7
#define CA4_PIN_LAT                  LATBbits.LATB7
#define CA4_PIN_PORT                 PORTBbits.RB7
#define CA4_PIN_WPU                  WPUBbits.WPUB7
#define CA4_PIN_OD                   ODCONBbits.
#define CA4_PIN_ANS                  ANSELBbits.
#define CA4_PIN_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define CA4_PIN_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define CA4_PIN_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define CA4_PIN_GetValue()           PORTBbits.RB7
#define CA4_PIN_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define CA4_PIN_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define CA4_PIN_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define CA4_PIN_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define CA4_PIN_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define CA4_PIN_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)
#define CA4_PIN_SetAnalogMode()      do { ANSELBbits. = 1; } while(0)
#define CA4_PIN_SetDigitalMode()     do { ANSELBbits. = 0; } while(0)

// get/set RC0 aliases
#define B_PIN_TRIS                 TRISCbits.TRISC0
#define B_PIN_LAT                  LATCbits.LATC0
#define B_PIN_PORT                 PORTCbits.RC0
#define B_PIN_WPU                  WPUCbits.
#define B_PIN_OD                   ODCONCbits.
#define B_PIN_ANS                  ANSELCbits.ANS4
#define B_PIN_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define B_PIN_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define B_PIN_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define B_PIN_GetValue()           PORTCbits.RC0
#define B_PIN_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define B_PIN_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define B_PIN_SetPullup()          do { WPUCbits. = 1; } while(0)
#define B_PIN_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define B_PIN_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define B_PIN_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define B_PIN_SetAnalogMode()      do { ANSELCbits.ANS4 = 1; } while(0)
#define B_PIN_SetDigitalMode()     do { ANSELCbits.ANS4 = 0; } while(0)

// get/set RC1 aliases
#define G_PIN_TRIS                 TRISCbits.TRISC1
#define G_PIN_LAT                  LATCbits.LATC1
#define G_PIN_PORT                 PORTCbits.RC1
#define G_PIN_WPU                  WPUCbits.
#define G_PIN_OD                   ODCONCbits.
#define G_PIN_ANS                  ANSELCbits.ANS5
#define G_PIN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define G_PIN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define G_PIN_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define G_PIN_GetValue()           PORTCbits.RC1
#define G_PIN_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define G_PIN_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define G_PIN_SetPullup()          do { WPUCbits. = 1; } while(0)
#define G_PIN_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define G_PIN_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define G_PIN_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define G_PIN_SetAnalogMode()      do { ANSELCbits.ANS5 = 1; } while(0)
#define G_PIN_SetDigitalMode()     do { ANSELCbits.ANS5 = 0; } while(0)

// get/set RC2 aliases
#define A_PIN_TRIS                 TRISCbits.TRISC2
#define A_PIN_LAT                  LATCbits.LATC2
#define A_PIN_PORT                 PORTCbits.RC2
#define A_PIN_WPU                  WPUCbits.
#define A_PIN_OD                   ODCONCbits.
#define A_PIN_ANS                  ANSELCbits.ANS6
#define A_PIN_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define A_PIN_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define A_PIN_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define A_PIN_GetValue()           PORTCbits.RC2
#define A_PIN_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define A_PIN_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define A_PIN_SetPullup()          do { WPUCbits. = 1; } while(0)
#define A_PIN_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define A_PIN_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define A_PIN_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define A_PIN_SetAnalogMode()      do { ANSELCbits.ANS6 = 1; } while(0)
#define A_PIN_SetDigitalMode()     do { ANSELCbits.ANS6 = 0; } while(0)



// get/set RC3 aliases
#define CAL_PIN_TRIS                 TRISCbits.TRISC3
#define CAL_PIN_LAT                  LATCbits.LATC3
#define CAL_PIN_PORT                 PORTCbits.RC3
#define CAL_PIN_WPU                  WPUCbits.
#define CAL_PIN_OD                   ODCONCbits.
#define CAL_PIN_ANS                  ANSELCbits.ANS7
#define CAL_PIN_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define CAL_PIN_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define CAL_PIN_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define CAL_PIN_GetValue()           PORTCbits.RC3
#define CAL_PIN_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define CAL_PIN_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define CAL_PIN_SetPullup()          do { WPUCbits. = 1; } while(0)
#define CAL_PIN_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define CAL_PIN_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define CAL_PIN_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define CAL_PIN_SetAnalogMode()      do { ANSELCbits.ANS7 = 1; } while(0)
#define CAL_PIN_SetDigitalMode()     do { ANSELCbits.ANS7 = 0; } while(0)

// get/set RC4 aliases
#define D_PIN_TRIS                 TRISCbits.TRISC4
#define D_PIN_LAT                  LATCbits.LATC4
#define D_PIN_PORT                 PORTCbits.RC4
#define D_PIN_WPU                  WPUCbits.
#define D_PIN_OD                   ODCONCbits.
#define D_PIN_ANS                  ANSELCbits.
#define D_PIN_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define D_PIN_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define D_PIN_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define D_PIN_GetValue()           PORTCbits.RC4
#define D_PIN_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define D_PIN_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define D_PIN_SetPullup()          do { WPUCbits. = 1; } while(0)
#define D_PIN_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define D_PIN_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define D_PIN_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define D_PIN_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define D_PIN_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

// get/set RC5 aliases
#define E_PIN_TRIS                 TRISCbits.TRISC5
#define E_PIN_LAT                  LATCbits.LATC5
#define E_PIN_PORT                 PORTCbits.RC5
#define E_PIN_WPU                  WPUCbits.
#define E_PIN_OD                   ODCONCbits.
#define E_PIN_ANS                  ANSELCbits.
#define E_PIN_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define E_PIN_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define E_PIN_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define E_PIN_GetValue()           PORTCbits.RC5
#define E_PIN_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define E_PIN_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define E_PIN_SetPullup()          do { WPUCbits. = 1; } while(0)
#define E_PIN_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define E_PIN_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define E_PIN_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define E_PIN_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define E_PIN_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

// get/set RC6 aliases
#define CA2_PIN_TRIS                 TRISCbits.TRISC6
#define CA2_PIN_LAT                  LATCbits.LATC6
#define CA2_PIN_PORT                 PORTCbits.RC6
#define CA2_PIN_WPU                  WPUCbits.
#define CA2_PIN_OD                   ODCONCbits.
#define CA2_PIN_ANS                  ANSELCbits.ANS8
#define CA2_PIN_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define CA2_PIN_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define CA2_PIN_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define CA2_PIN_GetValue()           PORTCbits.RC6
#define CA2_PIN_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define CA2_PIN_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define CA2_PIN_SetPullup()          do { WPUCbits. = 1; } while(0)
#define CA2_PIN_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define CA2_PIN_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define CA2_PIN_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define CA2_PIN_SetAnalogMode()      do { ANSELCbits.ANS8 = 1; } while(0)
#define CA2_PIN_SetDigitalMode()     do { ANSELCbits.ANS8 = 0; } while(0)

// get/set RC7 aliases
#define CA3_PIN_TRIS                 TRISCbits.TRISC7
#define CA3_PIN_LAT                  LATCbits.LATC7
#define CA3_PIN_PORT                 PORTCbits.RC7
#define CA3_PIN_WPU                  WPUCbits.
#define CA3_PIN_OD                   ODCONCbits.
#define CA3_PIN_ANS                  ANSELCbits.ANS9
#define CA3_PIN_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define CA3_PIN_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define CA3_PIN_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define CA3_PIN_GetValue()           PORTCbits.RC7
#define CA3_PIN_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define CA3_PIN_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define CA3_PIN_SetPullup()          do { WPUCbits. = 1; } while(0)
#define CA3_PIN_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define CA3_PIN_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define CA3_PIN_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define CA3_PIN_SetAnalogMode()      do { ANSELCbits.ANS9 = 1; } while(0)
#define CA3_PIN_SetDigitalMode()     do { ANSELCbits.ANS9 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/