int sensorPresion = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(INPUT,sensorPresion);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("El sensor tiene un valor: ");
  Serial.println(analogRead(sensorPresion));
  delay(1000);
}
