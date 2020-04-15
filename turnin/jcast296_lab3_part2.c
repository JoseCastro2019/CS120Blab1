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
    DDRC = 0XFF; PORTC = 0X00;

    unsigned char tmpC = 0x00;
    unsigned char tmpA = 0x00;

    /* Insert your solution below */
    while (1) {
            tmpA = PINA;
            tmpC = tmpA & 0x0F; 
 
            if (tmpC == 0x00) {
 		tmpC = 0x40;
                }
            else if ((tmpC > 0) && (tmpC < 0x03) ) 
               {
                tmpC = 0x60;
               }
            else if ((tmpC > 0) && (tmpC < 5))
               {
                tmpC = 0x70;
               }
            else if ((tmpC > 0) && (tmpC < 7))
              {
               tmpC = 0x38;
              }
            else if ((tmpC >0) && (tmpC < 10))
              {
               tmpC = 0x3C;
              }
            else if ((tmpC > 0) && (tmpC < 12))
              {
               tmpC =0x3E;
              }
            else if ((tmpC > 0) && (tmpC <= 15))
              {
               tmpC =0x3F;
              }
            else 
              {
               tmpC =0x00;
              }


           PORTC=tmpC;
           }
    return 0;
}
