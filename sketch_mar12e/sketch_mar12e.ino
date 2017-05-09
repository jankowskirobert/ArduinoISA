#include <ISADefinitions.h>
void setup() {
 pinMode(LED8, OUTPUT);
 Serial1.begin(9600);
}
bool state = false;
const char* tekst = "Ala ma kota\n";
int counter = 0;
void loop() {
 char ch = tekst[counter];
 counter = (counter + 1) % strlen(tekst);
 digitalWrite(LED8, state=!state);
 Serial1.print(ch);
 delay(150);
}
