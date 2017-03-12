#include <ISADefinitions.h>
#include <ISALiquidCrystal.h>

int i = 0;
ISALiquidCrystal lcd;

void setup() {
  lcd.begin();
}

void loop() {
  lcd.clear();
  int joy = analogRead(JOY1X);
  lcd.print(joy);

}
