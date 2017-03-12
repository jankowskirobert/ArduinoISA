#include <ISALiquidCrystal.h>
#include <ISAButtons.h>

ISALiquidCrystal lcd;
ISAButtons btn;

char a[16];
char b[16];
char znak;

int i,j;

void setup() {
  lcd.begin();
  btn.init();
  
}

void loop() {
  
    if(btn.buttonPressed(8)){
      lcd.print(1);
    }

    if(btn.buttonPressed(9)){
      lcd.print(2);
    }

    if(btn.buttonPressed(10)){
      lcd.print(3);
    }

    if(btn.buttonPressed(4)){
      lcd.print(4);
    }

    if(btn.buttonPressed(5)){
      lcd.print(6);
    }

    if(btn.buttonPressed(6)){
      lcd.print(5);
    }

    if(btn.buttonPressed(0)){
      lcd.print(7);
    }

    if(btn.buttonPressed(7)){
      lcd.print(4);
    }

    if(btn.buttonPressed(1)){
      lcd.print(8);
    }

    if(btn.buttonPressed(2)){
      lcd.print(9);
    }

    if(btn.buttonPressed(14)){
      lcd.print(0);
    }

    if(btn.buttonPressed(15)){
      lcd.clear();
    }
    delay(40);

}
