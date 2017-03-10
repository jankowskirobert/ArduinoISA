#include <LiquidCrystal.h>
#include <SH1106_SPI.h>
int analogFirstX = -1;
int analogFirstY = -1;
int analogSecondX = -1;
int analogSecondY = -1;
int mappedFirstX = -1;
int mappedFirstY = -1;
int mappedSecondX = -1;
int mappedSecondY = -1;
bool observerState = false;
LiquidCrystal lcd(26, 28, 29, 30, 31, 32);
SH1106_SPI_FB oled;
void setup() {
    lcd.begin(16,2);
    initScreen();
    oled.begin();
    oled.print("Start");
    oled.renderAll();
    
}

void loop() {
  analogFirstX = analogRead(A1);
  analogFirstY = analogRead(A0);
  analogSecondY = analogRead(A10);
  analogSecondX = analogRead(A11);
mappedFirstX = map(analogFirstX, 1023, 0, 0,128);
mappedFirstY = map(analogFirstY, 1023, 0, 0,64);

     observerState = true;

  

  oled.setPixel(mappedFirstX, mappedFirstY, true);
  oled.renderAll();
  analogsDisplay();
//  delay(250);
}
void initScreen(){
  lcd.clear();
}
void analogsDisplay() {
  if( observerState){
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AX=");
  lcd.setCursor(3,0);
  lcd.print(analogFirstX);
    lcd.setCursor(0,1);
  lcd.print("AY=");
  lcd.setCursor(3,1);
  lcd.print(analogFirstY);
  
  lcd.setCursor(9,0);
  lcd.print("BX=");
  lcd.setCursor(12,0);
  lcd.print(analogSecondX);
    lcd.setCursor(9,1);
  lcd.print("BY=");
  lcd.setCursor(12,1);
  lcd.print(analogSecondY);
  
   observerState = false;
  }
  
}

