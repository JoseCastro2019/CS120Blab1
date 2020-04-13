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
    DDRB = 0X00; PORTB = 0XFF;
    DDRC = 0x00; PORTC = 0xFF;

    DDRD = 0xFF; PORTD = 0x00;

    unsigned char tmpB = 0x00;
    unsigned char tmpA = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char totWeight = 0x00;

    /* Insert your solution below */
    while (1) {
        tmpA = PINA; 
        tmpB = PINB;
        tmpC = PINC;
        totWeight = tmpA + tmpB + tmpC;
    
        if ((tmpA + tmpB + tmpC) > 140) 
          {
             PORTD = 0x01; 
          }
        else 
          {
             PORTD = 0x00;
          } 
        if (((tmpA - tmpC) > 80) || ((tmpC - tmpA) > 8))
          {
             PORTD = PORTD | 0x02;
          } 
        PORTD = PORTD | (totWeight & 0xFC); 
        }
    return 0;
}

