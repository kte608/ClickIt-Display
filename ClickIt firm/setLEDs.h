/* 
 * File:   setLEDs.h
 * Author: karle
 *
 * Created on March 29, 2024, 12:47 PM
 */

#ifndef SETLEDS_H
#define	SETLEDS_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
#define A_PIN_Set()   A_PIN_SetDigitalOutput(); A_PIN_SetHigh()
#define A_PIN_Clear() A_PIN_SetDigitalInput()

#define B_PIN_Set()   B_PIN_SetDigitalOutput(); B_PIN_SetHigh()
#define B_PIN_Clear() B_PIN_SetDigitalInput()

#define C_PIN_Set()   C_PIN_SetDigitalOutput(); C_PIN_SetHigh()
#define C_PIN_Clear() C_PIN_SetDigitalInput()

#define D_PIN_Set()   D_PIN_SetDigitalOutput(); D_PIN_SetHigh()
#define D_PIN_Clear() D_PIN_SetDigitalInput()

#define E_PIN_Set()   E_PIN_SetDigitalOutput(); E_PIN_SetHigh()
#define E_PIN_Clear() E_PIN_SetDigitalInput()

#define F_PIN_Set()   F_PIN_SetDigitalOutput(); F_PIN_SetHigh()
#define F_PIN_Clear() F_PIN_SetDigitalInput()

#define G_PIN_Set()   G_PIN_SetDigitalOutput(); G_PIN_SetHigh()
#define G_PIN_Clear() G_PIN_SetDigitalInput()

#define DP_PIN_Set()   DP_PIN_SetDigitalOutput(); DP_PIN_SetHigh()
#define DP_PIN_Clear() DP_PIN_SetDigitalInput()

#define CA1_PIN_Set()   CA1_PIN_SetDigitalInput()
#define CA1_PIN_Clear() CA1_PIN_SetDigitalOutput(); CA1_PIN_SetLow()

#define CA2_PIN_Set() CA2_PIN_SetDigitalInput()
#define CA2_PIN_Clear() CA2_PIN_SetDigitalOutput(); CA2_PIN_SetLow()

#define CA3_PIN_Set() CA3_PIN_SetDigitalInput()
#define CA3_PIN_Clear() CA3_PIN_SetDigitalOutput(); CA3_PIN_SetLow()

#define CA4_PIN_Set() CA4_PIN_SetDigitalInput()
#define CA4_PIN_Clear() CA4_PIN_SetDigitalOutput(); CA4_PIN_SetLow()

#define CAL_PIN_Set() CAL_PIN_SetDigitalInput()
#define CAL_PIN_Clear() CAL_PIN_SetDigitalOutput(); CAL_PIN_SetLow()
*/
    
    
#define A_PIN_Set()   A_PIN_SetHigh()
#define A_PIN_Clear() A_PIN_SetLow()

#define B_PIN_Set()   B_PIN_SetHigh()
#define B_PIN_Clear() B_PIN_SetLow()

#define C_PIN_Set()   C_PIN_SetHigh()
#define C_PIN_Clear() C_PIN_SetLow()

#define D_PIN_Set()   D_PIN_SetHigh()
#define D_PIN_Clear() D_PIN_SetLow()

#define E_PIN_Set()   E_PIN_SetHigh()
#define E_PIN_Clear() E_PIN_SetLow()

#define F_PIN_Set()   F_PIN_SetHigh()
#define F_PIN_Clear() F_PIN_SetLow()

#define G_PIN_Set()   G_PIN_SetHigh()
#define G_PIN_Clear() G_PIN_SetLow()

#define DP_PIN_Set()  DP_PIN_SetHigh()
#define DP_PIN_Clear() DP_PIN_SetLow()

#define CA1_PIN_Set()   CA1_PIN_SetHigh()
#define CA1_PIN_Clear() CA1_PIN_SetLow()

#define CA2_PIN_Set() CA2_PIN_SetHigh()
#define CA2_PIN_Clear() CA2_PIN_SetLow()

#define CA3_PIN_Set() CA3_PIN_SetHigh()
#define CA3_PIN_Clear() CA3_PIN_SetLow()

#define CA4_PIN_Set() CA4_PIN_SetHigh()
#define CA4_PIN_Clear() CA4_PIN_SetLow()

#define CAL_PIN_Set() CAL_PIN_SetHigh()
#define CAL_PIN_Clear() CAL_PIN_SetLow()
    
#define L1_PIN_SetHigh A_PIN_SetHigh
#define L1_PIN_SetLow A_PIN_SetLow
#define L1_PIN_Set    A_PIN_Set
#define L1_PIN_Clear  A_PIN_Clear

#define L2_PIN_SetHigh B_PIN_SetHigh
#define L2_PIN_SetLow B_PIN_SetLow
#define L2_PIN_Set    B_PIN_Set
#define L2_PIN_Clear  B_PIN_Clear

#define L3_PIN_SetHigh C_PIN_SetHigh
#define L3_PIN_SetLow C_PIN_SetLow
#define L3_PIN_Set    C_PIN_Set
#define L3_PIN_Clear  C_PIN_Clear

#include <stdbool.h>
    
    
void clearSegs();
void clearChars();
void clearAll();
void set_character(char lite_up, bool decimalPoint, int num);
void setRCON();



#ifdef	__cplusplus
}
#endif

#endif	/* SETLEDS_H */

