int boton1 = 2;
int boton2 = 3;
int boton3 = 4;
int boton4 = 5;
int boton5 = 6;
int boton6 = 7;
int boton7 = 8;
int boton8 = 9;
int boton9 = 13;

int r = A1;
int b = A2;
int g = A3;

int buzzer = 13;
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

  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(b,OUTPUT);

  pinMode(buzzer,OUTPUT);
}

void loop() {
  digitalWrite(r,random(0,250));
  digitalWrite(g, random(0,250));
  digitalWrite(b, random(0,250));

   if(digitalRead(boton1) == HIGH){
      tone(buzzer,256.1);
      delay(500);
      noTone(buzzer);
   }
   else noTone(buzzer);
    if(digitalRead(boton2) == HIGH){
      tone(buzzer,256.1);
      delay(500);
      noTone(buzzer);
   }
   else noTone(buzzer);
    if(digitalRead(boton3) == HIGH) {
      tone(buzzer,256.1);
      delay(500);
      noTone(buzzer);
      }
   else noTone(buzzer);
    if(digitalRead(boton4) == HIGH){
      tone(buzzer,256.1);
      delay(500);
      noTone(buzzer);
      }
   else noTone(buzzer);
    if(digitalRead(boton5) == HIGH){
      tone(buzzer,256.1);
      delay(500);
      noTone(buzzer);
    }
   else noTone(buzzer);
    if(digitalRead(boton6) == HIGH){
      tone(buzzer,256.1);
      delay(500);
      noTone(buzzer);
    }
   else noTone(buzzer);
    if(digitalRead(boton7) == HIGH) {
      tone(buzzer,256.1);
      delay(500);
      noTone(buzzer);
    }
   else noTone(buzzer);
      if(digitalRead(boton8) == HIGH){
      tone(buzzer,256.1);
      delay(500);
      noTone(buzzer);
    }
    else noTone(buzzer);
    if(digitalRead(boton9) == HIGH){
      tone(buzzer,256.1);
      delay(500);
      noTone(buzzer);
    }
   else noTone(buzzer);
 
   delay(1000);
}
