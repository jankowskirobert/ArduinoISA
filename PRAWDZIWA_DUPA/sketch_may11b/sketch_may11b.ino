#include <ISADefinitions.h>
#include <ISALedControl.h>
#include <ISALiquidCrystal.h>

ISALiquidCrystal lcd;
ISALedControl led;
int joy1_x = 0;
int joy1_y = 0;
void setup() {
  for (int i = 0 ; i < 7; i++){
    pinMode(LEDS[i], OUTPUT);
  }
  
  Serial.begin(9600);
  lcd.begin();
  led.init();
}

void loop() {
  joy1_x = analogRead(JOY1X);
  joy1_y = analogRead(JOY1Y);
  delay(50);
  barrier(3,3);
  remapToDisplay(joy1_x, joy1_y,3,3);
}

void remapToDisplay(int angIn_X, int angIn_Y, int barrier_x, int barrier_y){
  led.clearDisplay();
  lcd.clear();
  int tmp_x = map(angIn_X, 0, 1015, 7 ,0);
  
  lcd.setCursor(0,0);
  lcd.print("J1X:");
  lcd.setCursor(5,0);
  lcd.print(tmp_x);
  lcd.setCursor(0,1);
  lcd.print(angIn_X);

  int tmp_y = map(angIn_Y, 40, 1015, 7 ,0);
  
  lcd.setCursor(10,0);
  lcd.print("J1Y:");
  lcd.setCursor(15,0);
  lcd.print(tmp_y);
  lcd.setCursor(10,1);
  lcd.print(angIn_Y);

  int val = map(tmp_x, 0, 8, 0, 255);
  ledBright(val);
  led.setLed(tmp_y, tmp_x, true);
}

void ledBright(int val){
  analogWrite(LEDS[1], val);
}

void barrier(int x, int y) {
  led.setLed(y, x, true);
}

