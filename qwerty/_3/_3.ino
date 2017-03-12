#include <ISADefinitions.h>
#include <ISAButtons.h>
ISAButtons button;
bool state = false;
void setup(){
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 pinMode(LED4, OUTPUT);
 pinMode(LED5, OUTPUT);
 pinMode(LED6, OUTPUT);
 pinMode(LED7, OUTPUT);
 pinMode(LED8, OUTPUT);
 pinMode(KEY_LEFT, INPUT);
 pinMode(KEY_RIGHT, INPUT);

 
}
void loop(){

if(i<7){
  if(!digitalRead(KEY_RIGHT)) {
    i=i+1;
    digitalWrite(LEDS[i-1]
  }
}


 
}
    
