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

//Sonar
int trig = 45;    
int echo = 44;    
float duration;
float distance = 30;
char buffor[16];



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

void stopCar(){
  digitalWrite(AIN1, HIGH); // AIN1; 
  digitalWrite(AIN2, HIGH); // AIN1; 
  digitalWrite(BIN1, HIGH); // AIN2
  digitalWrite(BIN2, HIGH); // AIN1; 
}
void forward(int tempo){

 digitalWrite(AIN1, LOW); // AIN1; 
 digitalWrite(BIN1, LOW); // AIN2
  //float tempo=(float)temp;
  int rate=5;
  Serial.println(cntP);
  Serial.println(cntL);
  Serial.println(voltP);
  Serial.println(velocityL);
  Serial.println(velocityP);
  Serial.println();
 if(((int)velocityL)<tempo) voltL+=rate;
 if(((int)velocityL)>tempo) voltL-=rate;
 if(((int)velocityP)<tempo) voltP+=rate;
 if(((int)velocityP)>tempo) voltP-=rate;
 
 analogWrite(AIN2, voltL);
 analogWrite(BIN2, voltP);
 
}

void rectangle(int a, int b){
  int i;
  int rate = 50;
  turnLeft(85, 250);
  for(i=0;i<a;i++)
    forward(rate);
  stopCar();
  delay(100);
  turnLeft(85, 250);
  for(i=0;i<b;i++)
    forward(rate);
  stopCar();
  delay(100);
  turnLeft(85, 250);
  
  for(i=0;i<a;i++)
    forward(rate);
  stopCar();
  delay(100);
  turnLeft(85, 250);
  for(i=0;i<b;i++)
    forward(rate);
  stopCar();
}

void displayDistanceSerial(float distance){
  Serial.print("Distance (in cm): ");
  Serial.print(distance);
  Serial.print(int(distance));
  Serial.println();
}

bool checkBrakeStatus(float distance){

  if(distance < 25){
    displayDistanceSerial(distance);

    return false;
    } else {
      displayDistanceSerial(distance);
      return true;
    }
}

void setup() {
 pinMode(AIN1, OUTPUT);
 pinMode(AIN2, OUTPUT);
 pinMode(BIN1, OUTPUT);
 pinMode(BIN2, OUTPUT);
 pinMode(trig, OUTPUT);
 pinMode(echo, INPUT);

 Serial.begin(9600);
 pinMode(encoderP, INPUT); 
 attachInterrupt(digitalPinToInterrupt(encoderP), revolveCounterP, CHANGE);
 pinMode(encoderL, INPUT); 
 attachInterrupt(digitalPinToInterrupt(encoderL), revolveCounterL, CHANGE);
 Timer4.attachInterrupt(revolveCalcul);
 Timer4.start(250000);



}

void loop(){

//  rectangle(100,100);
  
  
  //delay(100);

  
digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW); 
  
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
 
  distance = (duration/2) / 29.1 - 0.5;
if (checkBrakeStatus(distance)){
  
  forward(20);
} else{
stopCar();
}
 

 /**backward
 digitalWrite(AIN2, LOW);
 digitalWrite(BIN2, LOW);
 for (int i = 0; i < 255; ++i) {
 analogWrite(AIN1, i);
 analogWrite(BIN1, i);
 delay(50);
 }**/
  
}

