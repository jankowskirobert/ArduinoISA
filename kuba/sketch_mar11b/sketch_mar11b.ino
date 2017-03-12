#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
  int a=1000;
  int s=1;
  int m=0;
void setup() {
  lcd.begin();
  lcd.print("hello darkness");
  lcd.setCursor(0,1);
  lcd.print("my old friend");
  delay(10);
  lcd.clear();

}

void loop() {
  lcd.clear();
  if (m<10){
  lcd.print("0");
  }
  lcd.print(m);
  lcd.print(":");
  if (s<10){
    lcd.print("0");
  }
  lcd.print(s);
  delay(a);
  s++;  
  if (s==60){
    s=0;
    m++;
  }
}
