#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
void setup()
{
 lcd.begin();
 lcd.print("hello, world!");
}
void loop() {
  unsigned long int czas, sekundy, minuty;
  lcd.clear();
  lcd.print("Czas: ");
  czas = millis();
  sekundy = czas/100;
  
 
  
  if(sekundy>=60){
    sekundy=0;
    minuty=minuty+1;
  }
  if(sekundy!=60){
    lcd.print(sekundy);
  }
    else
    {
      lcd.print("0,0");
    }
  


  lcd.print(minuty);

  delay(1000);
  }
