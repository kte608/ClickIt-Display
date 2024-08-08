
#include "mcc_generated_files/system/system.h"
#include "setLEDs.h"

void clearSegs() {
    A_PIN_Clear();
    B_PIN_Clear();
    C_PIN_Clear();
    D_PIN_Clear();
    E_PIN_Clear();
    F_PIN_Clear();
    G_PIN_Clear();
    DP_PIN_Clear();

}

void clearChars() {

    CA1_PIN_Clear();
    CA2_PIN_Clear();
    CA3_PIN_Clear();
    CA4_PIN_Clear();
    CAL_PIN_Clear();
}

// Clear all the segments and the characters.
void clearAll() {
    clearChars();
    clearSegs();
}

// lite_up is the character to display
// num is which character to put it in.
// when num==0, we have a special case of controlling the lights.
//
void set_character(char lite_up, 
                   bool decimalPoint, 
                   int num) {
    clearAll();
    //This part draws the characters. 

    if(decimalPoint)
    {
        DP_PIN_Set();
    }
    else
    {
        DP_PIN_Clear();
    }
    
    if (num == 0) { // Lights
        if(lite_up&(1<<0))
        {
            L1_PIN_Set();
        }
        if(lite_up&(1<<1))
        {
            L2_PIN_Set();
        }
        if(lite_up&(1<<2))
        {
            L3_PIN_Set();
        }
       
    } else {
        switch (lite_up) {
            case 0:
                A_PIN_Clear();
                B_PIN_Clear();
                C_PIN_Clear();
                D_PIN_Clear();
                E_PIN_Clear();
                F_PIN_Clear();
                G_PIN_Clear();
                break;
            case '1':
                A_PIN_Clear();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Clear();
                E_PIN_Clear();
                F_PIN_Clear();
                G_PIN_Clear();
                break;
            case '2':
                A_PIN_Set();
                B_PIN_Set();
                C_PIN_Clear();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Clear();
                G_PIN_Set();
                break;
            case '3':
                A_PIN_Set();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Set();
                E_PIN_Clear();
                F_PIN_Clear();
                G_PIN_Set();
                break;
            case '4':
                A_PIN_Clear();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Clear();
                E_PIN_Clear();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case 'z':
                A_PIN_Set();
                B_PIN_Clear();
                C_PIN_Set();
                D_PIN_Clear();
                E_PIN_Set();
                F_PIN_Clear();
                G_PIN_Set();
                break;
            case '5':
            case 'S':
                A_PIN_Set();
                B_PIN_Clear();
                C_PIN_Set();
                D_PIN_Set();
                E_PIN_Clear();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case '6':
                A_PIN_Set();
                B_PIN_Clear();
                C_PIN_Set();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case '7':
                A_PIN_Set();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Clear();
                E_PIN_Clear();
                F_PIN_Clear();
                G_PIN_Clear();
                break;
            case '8':
                A_PIN_Set();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case '9':
                A_PIN_Set();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Set();
                E_PIN_Clear();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case '0':
                A_PIN_Set();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Clear();
                break;
            case 'A':
                A_PIN_Set();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Clear();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case 'b':
                A_PIN_Clear();
                B_PIN_Clear();
                C_PIN_Set();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case 'C':
                A_PIN_Set();
                B_PIN_Clear();
                C_PIN_Clear();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Clear();
                break;
            case 'd':
                A_PIN_Clear();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Clear();
                G_PIN_Set();
                break;
            case 'E':
                A_PIN_Set();
                B_PIN_Clear();
                C_PIN_Clear();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case 'F':
                A_PIN_Set();
                B_PIN_Clear();
                C_PIN_Clear();
                D_PIN_Clear();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case 'H':
                A_PIN_Clear();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Clear();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case 'L':
                A_PIN_Clear();
                B_PIN_Clear();
                C_PIN_Clear();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Clear();
                break;
            case 'n':
                A_PIN_Clear();
                B_PIN_Clear();
                C_PIN_Set();
                D_PIN_Clear();
                E_PIN_Set();
                F_PIN_Clear();
                G_PIN_Set();
                break;
            case 'P':
                A_PIN_Set();
                B_PIN_Set();
                C_PIN_Clear();
                D_PIN_Clear();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Set();
                break;
            case 'U':
                A_PIN_Clear();
                B_PIN_Set();
                C_PIN_Set();
                D_PIN_Set();
                E_PIN_Set();
                F_PIN_Set();
                G_PIN_Clear();
                break;
            default:
                A_PIN_Clear();
                B_PIN_Clear();
                C_PIN_Clear();
                D_PIN_Clear();
                E_PIN_Clear();
                F_PIN_Clear();
                G_PIN_Clear();
                break;
        }
    }
    //This part chooses the character. 1-4
    switch (num) {
        case 0: // The lights.
            CA1_PIN_Clear();
            CA2_PIN_Clear();
            CA3_PIN_Clear();
            CA4_PIN_Clear();
            CAL_PIN_Set();

            break;
        case 1:
            CA1_PIN_Set();
            CA2_PIN_Clear();
            CA3_PIN_Clear();
            CA4_PIN_Clear();
            CAL_PIN_Clear();
            break;
        case 2:
            CA1_PIN_Clear();
            CA2_PIN_Set();
            CA3_PIN_Clear();
            CA4_PIN_Clear();
            CAL_PIN_Clear();
            break;
        case 3:
            CA1_PIN_Clear();
            CA2_PIN_Clear();
            CA3_PIN_Set();
            CA4_PIN_Clear();
            CAL_PIN_Clear();
            break;
        case 4:
            CA1_PIN_Clear();
            CA2_PIN_Clear();
            CA3_PIN_Clear();
            CA4_PIN_Set();
            CAL_PIN_Clear();
            break;
        default:
            CA1_PIN_Clear();
            CA2_PIN_Clear();
            CA3_PIN_Clear();
            CA4_PIN_Clear();
            CAL_PIN_Clear();
            break;



    }
}

void setRCON() {
    // See page 238 of 387
    clearAll();
    if (RCONbits.nRI)//RCON&1<<4)
    {// Clear if it was not a RI
        D_PIN_Clear();
    } else {// Set if it was a RI
        D_PIN_Set();
    }

    if (RCONbits.nTO)//RCON&1<<3)
    {// Clear if it was not a TO
        E_PIN_Clear();
    } else {// Set if it was a TO
        E_PIN_Set();

    }


    if (RCONbits.nPD)//RCON&1<<2)
    {// Clear if it was not a PD
        F_PIN_Clear();
    } else {// Set if it was a PD
        F_PIN_Set();

    }

    if (RCONbits.nPOR)//RCON&1<<1
    {// Clear if it was not a POR
        G_PIN_Clear();
    } else {// Set if it was a POR
        G_PIN_Set();

    }

    if (RCONbits.nBOR)//RCON&1<<0)
    {// Clear if it was not a BOR
        DP_PIN_Clear();
    } else {// Set if it was a BOR
        DP_PIN_Set();
    }
    //

    //CA1_PIN_SetLow();
    __delay_ms(10);
}
