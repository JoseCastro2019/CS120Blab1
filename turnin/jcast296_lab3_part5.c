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
    DDRB = 0xFE; PORTB = 0x00;
    
    DDRC = 0xFF; PORTC =0x00;    

    unsigned char tmpB = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00;

    unsigned char test;
    unsigned int i = 0;
    unsigned int maxBit = 256;
    unsigned int total = 0;

    /* Insert your solution below */
    while (1) {
            total = 0;
            maxBit = 256;
            tmpA = PINA;
            tmpB = PINB & 0x01;
           
            for (i = 0; i < 8 ; ++i)
            {
              tmpC= tmpA & 0x80;
              if (tmpC == 0x80) 
                 {
                    total = total + maxBit;
                    //total = total + 1;
                  }
              tmpA = tmpA << 1;
              maxBit = maxBit / 2;
            }
            if (tmpB == 0x01)
               {
                  total = total + 1;
               }
            

           if ((total > 5) && (total < 70))
               {
                  tmpB = tmpB | 0x04;
                 //tmpB=total;
               }
            else  if (total >= 70)
               {
                  tmpB = tmpB | 0x02;
                //  tmpB =total;
               }
            else 
               {
                  tmpB = tmpB & 0x01;
                //  tmpB = total;
               }
            PORTB = tmpB;
         } 
    return 0;
}
