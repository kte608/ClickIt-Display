/**
 * MSSP Generated Driver File
 *
 * @file mssp.c
 *
 * @ingroup I2C_client
 *
 * @brief This file contains the driver code for I2C1 module.
 *
 * @version I2C1 Driver Version 2.1.0
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

#include <xc.h>
#include "../mssp.h"
#define NULL 0
/**
  Section: Driver Interface
 */
struct I2C_CLIENT_INTERFACE I2C1_Client; 

/**
 Section: Private functions declaration
 */
static void I2C1_EventHandler();
static void I2C1_ErrorEventHandler();
static bool I2C1_DefaultCallback(i2c_client_transfer_event_t event);

/**
 Section: Private Variable Definitions
 */
static volatile uint16_t i2c1Addr;
static volatile i2c_client_error_t i2c1ErrorState;
static bool(*I2C1_InterruptHandler)(i2c_client_transfer_event_t clientEvent) = NULL;

/**
 Section: Public functions
 */
void I2C1_Initialize(void)
{
    I2C1_Client.Initialize = I2C1_Initialize;                                 
    I2C1_Client.Deinitialize = I2C1_Deinitialize;
    I2C1_Client.WriteByte = I2C1_WriteByte;
    I2C1_Client.ReadByte = I2C1_ReadByte;
    I2C1_Client.TransferDirGet = I2C1_TransferDirGet;
    I2C1_Client.LastByteAckStatusGet = I2C1_LastByteAckStatusGet;
    I2C1_Client.ErrorGet = I2C1_ErrorGet;
    I2C1_Client.CallbackRegister = I2C1_CallbackRegister;
    I2C1_Client.Tasks = NULL;

    
    
    /* BF RCinprocess_TXcomplete; UA dontupdate; R_nW undefined; S startbit_notdetected; P stopbit_notdetected; D_nA undefined; CKE disabled; SMP Standard Speed;  */
    SSPSTAT = 0xA4;
    /* SSPM 7 Bit Polling; CKP disabled; SSPEN disabled; SSPOV no_overflow; WCOL no_collision;  */
    SSPCON1 |= 0x6;
    /* SEN enabled; RSEN disabled; PEN disabled; RCEN disabled; ACKEN disabled; ACKDT acknowledge; ACKSTAT received; GCEN disabled;  */
    SSPCON2 = 0x1;
    /* SSPADD 10;  */
    SSPADD = 0xA;
    /* SSPMSK 0;  */
    SSPMSK = 0x0;
    /* Enable Interrupts */
    PIE1bits.SSPIE = 1;
    PIE2bits.BCLIE = 1;
    I2C1_CallbackRegister(I2C1_DefaultCallback);
    SSPCON1bits.SSPEN = 1;
}

void I2C1_Deinitialize(void)
{
    SSPSTAT = 0x00;
    SSPCON1 |= 0x00;
    SSPCON2 = 0x00;
    SSPADD = 0x08;
    SSPMSK = 0x0;
    /* Disable Interrupts */
    PIE1bits.SSPIE = 0;
    PIE2bits.BCLIE = 0;
    I2C1_CallbackRegister(I2C1_DefaultCallback);
}

void I2C1_WriteByte(uint8_t data)
{
    SSPBUF = data;
}

uint8_t I2C1_ReadByte(void)
{
    return SSPBUF;
}

uint16_t I2C1_ReadAddr(void)
{
    return (i2c1Addr >> 1);
}

i2c_client_error_t I2C1_ErrorGet(void)
{
    i2c_client_error_t error;
    error = i2c1ErrorState;
    i2c1ErrorState = I2C_CLIENT_ERROR_NONE;
    return error;
}

i2c_client_transfer_dir_t I2C1_TransferDirGet(void)
{
    return (SSPSTATbits.R_nW ? I2C_CLIENT_TRANSFER_DIR_READ : I2C_CLIENT_TRANSFER_DIR_WRITE);
}

i2c_client_ack_status_t I2C1_LastByteAckStatusGet(void)
{
    return (SSPCON2bits.ACKDT ? I2C_CLIENT_ACK_STATUS_RECEIVED_NACK : I2C_CLIENT_ACK_STATUS_RECEIVED_ACK);
}

void I2C1_CallbackRegister(bool(*callback)(i2c_client_transfer_event_t clientEvent))
{
    if (callback != NULL)
    {
        I2C1_InterruptHandler = callback;
    }
}

void I2C1_ISR(void)
{
    I2C1_EventHandler();
}

void I2C1_ERROR_ISR(void)
{
    I2C1_ErrorEventHandler();
}

/**
 Section: Private functions
 */
static void I2C1_EventHandler(void)
{
    PIR1bits.SSPIF = 0;
    if (SSPSTATbits.P)
    {
        /* Notify that a stop event has occurred */
        I2C1_InterruptHandler(I2C_CLIENT_TRANSFER_EVENT_STOP_BIT_RECEIVED);
    }
    else if (!SSPSTATbits.D_nA)
    {
        /* Received I2C address must be read out */
        i2c1Addr = I2C1_ReadByte();
        /* Clear Software Error State */
        i2c1ErrorState = I2C_CLIENT_ERROR_NONE;
        /* Notify that a address match event has occurred */
        if (I2C1_InterruptHandler(I2C_CLIENT_TRANSFER_EVENT_ADDR_MATCH) == true)
        {
            /* I2C host wants to read */
            if (SSPSTATbits.R_nW)
            {
                if (!SSPSTATbits.BF)
                {
                    /* In the callback, client must write to transmit register by calling I2Cx_WriteByte() */
                    if (I2C1_InterruptHandler(I2C_CLIENT_TRANSFER_EVENT_TX_READY) == false)
                    {
                        /* Send NACK */
                        SSPCON2bits.ACKDT = 1;
                        SSPCON2bits.ACKEN = 1;
                    }
                }
            }

            /* Send ACK */
            SSPCON2bits.ACKDT = 0;
            SSPCON2bits.ACKEN = 1;
        }
        else
        {
            /* Send NACK */
            SSPCON2bits.ACKDT = 1;
            SSPCON2bits.ACKEN = 1;
        }
    }
    else
    {
        /* Host reads from client, client transmits */
        if (SSPSTATbits.R_nW)
        {
            if ((!SSPSTATbits.BF) && (!SSPCON2bits.ACKDT))
            {
                /* I2C host wants to read. In the callback, client must write to transmit register */
                if (I2C1_InterruptHandler(I2C_CLIENT_TRANSFER_EVENT_TX_READY) == false)
                {
                    /* Send NACK */
                    SSPCON2bits.ACKDT = 1;
                    SSPCON2bits.ACKEN = 1;
                }
            }
        }
        else
        {
            if (SSPSTATbits.BF)
            {
                /* I2C host wants to write. In the callback, client must read data by calling I2Cx_ReadByte()  */
                if (I2C1_InterruptHandler(I2C_CLIENT_TRANSFER_EVENT_RX_READY) == true)
                {
                    /* Send ACK */
                    SSPCON2bits.ACKDT = 0;
                    SSPCON2bits.ACKEN = 1;
                }
                else
                {
                    /* Send NACK */
                    SSPCON2bits.ACKDT = 1;
                    SSPCON2bits.ACKEN = 1;
                }
            }
        }
    }

    /* Data written by the application; release the clock stretch */
    SSPCON1bits.CKP = 1;
}

static void I2C1_ErrorEventHandler(void)
{
    if (PIR2bits.BCLIF)
    {
        i2c1ErrorState = I2C_CLIENT_ERROR_BUS_COLLISION;
        I2C1_InterruptHandler(I2C_CLIENT_TRANSFER_EVENT_ERROR);
        PIR2bits.BCLIF = 0; /* Clear the Bus collision */
    }
    else if (SSPCON1bits.WCOL)
    {
        i2c1ErrorState = I2C_CLIENT_ERROR_WRITE_COLLISION;
        I2C1_InterruptHandler(I2C_CLIENT_TRANSFER_EVENT_ERROR);
        SSPCON1bits.WCOL = 0; /* Clear the Write collision */
    }
    /* Data written by the application; release the clock stretch */
    SSPCON1bits.CKP = 1;
}

static bool I2C1_DefaultCallback(i2c_client_transfer_event_t event)
{
    /* User has to register own callback. Refer example code */
    return false;
}