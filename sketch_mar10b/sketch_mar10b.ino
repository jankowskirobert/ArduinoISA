#include <DueTimer.h>
#include "Buttons.h" 
#include "ISA7SegmentDisplay.h"
Buttons button ;
ISA7SegmentDisplay seg;
int actualTime=0;
int format=0;

void clockUp(){
  actualTime++;
  switch (format){
  case 0:
    displayBin();
  break;
  case 1:
    displayDec();
  break;
  case 2:
    displayHex();
  break;
    
  }
}

void displayBin(){
  int value=actualTime;
  int i = 0;
  for(;i<4;i++){
    seg.displayDigit(value%2, i) ;
    value/=2;
  }
}

void displayDec(){
  int value=actualTime;
  int i = 0;
  for(;i<4;i++){
    seg.displayDigit(value%10, i) ;
    value/=10;
  }
}

void displayHex(){
  int value=actualTime;
  int i = 0;
  for(;i<4;i++){
    int v = value%16;
    if(v<=9)
      seg.displayDigit(v, i);
    else if(v==10)
      seg.setLed(B01111101,i);
    else if(v==11)
      seg.setLed(B11111000,i);
    else if(v==12)
      seg.setLed(B11100100,i);
    else if(v==13)
      seg.setLed(B10111001,i);
    else if(v==14)
      seg.setLed(B11110100,i);
    else if(v==15)
      seg.setLed(B01110100,i);
    value/=16;
  }
}

void setup() {
  seg.init() ;
  Timer5.start(1000000);
  Timer5.attachInterrupt(clockUp);
  button.init();

}

void loop() {
  
  if (button.buttonPressed(0)) {
format=0;
 }
   if (button.buttonPressed(1)) {
format=1;
 }
   if (button.buttonPressed(2)) {
format=2;
 }
 

}
