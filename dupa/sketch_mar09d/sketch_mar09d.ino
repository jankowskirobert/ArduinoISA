#include "Buttons.h" 
int value = 0 ;
int displayed = 0 ;
Buttons button ;
int morseCode[10][5] = {
  {2,2,2,2,2}, // 0
  {1,2,2,2,2},// 1
  {1,1,2,2,2}, 
  {1,1,1,2,2},
  {1,1,1,1,2},
  {1,1,1,1,1},
  {2,1,1,1,1},
  {2,2,1,1,1},
  {2,2,2,1,1},
  {2,2,2,2,1}
  };
void setup() {
    pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
 button.init();
  pinMode(24, OUTPUT);
 digitalWrite(24, HIGH);
 delay(500);
 digitalWrite(24, LOW);
}

void loop() {
  if (button.buttonPressed(0)) {
    //7 
    value = value*10 + 7;
 }
 
if (button.buttonPressed(1)) {
value = value*10 + 8;
 }
   if (button.buttonPressed(2)) {
value = value*10 + 9;
 }
   if (button.buttonPressed(7)) {
value = value*10 + 4;
 }
    if (button.buttonPressed(6)) {
value = value*10 + 5;
 }
    if (button.buttonPressed(5)) {
value = value*10 + 6;
 }
    if (button.buttonPressed(8)) {
value = value*10 + 1;
 }
    if (button.buttonPressed(9)) {
value = value*10 + 2;
 }
    if (button.buttonPressed(10)) {
value = value*10 + 3;
 }
     if (button.buttonPressed(12)) {
value = 0;
  displayed = value;
 }
     if (button.buttonPressed(14)) {
value = value*10;
 }
 
     if (button.buttonPressed(13)) {
  displayed = value;
  value = 0;
 }
 binary2LED(displayed);
   if (button.buttonPressed(4)) {
 bitToSound(displayed);
 }

 delay(25);

}
void bitToSound(unsigned int value){
  int i = 0 ;
  int x = 0;
  int units = value % 10;
  int tens = (value - units) / 10;
  if(tens < 1) {
    for(i = 0 ; i < 5 ; i++){
      x = morseCode[units][i];
     digitalWrite(24, HIGH);
     delay(250*x);
     digitalWrite(24, LOW);
     delay(350);
    }
  }
}
void binary2LED(unsigned int value) {
  int i = 0;
  int l=2;
  for(;i<8;i++, l++){
    digitalWrite(l, value%2 );
    value/=2;
  }
  
}
