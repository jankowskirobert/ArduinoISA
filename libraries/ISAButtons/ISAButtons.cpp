/*
  Display.h - Library for displaying digits on 
	      seven-segment disply.
  Created by Piotr Duch, December 30, 2016.
*/

#include "Arduino.h"
#include "ISAButtons.h"

ISAButtons::ISAButtons()
{
}




void ISAButtons::init()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, INPUT);
}

void ISAButtons::refresh()
{

  unsigned long currentTimeStamp = millis();

  if ( currentTimeStamp - timeOfLastButtonUpdate > 25 )
  {
     timeOfLastButtonUpdate = currentTimeStamp;
  }
  else  
     return;

  digitalWrite(latchPin,1);
  //set it to 1 to collect parallel data, wait
  //delayMicroseconds(20);
  //set it to 0 to transmit data serially  
  digitalWrite(latchPin,0);

  //while the shift register is in serial mode
  //collect each shift register into a byte
  //the register attached to the chip comes in first
  currentState1 = shiftIn(dataPin, clockPin);
  currentState2 = shiftIn(dataPin, clockPin);

  for ( int i = 0; i < 8; ++i )
  {
    int previous = (previousState1 & (1 << i)) >> i;
    int current = (currentState1 & (1 << i)) >> i;

    if (current == 0 && previous != current)
      buttonsPressed[ i ] = true;
    else
      buttonsPressed[ i ] = false;

    if (current == 1 && previous != current)
      buttonsReleased[ i ] = true;
    else
      buttonsReleased[ i ] = false;
  }

  for ( int i = 0; i < 8; ++i )
  {
    int previous = (previousState2 & (1 << i)) >> i;
    int current = (currentState2 & (1 << i)) >> i;

    if (current == 0 && previous != current)
      buttonsPressed[ i + 8] = true;
    else
      buttonsPressed[ i + 8 ] = false;

    if (current == 1 && previous != current)
      buttonsReleased[ i + 8 ] = true;
    else
      buttonsReleased[ i + 8 ] = false;
  }
  
  previousState1 = currentState1;
  previousState2 = currentState2;
    
}

//Zwraca true jezeli zostal przycisk nacisniety (zmienil stan w niewcisnietego na wcisniety)
bool ISAButtons::buttonPressed( int id )
{
  refresh();

  if ( id >= numberOfButtons )
    return false;
  
  return buttonsPressed[ id ];
}

//Zwraca true jezeli zostal przycisk zwolniony (zmienil stan w wcisnietego na niewcisniety)
bool ISAButtons::buttonReleased( int id )
{
  refresh();

  if ( id >= numberOfButtons )
    return false;
  
  return buttonsReleased[ id ];
}

//Zwraca true jak wcisniety, false jak nie
bool ISAButtons::buttonState( int id )
{
  refresh();
 
  if ( id >= numberOfButtons )
    return false;
  else if (id < 8)
    return ((~currentState1) & (1 << id)) >> id;
  else 
    return ((~currentState2) & (1 << (id - 8))) >> (id - 8);
}

byte ISAButtons::shiftIn(int myDataPin, int myClockPin) 
{
  int i;
  int temp = 0;
  int pinState;
  byte myDataIn = 0;

  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, INPUT);

//we will be holding the clock pin high 8 times (0,..,7) at the
//end of each time through the for loop

//at the begining of each loop when we set the clock low, it will
//be doing the necessary low to high drop to cause the shift
//register's DataPin to change state based on the value
//of the next bit in its serial information flow.
//The register transmits the information about the pins from pin 7 to pin 0
//so that is why our function counts down
  for (i=7; i>=0; i--)
  {
    digitalWrite(myClockPin, 0);
    delayMicroseconds(2);
    temp = digitalRead(myDataPin);
    if (temp) {
      pinState = 1;
      //set the bit to 0 no matter what
      myDataIn = myDataIn | (1 << i);
    }
    else {
      //turn it off -- only necessary for debuging
     //print statement since myDataIn starts as 0
      pinState = 0;
    }

    //Debuging print statements
    //Serial.print(pinState);
    //Serial.print("     ");
    //Serial.println (dataIn, BIN);

    digitalWrite(myClockPin, 1);

  }
  //debuging print statements whitespace
  //Serial.println();
  //Serial.println(myDataIn, BIN);
  return myDataIn;
}
