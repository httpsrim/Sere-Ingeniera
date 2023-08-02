int boton1 = 2;
int boton2 = 3;
int boton3 = 4;
int boton4 = 5;
int boton5 = 6;
int boton6 = 7;
int boton7 = 8;
int boton8 = 10;
int boton9 = 11;

int doNota = 0;
int reNota = 0;
int miNota = 0;
int faNota = 0;
int solNota = 0;
int laNota = 0;
int siNota = 0;
int DoNota = 0;
int SiNota = 0;

int r = A1;
int b = A2;
int g = A3;

int buzzer = 9;
void setup() {
  Serial.begin(9600);
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  pinMode(boton4, INPUT);
  pinMode(boton5, INPUT);
  pinMode(boton6, INPUT);
  pinMode(boton7, INPUT);
  pinMode(boton8, INPUT);
  pinMode(boton9, INPUT);

  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(r, random(0, 250));
  digitalWrite(g, random(0, 250));
  digitalWrite(b, random(0, 250));

  if (digitalRead(boton1) == HIGH) {
    doNota = true;
    tone(buzzer,446);
    delay(200);
  }
  if (digitalRead(boton1) == LOW) {
    doNota = false;
    noTone(buzzer);
  }
  if (digitalRead(boton2) == HIGH) {
    reNota = true;
    tone(buzzer,446);
    delay(200);
  }
  if (digitalRead(boton2) == LOW) {
    reNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton3) == HIGH) {
    miNota = true;
    tone(buzzer,446);
    delay(200);
  }
  if (digitalRead(boton3) == LOW) {
    miNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton4) == HIGH) {
    faNota = true;
    tone(buzzer,446);
    delay(200);
  }
  if (digitalRead(boton4) == LOW) {
    faNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton5) == HIGH) {
    solNota = true;
    tone(buzzer,446);
    delay(200);
  }
  if (digitalRead(boton5) == LOW) {
    solNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton6) == HIGH) {
    laNota = true;
    tone(buzzer,446);
    delay(200);
  }
  if (digitalRead(boton6) == LOW) {
    laNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton7) == HIGH) {
    siNota = true;
    tone(buzzer,446);
    delay(200);
  }
  if (digitalRead(boton7) == LOW) {
    siNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton8) == HIGH) {
    DoNota = true;
    tone(buzzer,446);
    delay(200);
  }
  if (digitalRead(boton8) == LOW) {
    DoNota = false;
    noTone(buzzer);

  }
    if (digitalRead(boton9) == HIGH) {
    SiNota = true;
    tone(buzzer,446);
    delay(200);
  }
  if (digitalRead(boton9) == LOW) {
    SiNota = false;
    noTone(buzzer);

  }
  /*
    si se pulsa un boton especial se le añade 1 a una variable. Se vambia el valor de los leds, o .... que vaya grabando unas notas 
    Boton: elegir modo manual, modo automatico, modo programador, cambiar valor de los leds.... etc.
  */
}
