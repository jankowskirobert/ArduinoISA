/*
  Display.h - Library for button handling.
  Created by Piotr Duch, December 30, 2016.
*/

#ifndef ISA7SegmentDisplay_h
#define ISA7SegmentDisplay_h

#include "Arduino.h"

class ISA7SegmentDisplay {

  public:
	ISA7SegmentDisplay() {}
	void init();
	void displayDigit(byte digit, int dispID, bool dot = false);
	void setLed(byte values, int dispID);

  private:
	const byte numbers[10] = {B11101101, B00001001, B10110101, B10011101, B01011001, B11011100, B11111100, B00001101, B11111101, B11011101};
	const int STR1 = 33;
	const int STR2 = 34;
	const int STR3 = 35;
	const int STR4 = 36;
	const int OE = 37;
	const int DATA = 38;	
	const int CLK = 39;
	const int STRPins[4] = {STR1, STR2, STR3, STR4};

};

#endif
