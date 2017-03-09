#include <DueTimer.h>
#include "Buttons.h" 

Buttons button ;
int actualLed=0;
volatile int directionLed=1;
void setup() {
  pinMode(2, OUTPUT); //led8
  pinMode(3, OUTPUT); //led7
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
Timer5.start(50000);
Timer5.attachInterrupt(clockUp);
 button.init();
 analogWrite(6,60); //zmana stabilna 
}
void clockUp(){
  actualLed+=directionLed;
  analogWrite(2,actualLed);
  if(actualLed>254) directionLed=-1;
  if(actualLed<1) directionLed=1;
}


void loop() {


}

