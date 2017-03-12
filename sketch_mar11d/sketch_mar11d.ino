#include<ISADefinitions.h>
#include<ISALiquidCrystal.h>

ISALiquidCrystal lcd;

int counter=0;

void setup() {
  // put your setup code here, to run once:
   lcd.begin();
   for(int i = 0; i<=7; i++)
   pinMode(LEDS[i], OUTPUT);
   
   /*pinMode(KEY_LEFT,INPUT);
   pinMode(KEY_RIGHT,INPUT);*/

   digitalWrite(LEDS[0], HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pot = analogRead(POT);
  digitalWrite(LEDS[(pot/128)-1], LOW);
  digitalWrite(LEDS[pot/128], HIGH);
  digitalWrite(LEDS[(pot/128)+1], LOW);
  

  
/*  if (!digitalRead(KEY_LEFT)){
    if (counter > 0){
       counter--;
       digitalWrite(LEDS[counter], HIGH);
       digitalWrite(LEDS[counter+1], LOW);
    }
  }

  if (!digitalRead(KEY_RIGHT)){
    if (counter < 7){
       counter++;
       digitalWrite(LEDS[counter], HIGH);
       digitalWrite(LEDS[counter-1], LOW);
    }
  }
  delay(100);*/ 
}
