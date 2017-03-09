#include <DueTimer.h>

int actualLed=3;

volatile int directionLed=1;
void setup() {
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
Timer5.start(50000);
Timer5.attachInterrupt(clockUp);

}
void clockUp(){
  actualLed+=directionLed;
  analogWrite(actualLed-2,0);
  analogWrite(actualLed-1,10);
  analogWrite(actualLed,60);
  analogWrite(actualLed+1,10);
  analogWrite(actualLed+2,0);
  if(actualLed>8) directionLed=-1;
  if(actualLed<3) directionLed=1;
}


void loop() {


}

