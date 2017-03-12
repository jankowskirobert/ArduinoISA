#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
unsigned long int minuty;
void setup() 
{
  lcd.begin(); 
}

void loop() 
{
  unsigned long int czas,sekundy;
  lcd.clear();
  lcd.print("Czas: ");
  czas = millis();
  sekundy = (czas/1000)-(minuty*60);
  if (sekundy == 60)
     minuty = minuty+1;
  lcd.print(minuty);
  lcd.print(":");
  if (sekundy < 10)
    lcd.print("0");
  if (sekundy != 60)
    lcd.print(sekundy);
  else 
    lcd.print("00");
  delay(1000);
  lcd.setCursor(0,0);
}
