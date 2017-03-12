#include "ISADefinitions.h"
#include <DueTimer.h>

class SterringRain {
  
} ;


class LEDFun {
 private:
  const int numberOfLeds = 8;
 public:
  int setUpValue(int);
  void initLeds(void);
  void clearLeds(void);
} qwerty;

void LEDFun::initLeds(void) {
  Serial.begin(9600);
  Serial.println("START");
  for(int i = 0 ; i < numberOfLeds ; i++) {
    Serial.println(LEDS[i]);
  }
  for( int i = 0; i < numberOfLeds; i++ ) {
     pinMode(LEDS[i], OUTPUT);
  }
}
int LEDFun::setUpValue (int value) {
  clearLeds();
  for(int i = 0;i<numberOfLeds;i++){
    digitalWrite(LEDS[i], value%2 );
    value/=2;
  }
}
void LEDFun::clearLeds(void) {
  for( int i = 0; i < numberOfLeds; i++ ) {
    digitalWrite(LEDS[i], LOW);
  }
}

void setup() {
  pinMode(24, OUTPUT);
//  Timer4.attachInterrupt(dioda);
//  Timer4.start(1000000);
  qwerty.initLeds();
}

void loop() {

//  digitalWrite(24, HIGH);
//  delay(10);
//  digitalWrite(24, LOW);
  int pot = analogRead(A9);
  int mapped = map(pot, 0, 1023, 0, 255);
  qwerty.setUpValue(mapped);
}


