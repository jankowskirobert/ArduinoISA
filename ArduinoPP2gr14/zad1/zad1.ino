#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
void setup()
{
 lcd.begin();
 lcd.print("hello, world!");
}
void loop() {
  lcd.clear();
  int czas; int sekundy; int minuty=0;
  czas = millis();

  sekundy=czas/1000;
  if(sekundy >= 60)
  {
    sekundy = sekundy%60;
    minuty = minuty + 1;
  }

  if(minuty==0)
  {
    lcd.print("Czas: 0:");
    lcd.print(sekundy);
  }

  if(minuty>0)
  {
    lcd.print("Czas: ");
    lcd.print(minuty);
    lcd.print(":");
    lcd.print(sekundy);
  }

  delay(1000);
  }

