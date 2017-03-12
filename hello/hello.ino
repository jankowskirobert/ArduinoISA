#include <ISALiquidCrystal.h>
ISALiquidCrystal lcd;
int i = 0;
int mins = 0;
int sec = 0;
char out[6];
void setup() {
  lcd.begin();
  //lcd.print("hello, world!");

}

void loop() {
  sec = i % 60;
  mins = i / 60;
  lcd.clear();
  out[0]='0'+(mins/10);
  out[1]='0'+(mins%10);
  out[2]=':';
  out[3]='0'+(sec/10);
  out[4]='0'+(sec%10);
  out[5]='\0';
  lcd.print(out);
  i=i+1;
  delay(1000);
}
