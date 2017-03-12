#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("j1:X ");
  lcd.print(analogRead(JOY1X));
  lcd.print(" Y ");
  lcd.print(analogRead(JOY1Y));
  lcd.setCursor(0,1);
  lcd.print("j2:X ");
  lcd.print(analogRead(JOY2X));
  lcd.print(" Y ");
  lcd.print(analogRead(JOY2Y));
delay(50);
lcd.clear();
}
