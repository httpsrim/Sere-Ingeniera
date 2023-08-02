int boton1 = 1;
int boton2 = 2;
int boton3 = 3;
int boton4 = 4;
int boton5 = 5;
int boton6 = 6;
int boton7 = 7;
int boton8 = 8;
int boton9 = 9;
int boton10 = 10;
int boton11 = 11;
int boton12 = 12;
int boton13 = 13;
int boton14 = 14;

void setup() {
  Serial.begin(9600);
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  pinMode(boton4,INPUT);
  pinMode(boton5,INPUT);
  pinMode(boton6,INPUT);
  pinMode(boton7,INPUT);
  pinMode(boton8,INPUT);
  pinMode(boton9,INPUT);
  pinMode(boton10,INPUT);
  pinMode(boton11,INPUT);
  pinMode(boton12,INPUT);
  pinMode(boton13,INPUT);
  pinMode(boton14,INPUT);
}

void loop() {
   if(digitalRead(boton1) == HIGH) Serial.prinln("Encendido 1");
   else Serial.prinln("Apagado 1");
      if(digitalRead(boton2) == HIGH) Serial.prinln("Encendido 2");
   else Serial.prinln("Apagado 2");
      if(digitalRead(boton3) == HIGH) Serial.prinln("Encendido 3");
   else Serial.prinln("Apagado 3");
      if(digitalRead(boton4) == HIGH) Serial.prinln("Encendido 4");
   else Serial.prinln("Apagado 4");
      if(digitalRead(boton5) == HIGH) Serial.prinln("Encendido 5");
   else Serial.prinln("Apagado 5");
      if(digitalRead(boton6) == HIGH) Serial.prinln("Encendido 6");
   else Serial.prinln("Apagado 6");
      if(digitalRead(boton7) == HIGH) Serial.prinln("Encendido 7");
   else Serial.prinln("Apagado 7");
      if(digitalRead(boton8) == HIGH) Serial.prinln("Encendido 8");
   else Serial.prinln("Apagado 8");
      if(digitalRead(boton9) == HIGH) Serial.prinln("Encendido 9");
   else Serial.prinln("Apagado 9");
      if(digitalRead(boton10) == HIGH) Serial.prinln("Encendido 10");
   else Serial.prinln("Apagado 10");
      if(digitalRead(boton11) == HIGH) Serial.prinln("Encendido 11");
   else Serial.prinln("Apagado 11");
      if(digitalRead(boton12) == HIGH) Serial.prinln("Encendido 12");
   else Serial.prinln("Apagado 12");
      if(digitalRead(boton13) == HIGH) Serial.prinln("Encendido 13");
   else Serial.prinln("Apagado 13");
      if(digitalRead(boton14) == HIGH) Serial.prinln("Encendido 14");
   else Serial.prinln("Apagado 14");
   delay(1000);
}
