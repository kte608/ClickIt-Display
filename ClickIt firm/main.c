 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
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
#include "mcc_generated_files/system/system.h"
#include "setLEDs.h"
#include <stdint.h>

#define WAIT_TIME 500
#define FLASH_TIME 2   // 5 works but 2 is better
/*
    Main application
*/

void littleBlink()
{
  __delay_ms(WAIT_TIME);
    __delay_ms(WAIT_TIME);
    DP_PIN_Set();
    CA4_PIN_Set();
    __delay_ms(WAIT_TIME);
    __delay_ms(WAIT_TIME);
    DP_PIN_Clear();
    CA4_PIN_Clear();
    __delay_ms(WAIT_TIME);
    __delay_ms(WAIT_TIME);
    DP_PIN_Clear();
    CA4_PIN_Set();
    __delay_ms(WAIT_TIME);
    __delay_ms(WAIT_TIME);
    DP_PIN_Clear();
    CA4_PIN_Set();  
}

void roconBlink()
{
    __delay_ms(WAIT_TIME);
    __delay_ms(WAIT_TIME);
    setRCON();
    CA1_PIN_Clear();
    __delay_ms(WAIT_TIME);
    __delay_ms(WAIT_TIME);
    
    CA1_PIN_Set();

}

#define DISPLAY_BUF_LEN 5
uint8_t displayPointer=0;
uint8_t displayArray[DISPLAY_BUF_LEN]={0b11110011,0,'8','0','0'};
uint8_t receiveArray[DISPLAY_BUF_LEN]={0b11110011,0,'8','0','0'};
uint8_t newDisplayData=0;
static bool I2C1_DisplayCallback(i2c_client_transfer_event_t event)
{
    bool result = false;
    uint16_t i2cAddr;
    /* User has to register own callback. Refer example code */
    switch(event)
    {
        case I2C_CLIENT_TRANSFER_EVENT_ADDR_MATCH:
            i2cAddr = I2C1_ReadAddr();
            if(i2cAddr == 0x05)
            {
                displayPointer=0;
                result = true;
            }
            break;
        case I2C_CLIENT_TRANSFER_EVENT_STOP_BIT_RECEIVED:
            displayPointer=0;
            break;
        case I2C_CLIENT_TRANSFER_EVENT_RX_READY:
            receiveArray[displayPointer]=I2C1_ReadByte();
            displayPointer=(displayPointer+1);
            newDisplayData=displayPointer;    
            displayPointer=displayPointer%DISPLAY_BUF_LEN;
            break;
        case I2C_CLIENT_TRANSFER_EVENT_TX_READY:
            I2C1_WriteByte(displayArray[displayPointer]);
            displayPointer=(displayPointer+1)%DISPLAY_BUF_LEN;            
            break;
    }
    return result;
}


void setI2C_ADDR(uint8_t addr)
{
    SSPADD = addr<<1; 
    SSPMSK = 0xFF;
}


// For I2C support, see https://github.com/microchip-pic-avr-examples/pic16f15244-uart-i2c-bridge-i2c-client1-mplab-mcc

int main(void)
{
    uint8_t i;
    
    SYSTEM_Initialize();
    setI2C_ADDR(0x9);               // Change the address here to whatever you want!
    clearAll();
    //roconBlink();
    uint8_t decimals;
    uint8_t decimalMask;
    
    
    
    I2C1_CallbackRegister(I2C1_DisplayCallback);
    
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

   
    
    clearAll();
    
    for(;;)
    {
        if(newDisplayData!=0)
        {
            for(i=0;i<newDisplayData;i++)
            {
                displayArray[i]=receiveArray[i];
            }
            newDisplayData=0;
            
        }
        set_character(displayArray[0],0,0);
        __delay_ms(FLASH_TIME);
        decimals=displayArray[0]>>4;
        for(i=1;i<DISPLAY_BUF_LEN;i++)
        {
            set_character(displayArray[i],decimals&(1<<(4-i)),i);
            __delay_ms(FLASH_TIME);
        }
        /*set_character(0b0011,0,0);    // Lights
        __delay_ms(FLASH_TIME);
        set_character(0,0,1);
        __delay_ms(FLASH_TIME);
        set_character('7',0,2);
        __delay_ms(FLASH_TIME);
        set_character('5',0,3);
        __delay_ms(FLASH_TIME);
        set_character('3',0,4);
        __delay_ms(FLASH_TIME);*/
    }
    
   
    
}