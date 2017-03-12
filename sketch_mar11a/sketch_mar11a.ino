#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.clear();
}

int minuty = 0;
int sekundy = 0;

void loop() {
  delay(1000);
  sekundy++;
  if(sekundy > 59)
  {
    minuty++;
    sekundy = 0;
  }
  lcd.clear();
  char buf[1024];
  sprintf(buf, "%d:%d", minuty, sekundy);
  lcd.print(buf);
  

}
