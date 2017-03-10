#include <DueTimer.h>

const int ECHO=44;
const int TRIG=45;

void setup() {
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(15);
  digitalWrite(TRIG,LOW);
  bool response=false;
  while(!response){
    response=digitalRead(ECHO);
  }
  unsigned long start=micros();
  while(response){
    response=digitalRead(ECHO);
  }
  unsigned long stop = micros();
  Serial.println((stop-start)/58);
}
