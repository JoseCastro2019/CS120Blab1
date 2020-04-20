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

enum States { s0, s1, s2, s3, s4 } state;

void Tick()
{
  
   unsigned char A0;
   unsigned char A1;
   unsigned char A2; 
   unsigned char A7;   
  
   A0= PINA & 0x01;
   A1= PINA & 0x02;
   A2= PINA & 0x04;
   A7= PINA & 0x80;
   
   switch(state) {   // Transitions
     case s0: // Initial transition
        if (A7)
        {
           if (!A0 && !A1 && !A2)
              state = s0;
           else 
              {
               state =s0;
               PORTB=0x00;
              }
        }
        else if (A2 && !A1 && !A0)
            state = s1;
        else 
            state = s0;
        break;

     case s1:
        if ( A2 && !A1 && !A2 ) 
           state = s1;
        else if (!A0 && !A1 && !A0)
           state = s2;
        else 
           state = s0;
        break;

     case s2:
       if (!A0 && !A1 && !A2) 
           state = s2;
        else if (!A0 && A1 && !A2) 
           state = s3;
        else 
           state = s0;
        break;
    
    case s3:
        if (A7)
        {
           if (!A0 && !A1 && !A2)
               state = s3;
           else 
              {
                state = s0;
               // PORTB=0x00;       
              }
        }
        else
           state= s3;
        /*if (!A0 && A1 && !A2) {
           state = s3;
        }
        else if (!A0 && !A1 && !A2) {
           state = s4;
        }
        else
        {
           state = s0;
        }*/
       
        break;
    
    case s4:
      
        if (!A0 && !A1 && !A2) {
           state = s4;
        }
        else  {
           state = s0;
        }
        break;
    
     default:
        state = s0;
        break;
  }// Transitions

  switch(state) {  // State actions
     case s0:
        PORTB=0x00;
        PORTC=0x00;
        break;
     case s1:
        PORTC=0x01;
        break;
     case s2:
        PORTC=0x02;
        break;
     case s3:
        PORTC=0x03;
        PORTB=0x01;
        break;
     case s4:
        PORTC=0x04;
        break;
     default:
        break;
   }// State actions
}

void main() {
   PORTC = 0x00;
   PORTB = 0x00;      //        Initialize outputs
   state = s0;   // Indicates initial call

   while(1) {
      Tick();
   }
  return 0;
}

