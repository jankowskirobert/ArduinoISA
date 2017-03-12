#include <ISADefinitions.h>
#include<ISALiquidCrystal.h>

ISALiquidCrystal lcd;

void setup() {
  // put your setup code here, to run once:
   lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int Joy1X = analogRead(JOY1X);
  int Joy1Y = analogRead(JOY1Y);
  int Joy2X = analogRead(JOY2X);
  int Joy2Y = analogRead(JOY2Y);

  lcd.print(Joy1X);
  lcd.setCursor(8,0);
  lcd.print(Joy1Y);

  lcd.setCursor(0,1);
  lcd.print(Joy2X);
  lcd.setCursor(8,1);
  lcd.print(Joy2Y);
  delay(100);
  lcd.clear();

}
