#include <ISADefinitions.h>
#include <ISA7SegmentDisplay.h>
ISA7SegmentDisplay sseg;
void setup() {
  // put your setup code here, to run once:
  sseg.init();
}
int i=0;
void loop() {
  // put your main code here, to run repeatedly:
  int j=i/60;
  int k=i%60;
  if(j>9){
    sseg.displayDigit(j/10, 3);
    sseg.displayDigit(j%10, 2);
  }
  else{
    sseg.displayDigit(0, 3);
    sseg.displayDigit(j, 2);
  }
  
  if(k>9){
    sseg.displayDigit(k/10, 1);
    sseg.displayDigit(k%10, 0);
  }
  else{
    
    sseg.displayDigit(0, 1);
    sseg.displayDigit(k, 0);
  }
  
  i++;
  delay(1000);
  
}
