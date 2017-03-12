#include <ISADefinitions.h>
#include <ISA7SegmentDisplay.h>

ISA7SegmentDisplay sseg;


void setup() {
  // put your setup code here, to run once:
  sseg.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<10;i++)
  {
    sseg.displayDigit(i,0);
    delay(250);
  }
}
