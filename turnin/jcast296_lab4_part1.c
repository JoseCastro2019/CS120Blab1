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

enum States { Start, release2, press1, release1, press2 } state;

void Tick()
{
  
   unsigned char A0;
   A0= PINA & 0x01;

   switch(state) {  //  Transitions
     case Start: // Initial transition
        state = release2;
        PORTB=0x01;
        break;

     case release2:
        if (!A0) {
           state = release2;
        }
        else if (A0) {
           state = press1;
        }
        break;

     case press1:
       if (A0) {
           state = press1;
        }
        else if (!A0) {
           state = release1;
        }
        break;
    
    case release1:
        if (!A0) {
           state = release1;
        }
        else if (A0) {
           state = press2;
        }
        break;
    
    case press2:
        if (A0) {
           state = press2;
        }
        else if (!A0) {
           state = release2;
        }
        break;
    
     default:
        state = Start;
        break;
  }// Transitions

  switch(state) {   // State actions
     case press1:
        PORTB = 0x02;
        break;

     case press2:
        PORTB = 0x01;
        break;

     default:
        break;
   }// State actions
}

void main() {
   PORTB = 0x00;             // Initialize outputs
   state = Start;   // Indicates initial call

   while(1) {
      Tick();
   }
}
