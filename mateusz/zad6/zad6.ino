#include <ISADefinitions.h>
#include <ISA7SegmentDisplay.h>

ISA7SegmentDisplay seg;
int i = 0;

void setup() {
  seg.init();

}

void loop() {
  int mins = i/60;
  int secs = i%60;
  seg.displayDigit(mins/10, 3);
  seg.displayDigit(mins%10, 2, true);
  seg.displayDigit(secs/10, 1);
  seg.displayDigit(secs%10, 0);
  
  i = i + 1;
  delay(250);
}
