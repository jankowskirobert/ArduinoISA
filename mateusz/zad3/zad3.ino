#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>

int i = 0;

void setup() {
  for(i = 0;i<8;i++)
  {
    pinMode(LEDS[i], OUTPUT);
  }
}

void loop() {
  for(i = 0;i<8;i++)
  {
    digitalWrite(LEDS[i], LOW);
  }
  int pot = analogRead(POT);
  if(pot>800)
    digitalWrite(LEDS[7], HIGH);
  else if(pot>700)
    digitalWrite(LEDS[6], HIGH);
  else if(pot>600)
    digitalWrite(LEDS[5], HIGH);
  else if(pot>500)
    digitalWrite(LEDS[4], HIGH);
  else if(pot>400)
    digitalWrite(LEDS[3], HIGH);
  else if(pot>300)
    digitalWrite(LEDS[2], HIGH);
  else if(pot>200)
    digitalWrite(LEDS[1], HIGH);
  else if(pot>100)
    digitalWrite(LEDS[0], HIGH);
}
