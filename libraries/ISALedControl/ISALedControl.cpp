/*
  Display.h - Library for displaying digits on 
	      seven-segment disply.
  Created by Piotr Duch, December 30, 2016.
*/

#include "Arduino.h"
#include <SPI.h>
#include "ISALedControl.h"

ISALedControl::ISALedControl()
{
}

void ISALedControl::init()
{
	  // Set load pin to output
  pinMode(LOAD_PIN, OUTPUT);

  // Reverse the SPI transfer to send the MSB first  
  SPI.setBitOrder(MSBFIRST);
  
  // Start SPI
  SPI.begin();

  // Run test
  // All LED segments should light up
//  maxTransfer(0x0F, 0x01);
//  delay(1000);
  maxTransfer(0x0F, 0x00);
// delay(500);
  // Enable mode B
  //maxTransfer(0x09, 0x00);
  
  // Use lowest intensity
  maxTransfer(0x0A, 0x00);
  
  // Only scan one digit
  maxTransfer(0x0B, 0x07);
  
  // Turn on chip
  maxTransfer(0x0C, 0x01);

  clearDisplay();
	
}

/**
 * Transfers data to a MAX7219/MAX7221 register.
 * 
 * @param address The register to load data into
 * @param value   Value to store in the register
 */
void ISALedControl::maxTransfer(uint8_t address, uint8_t value) {

  // Ensure LOAD/CS is LOW
  digitalWrite(LOAD_PIN, LOW);

  // Send the register address
  SPI.transfer(address);

  // Send the value
  SPI.transfer(value);

  // Tell chip to load in data
  digitalWrite(LOAD_PIN, HIGH);
}  

/**
 * Transfers data to a MAX7219/MAX7221 register.
 * 
 * @param address The register to load data into
 * @param value   Value to store in the register
 */
void ISALedControl::setColumn(byte col, byte values) {

  if ( col >= 8 )
    return;

  columnState[col] = values;  

  // Ensure LOAD/CS is LOW
  digitalWrite(LOAD_PIN, LOW);

  // Send the register address
  SPI.transfer(col + 1);

  // Send the value
  SPI.transfer(values);

  // Tell chip to load in data
  digitalWrite(LOAD_PIN, HIGH);
}

void ISALedControl::setLed(byte row, byte col, byte val)
{
  if (val)
  {
    columnState[col] |= (1 << row);
  }
  else
  {
    
    columnState[col] &= (~(1 << row));   
  }

  setColumn(col, columnState[col]);
}


void ISALedControl::setRow(byte row, byte values)
{
  for (int i = 0; i < 8; ++i)
    setLed(row, i, (values & (1 << i)) >> i );
  
}

void ISALedControl::clearDisplay()
{
  for (int i = 0; i < 8; ++i)
    columnState[i] = 0;
    
  for (int i = 1; i <= 8; ++i) 
    maxTransfer(i, B00000000);
}
