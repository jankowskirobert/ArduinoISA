#include <ISALiquidCrystal.h>
#include <ISADefinitions.h>
#include<ISAButtons.h>
ISALiquidCrystal lcd;
ISAButtons button;

bool stan = false;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  button.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(LEDS[i], OUTPUT);
  digitalWrite(LEDS[i], HIGH);
  if(button.buttonPressed(0) == true) {
    i--;
    pinMode(LEDS[i+1], OUTPUT);
    digitalWrite(LEDS[i+1], LOW);
  }
  if(button.buttonPressed(1) == true) {
    i++;
    pinMode(LEDS[i-1], OUTPUT);
    digitalWrite(LEDS[i-1], LOW);
  }
  
  if(i < 0) i = 7;
  if(i > 7) i = 0;
  delay(30);
}
