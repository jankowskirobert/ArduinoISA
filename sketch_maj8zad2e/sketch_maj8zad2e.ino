#include <ISALedControl.h>
#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int i=1;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
if(i-1==0)
{ delay(500);
  pinMode(LEDS[i-1], OUTPUT);
  digitalWrite(LEDS[i-1], HIGH);
  
}
delay(500);
digitalWrite(LEDS[i-1], LOW);
pinMode(LEDS[i], OUTPUT);
digitalWrite(LEDS[i], HIGH);
i++;
if(i==8){
  
  delay(500);
  digitalWrite(LEDS[i-1], LOW);
  digitalWrite(LEDS[i-2], HIGH);
  for(i=6;i>0;i--)
  {
    delay(500);
    pinMode(LEDS[i], OUTPUT);
digitalWrite(LEDS[i], LOW);

digitalWrite(LEDS[i-1], HIGH);
  }
  i=1;
  
}

}

