#include <Adafruit_NeoPixel.h>
#define PIN   A4
#define NUMPIXELS 4

using namespace std;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

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
int cambiarLed = 0;
int musica = 0;
int leds = 0;

int r = A1;
int b = A2;
int g = A3;

int buzzer = 9;

int colorR = 0;
int colorB = 0;
int colorG = 0;

void setup() {
  Serial.begin(9600);
  pixels.begin();
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

  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(250, 250, 250));
    pixels.show();   
  }
}

void PinkFloyd(){
 tone(buzzer,239.665);
 delay(350);
 noTone(buzzer);
 delay(50);
 tone(buzzer,329.628);
 delay(420);
 noTone(buzzer);
 delay(50);
 tone(buzzer,349.228);
 delay(350);
 noTone(buzzer);
 delay(50);
 tone(buzzer,329.628);
 delay(500);
 noTone(buzzer);
 delay(400);
 tone(buzzer,239.665);
 delay(350);
 noTone(buzzer);
 delay(50);
 tone(buzzer,329.628);
 delay(450);
 noTone(buzzer);
 delay(50);
 tone(buzzer,349.228);
 delay(350);
 noTone(buzzer);
 delay(50);
 tone(buzzer,329.628);
 delay(600);
 noTone(buzzer);
 delay(350);
 tone(buzzer,239.665);
 delay(350);
 noTone(buzzer);
 delay(50);
 tone(buzzer,329.628);
 delay(450);
 noTone(buzzer);
 delay(50);
 tone(buzzer,349.228);
 delay(450);
 noTone(buzzer);
 delay(450);
}
void sweetdreams(){
  
  tone(buzzer,311.13);
  delay(400);
  noTone(buzzer);
  delay(50);
  
   tone(buzzer,311.13);
  delay(380);
  noTone(buzzer);
  delay(50);
  
  tone(buzzer,261.63);
  delay(350);
  noTone(buzzer);
  delay(50);
  
  tone(buzzer,311.13);
  delay(230);
  noTone(buzzer);
  delay(50);
  
  tone(buzzer,311.13);
  delay(380);
  noTone(buzzer);
  delay(50);

  tone(buzzer,311.13);
  delay(350);
  noTone(buzzer);
  delay(50); 
  
  tone(buzzer,293.67);
  delay(520);
  noTone(buzzer);
  delay(50); 

  tone(buzzer,311.13);
  delay(270);
  noTone(buzzer);
  delay(50); 

  tone(buzzer,311.13);
  delay(200);
  noTone(buzzer);
  delay(50); 
 
  tone(buzzer,261.63);
  delay(300);
  noTone(buzzer);
  delay(50);

  tone(buzzer,311.13);
  delay(480);
  noTone(buzzer);
  delay(50); 
  
  tone(buzzer,311.13);
  delay(260);
  noTone(buzzer);
  delay(50); 
   
   tone(buzzer,261.63);
  delay(250);
   noTone(buzzer);
  delay(50);

  tone(buzzer,311.13);
  delay(280);
  noTone(buzzer);
  delay(50);

  tone(buzzer,349.23);
  delay(375);
  noTone(buzzer);
  delay(50); 
  
  tone(buzzer,311.13);
  delay(255);
  noTone(buzzer);
  delay(50);

  tone(buzzer,293.67);
  delay(300);
  noTone(buzzer);
  delay(50);
}
void loop() {


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
    tone(buzzer,321.3);
    delay(200);
  }
  if (digitalRead(boton2) == LOW) {
    reNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton3) == HIGH) {
    miNota = true;
    tone(buzzer,410);
    delay(200);
  }
  if (digitalRead(boton3) == LOW) {
    miNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton4) == HIGH) {
    faNota = true;
    tone(buzzer,536);
    delay(200);
  }
  if (digitalRead(boton4) == LOW) {
    faNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton5) == HIGH) {
    solNota = true;
    tone(buzzer,646);
    delay(200);
  }
  if (digitalRead(boton5) == LOW) {
    solNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton6) == HIGH) {
    laNota = true;
    tone(buzzer,943);
    delay(200);
  }
  if (digitalRead(boton6) == LOW) {
    laNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton7) == HIGH) {
    siNota = true;
    tone(buzzer,523);
    delay(200);
  }
  if (digitalRead(boton7) == LOW) {
    siNota = false;
    noTone(buzzer);
  }
    if (digitalRead(boton8) == HIGH) {
     musica = true;
     sweetdreams();
  }
  if (digitalRead(boton8) == LOW) {
    musica = false;
    noTone(buzzer);

  }
  if (digitalRead(boton9) == HIGH) {
    leds = true;
    colorR = random(0,250);
    colorB = random(0,250);
    colorG = random(0,250);
    for(int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(colorR, colorG, colorB));
      pixels.show();  
    }
  }
  if (digitalRead(boton9) == LOW) {
    leds = false;
    noTone(buzzer);
  }
}
