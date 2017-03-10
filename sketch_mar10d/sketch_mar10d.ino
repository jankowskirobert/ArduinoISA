void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
}

void loop() {
  int pot = analogRead(A9);
  analogWrite(2,pot);
  Serial.println(pot);
  delay(250);

}
