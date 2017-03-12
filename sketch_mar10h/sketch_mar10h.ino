#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
long i,s, m;
void setup() {
  lcd.begin();
  lcd.clear();
  //lcd.print("Hello, world!");
}

void loop() {
  for(i=0; ;i++)
  {
    lcd.clear();
    lcd.print(m);
    //lcd.setCursor(1,0);
    lcd.print(":");
    //lcd.setCursor(2,0);    
    lcd.print(i);
    if(i%59 == 0)
    {
      m=m+1;
      i=0;
    }
    delay(1000);
  }

}
