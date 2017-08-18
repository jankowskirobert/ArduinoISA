/*
  Display.h - Library for displaying digits on 
	      seven-segment disply.
  Created by Piotr Duch, December 30, 2016.
*/

#include "Arduino.h"
#include "ISA7SegmentDisplay.h"


void ISA7SegmentDisplay::displayDigit(byte digit, int dispID, bool dot)
{
  if (digit > 9 || dispID > 3)
    return;
  
  byte value = numbers[digit];

  if (dot) 
    value |= (1 << 1);

  for (int i = 0; i < 8; ++i)
  {
    digitalWrite(CLK, LOW);
    delayMicroseconds(5);
    digitalWrite(DATA, !((value)&(1<<i)));
    delayMicroseconds(5);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(5);

  }

  digitalWrite(STRPins[dispID], HIGH);
  digitalWrite(STRPins[dispID], LOW);
}

void ISA7SegmentDisplay::setLed(byte values, int dispID)
{
  if (dispID > 3)
    return;
  
  for (int i = 0; i < 8; ++i)
  {
    digitalWrite(CLK, LOW);
    delayMicroseconds(5);
    digitalWrite(DATA, !(values&(1<<i)));
    delayMicroseconds(5);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(5);

  }

  digitalWrite(STRPins[dispID], HIGH);
  digitalWrite(STRPins[dispID], LOW);
}


void ISA7SegmentDisplay::init()
{
  // put your setup code here, to run once:
  pinMode(OE, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(CLK, OUTPUT);

  pinMode(STR1, OUTPUT);
  pinMode(STR2, OUTPUT);
  pinMode(STR3, OUTPUT);
  pinMode(STR4, OUTPUT);
  

  digitalWrite(STR1, HIGH);
  digitalWrite(STR2, HIGH);
  digitalWrite(STR3, HIGH);
  digitalWrite(STR4, HIGH);  
  digitalWrite(OE, HIGH);

  for (int i = 0; i < 8; ++i)
  {
    digitalWrite(CLK, LOW);
    delayMicroseconds(5);
    digitalWrite(DATA, HIGH);
    delayMicroseconds(5);
    digitalWrite(CLK, HIGH);
    delayMicroseconds(5);
  }

  digitalWrite(STR1, LOW);
  digitalWrite(STR2, LOW);
  digitalWrite(STR3, LOW);
  digitalWrite(STR4, LOW); 
  
}
