#include <DueTimer.h>
volatile int ECHO     = 44;
volatile int TRIGGER  = 45;
volatile bool mode = false;
volatile long startMeasure = 0;
volatile long stopMeasure = 0;
void setup() {
   Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
 Timer4.attachInterrupt(initUltraSonic);
 Timer4.start(1000000);
  attachInterrupt(digitalPinToInterrupt(ECHO), signalChange, CHANGE);
}

void loop() {
  Serial.println(stopMeasure/58);
}

void signalChange() {
  if(!mode){
    startMeasure = micros();
    mode = true;
  } else {
    stopMeasure = micros() - startMeasure;
    mode = false;
  }
}
void initUltraSonic() {
//  Timer4.detachInterrupt();
  digitalWrite(TRIGGER,HIGH);
   Timer4.attachInterrupt(waitUltraSound);
   Timer4.start(1500);

}
void waitUltraSound(){
   digitalWrite(TRIGGER,LOW);
//   Timer4.detachInterrupt();
   Timer4.attachInterrupt(initUltraSonic);
   Timer4.start(1000000);
}

