/*	Author: jcast296
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    
    DDRC = 0xFF; PORTC =0x00;    

    unsigned char tmpB = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00;

    unsigned int i = 0;
    unsigned int total = 0;

    /* Insert your solution below */
    while (1) {
            total = 0;
            tmpA = PINA;
            tmpB = PINB;
           
            for (i = 0; i < 8 ; ++i)
            {
              tmpC= tmpA & 0x80;
              if (tmpC == 0x80) 
                 {
                    total = total + 1;
                    //total = total + 1;
                  }
              tmpA = tmpA << 1;
            }
            
            for (i = 0; i < 8 ; ++i)
            {
              tmpC= tmpB & 0x80;
              if (tmpC == 0x80)
                 {
                    total = total + 1;
                 }
              tmpB = tmpB << 1;
             }


            PORTC = total;
         } 
    return 0;
}
