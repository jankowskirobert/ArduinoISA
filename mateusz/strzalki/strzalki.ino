#include <ISALedControl.h>
#include <ISADefinitions.h>
#include <ISAButtons.h>

enum {LEFT = 0, RIGHT, UP, DOWN};

ISALedControl led;
int x=0, y=0;
bool ButtonOn[4];
ISAButtons but;
void setup() {
  led.init();
  led.clearDisplay();
  x = 3;
  y = 3;
}

void loop() {
  

}
