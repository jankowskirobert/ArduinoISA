#include <DueTimer.h>

int AIN1=13; //lewy
int AIN2=12;
int BIN1=11; //prawy
int BIN2=10;
int encoderP=53;
int encoderL=52;
int voltP=0;
int voltL=0;
volatile int cntL = 0, cntP = 0;
volatile float velocityL = 0.0, velocityP = 0.0;
volatile unsigned long last_measurement;

void revolveCounterL() {
 cntL++;
}
void revolveCounterP() {
 cntP++;
}
void revolveCalcul(){
 velocityL = (float)cntL * 15.0f / 8.0f;
 velocityP = (float)cntP * 15.0f / 8.0f;
 cntL = 0;
 cntP = 0;
}

void turnLeft(int timeToTurn, int tempo) {
  
  digitalWrite(AIN1, LOW); // AIN1; 
  digitalWrite(BIN2, LOW); // AIN2
  while(timeToTurn > 0){
    Serial.println(cntP);
    Serial.println(cntL);
    Serial.println(voltP);
    Serial.println(velocityL);
    Serial.println(velocityP);
    Serial.println();
//    if(((int)velocityL)<tempo) voltL+=1;
//    if(((int)velocityL)>tempo) voltL-=1;
//    if(((int)velocityP)<tempo) voltP+=1;
//    if(((int)velocityP)>tempo) voltP-=1;
    analogWrite(AIN2, tempo);
    analogWrite(BIN1, tempo);
    timeToTurn--;
  }
  digitalWrite(AIN1, HIGH); // AIN1; 
  digitalWrite(AIN2, HIGH); // AIN1; 
  digitalWrite(BIN1, HIGH); // AIN2
  digitalWrite(BIN2, HIGH); // AIN1; 
}

void ster(int ){
  
}

void forward(int tempo){

 digitalWrite(AIN1, LOW); // AIN1; 
 digitalWrite(BIN1, LOW); // AIN2
  //float tempo=(float)temp;
  Serial.println(cntP);
  Serial.println(cntL);
  Serial.println(voltP);
  Serial.println(velocityL);
  Serial.println(velocityP);
  Serial.println();
 if(((int)velocityL)<tempo) voltL+=1;
 if(((int)velocityL)>tempo) voltL-=1;
 if(((int)velocityP)<tempo) voltP+=1;
 if(((int)velocityP)>tempo) voltP-=1;
 
 analogWrite(AIN2, voltL);
 analogWrite(BIN2, voltP);
 
}


void setup() {
 pinMode(AIN1, OUTPUT);
 pinMode(AIN2, OUTPUT);
 pinMode(BIN1, OUTPUT);
 pinMode(BIN2, OUTPUT);

 Serial.begin(9600);
 pinMode(encoderP, INPUT); 
 attachInterrupt(digitalPinToInterrupt(encoderP), revolveCounterP, CHANGE);
 pinMode(encoderL, INPUT); 
 attachInterrupt(digitalPinToInterrupt(encoderL), revolveCounterL, CHANGE);
 Timer4.attachInterrupt(revolveCalcul);
 Timer4.start(250000);


 turnLeft(85, 250);
}

void loop(){

  //forward(20);
  
  delay(100);
 

 /**backward
 digitalWrite(AIN2, LOW);
 digitalWrite(BIN2, LOW);
 for (int i = 0; i < 255; ++i) {
 analogWrite(AIN1, i);
 analogWrite(BIN1, i);
 delay(50);
 }**/
  
}

