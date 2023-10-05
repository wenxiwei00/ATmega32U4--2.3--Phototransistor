/* Name: main.c
 * Author: WENXI WEI
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include "MEAM_general.h"  // includes the resources included in the MEAM_general.h file
#include "m_usb.h"

#define PRINTNUM(x) m_usb_tx_uint(x); ; m_usb_tx_char(10); m_usb_tx_char(13)


void printPC7state() {
    if( bit_is_set(PINC,7)){
        m_usb_tx_string("high now\n");// wait while PC7 is high
    }else{
        m_usb_tx_string("low now\n");
    }                                                 
}

void setPB3high() {
    if( bit_is_set(PINC,7) ){
        clear(PORTB, 3);
    }else{
        set(PORTB,3); //set output is high
    }
}

int main(void)
{
    m_usb_init(); //init USB for print statements

    _clockdivide(0); //set the system clock speed to 16Mhz
    TCCR3B |= (1 << CS32);//set the timer clock speed to 16M/1024
    TCCR3B |= (1 << CS30);

    DDRB |= (1 << PB3); //set PB3 as output
    DDRC &= ~(1 << PC7); //set PC7 as input
    
    while(1){ 
        printPC7state();
        setPB3high();
    }
    
}









