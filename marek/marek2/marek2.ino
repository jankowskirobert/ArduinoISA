#include <ISADefinitions.h>
int i=1;
int r=0;
void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);

}

void loop() {

  digitalWrite(LEDS[i], HIGH);
 delay(500);
 digitalWrite(LEDS[i], LOW);
 if(i==7)
 {
 r=1;
 }
 else if(i==0)
 {
  r=0;
 }
  if(r==0)
  i++;
  else
  i--;


}
