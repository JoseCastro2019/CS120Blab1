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

    unsigned char cntavail = 0x00;
    unsigned char tmpA = 0x00;

    /* Insert your solution below */
    while (1) {
            tmpA = PINA & 0x0F;
	    if ((tmpA == 0x01) || (tmpA ==0x02) || (tmpA == 0x04) || (tmpA == 0x08)) {
 		 cntavail = 3; 	
                }
            else if ((tmpA == 0x03) || (tmpA == 0x06) || (tmpA == 0x05) || (tmpA == 0x09) || (tmpA == 0x0A) || (tmpA == 0x0C) ) 
               {
                cntavail = 2;
               }
            else if ((tmpA == 0x07) || (tmpA == 0x0E) || (tmpA == 0x0B) || (tmpA == 0x0D)) 
	     {
		cntavail = 1;
             }
	   else if (tmpA == 0x0F)
	    {
               cntavail = 0;
            }
           else 
               cntavail = 4;

           PORTC=cntavail;
           }
    return 0;
}
