#include <DueTimer.h>
int actualLED = 2;
int destination = 1;
int maxLED = 10;
int minLED = 1;
bool state = false;
void dioda(){
digitalWrite(actualLED, LOW);

//state = !state;
actualLED += destination;
digitalWrite(actualLED, HIGH);
if(actualLED==maxLED)
  destination = -1;
if(actualLED==minLED)
  destination = 1;

}
void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
 Timer4.attachInterrupt(dioda);
 Timer4.start(1000000);
}
void loop(){}
