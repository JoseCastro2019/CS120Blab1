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

enum States { Start, s0, s1, s2, s3 } state;
unsigned char cnt;

void Tick()
{
  
   unsigned char A0;
   unsigned char A1;
   
   
   A0= PINA & 0x01;
   A1= PINA & 0x02;
   
   switch(state) {  //  Transitions
     case Start: // Initial transition
        state = s0;
        cnt = 7;
        PORTC= cnt;
        break;

     case s0:
        if ( !A0 && !A1 ) {
           state = s0;
           
        }
        else if (A0 && !A1 ) {
           state = s1;
           if (cnt < 9) 
                 ++cnt;
           PORTC = cnt;
        }
        else if (A0 && A1) {
           state = s3;
        }
        else   //(A1 && !A0)  
        {
          state = s2;
          if (cnt > 0)
             --cnt; 
          PORTC = cnt;
        }
        break;

     case s1:
       if (A0 && !A1) {
           state = s1;
        }
        else if (!A0 && !A1) {
           state = s0;
        }
        else if (A0 && A1)
        {
           state = s3;
        }
        break;
    
    case s2:
        if (!A0 && A1) {
           state = s2;
        }
        else if (!A0 && !A1) {
           state = s0;
        }
        else if (A1 && A0)
        {
           state = s3;
        }
        break;
    
    case s3:
        if ((A0 && A1) || (!A0 && A1) || (A0 && !A1)) {
           state = s3;
        }
        else if (!A0 && !A1) {
           state = s0;
        }
        break;
    
     default:
        state = Start;
        break;
  }// Transitions

  switch(state) {   // State actions
     case s3:
        cnt = 0;
        PORTC = cnt;
        break;

     default:
        break;
   }// State actions
}

void main() {
   PORTC = 0x00;             // Initialize outputs
   state = Start;   // Indicates initial call

   while(1) {
      Tick();
   }
}
