#include <ISALedControl.h>
ISALedControl lc;
void setup()
{
  int i,j;
 lc.init();
 for(i=0;i<8;i++)
 {
  for(j=0;j<8;j++)
  {
 lc.setLed(i, j, true);
 delay(200);
  }}
}
void loop() {}
