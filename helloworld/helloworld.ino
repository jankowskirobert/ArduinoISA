#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int czas;
void setup() {
  
  // put your setup code here, to run once:
  lcd.begin();
  lcd.print("Hello world");
  lcd.setCursor(0,1);
  czas=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.print(czas/60);
  lcd.print(":");
  lcd.print(czas % 60);
  delay(1000);
  lcd.clear();
  czas++;
}
