void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.print(analogRead(A1));
  Serial.println();
}
