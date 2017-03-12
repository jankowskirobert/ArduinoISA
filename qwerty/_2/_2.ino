#include <ISADefinitions.h>
void setup(){
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 pinMode(LED4, OUTPUT);
 pinMode(LED5, OUTPUT);
 pinMode(LED6, OUTPUT);
 pinMode(LED7, OUTPUT);
 pinMode(LED8, OUTPUT);
 digitalWrite(LED1, HIGH);
 digitalWrite(LED2, HIGH);
 digitalWrite(LED3, HIGH);
 digitalWrite(LED4, HIGH);
 digitalWrite(LED5, HIGH);
 digitalWrite(LED6, HIGH);
 digitalWrite(LED7, HIGH);
 digitalWrite(LED8, HIGH);
}
void loop(){

  for(int i=0; i<8;i++)
  {
    digitalWrite(LEDS[i], HIGH);
    delay(50); 
    digitalWrite(LEDS[i], LOW);
  }
      for(int i=7;i>=0;i--)
      {
     digitalWrite(LEDS[i], HIGH);
    delay(50); 
    digitalWrite(LEDS[i], LOW);
      }
    }
