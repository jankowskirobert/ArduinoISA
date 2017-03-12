#include <ISADefinitions.h>
#include<ISAButtons.h>
ISAButtons button;
int i;

void setup() {
  for(i=0; i<8; i++)
  {
   pinMode(LEDS[i], OUTPUT); 
  }
  i=4;
  digitalWrite(LEDS[i], HIGH);
  button.init();
}

void loop() {
  if(button.buttonPressed(0))
  {
    digitalWrite(LEDS[i], LOW);
    if(i>0)
      i--;
    digitalWrite(LEDS[i], HIGH);
  }
  if(button.buttonPressed(1))
  {
    digitalWrite(LEDS[i], LOW);
    if(i<7)
      i++;
    digitalWrite(LEDS[i], HIGH);
  }
  delay(30);
}
