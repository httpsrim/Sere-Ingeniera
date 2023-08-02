int boton = 2;
int valor = 0;
void setup() {
  Serial.begin(9600);
  pinMode(boton,INPUT);
}

void loop() {
   valor = digitalRead(boton);
   if(valor == HIGH) Serial.prinln("Encendido");
   else Serial.prinln("Apagado");
   delay(1000);
}
