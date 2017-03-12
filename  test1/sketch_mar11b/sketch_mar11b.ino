#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int i=0, k=0;
void setup() {
  // put your setup code here, to run once:
lcd.begin();
int i, k=0;
}
void loop() {
  // put your main code here, to run repeatedly:

lcd.print(k);
lcd.print(":");
if(i<10)
{
  lcd.print("0");
  lcd.print(i);
}
else
  lcd.print(i);
delay(100);
lcd.clear();
i++;

if(i==60)
  {
   k++;
   i=0;
  }
}
