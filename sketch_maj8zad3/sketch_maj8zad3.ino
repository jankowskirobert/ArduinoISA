#include <ISAButtons.h>
#include <ISALedControl.h>
#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int i=0;
void setup() {
  // put your setup code here, to run once:
pinMode(LEDS[i], OUTPUT);
digitalWrite(LEDS[i], HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(LEDS[i], OUTPUT);
if(digitalRead(KEY_RIGHT))
{
  digitalWrite(LEDS[i], LOW);
  i++;
 
}
if(digitalRead(KEY_LEFT))
{pinMode(LEDS[i], OUTPUT);
  digitalWrite(LEDS[i], LOW);
  i--;
}
}
