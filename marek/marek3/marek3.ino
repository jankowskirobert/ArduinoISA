#include <ISADefinitions.h>
#include <ISAButtons.h>
ISAButtons button;
int i=0;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
   digitalWrite(LED1, HIGH);
   button.init();

}

void loop() {
  if(button.buttonPressed(3))
  {
  digitalWrite(LEDS[i], LOW);
  i++;
  digitalWrite(LEDS[i], HIGH);
  delay(500);
  if(i==7)
  {
  digitalWrite(LEDS[7], LOW);
  i=0;
  digitalWrite(LEDS[i], HIGH);
  }
  }

if(button.buttonPressed(0))
  {
  digitalWrite(LEDS[i], LOW);
  i--;
  digitalWrite(LEDS[i], HIGH);
  delay(500);
  if(i==0)
  {
  digitalWrite(LEDS[0], LOW);
  i=7;
  digitalWrite(LEDS[i], HIGH);
  }
  }

}
