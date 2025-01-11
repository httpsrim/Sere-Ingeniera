#include <Adafruit_NeoPixel.h>
using namespace std;

#define NUMPIXELS 4
#define PIN 6

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

bool sigueN1 = true;
bool sigueN2 = false;
bool sigueN3 = false;
bool sigueN4 = false;
bool sigueN5 = false;

bool sigColor1 = false;
bool sigColor2 = false;
bool sigColor3 = false;
bool sigColor4 = false;

int nivel = 0;

int presion1 = A1;
int presion2 = A2;
int presion3 = A3;
int presion4 = A4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pixels.begin();
  pinMode(presion1,INPUT);
  pinMode(presion2,INPUT);
  pinMode(presion3,INPUT);
  pinMode(presion4,INPUT);
}

void loop() {
  //nivel 1
  if(sigueN1){
    pixels.setPixelColor(1,pixels.Color(0,0,255));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
  }
  sigueN1 = false;
  if(analogRead(presion2) > 20){
      pixels.setPixelColor(1,pixels.Color(0,0,255));
      pixels.show();
      delay(500);
      sigueN2 = true;
  }  
  else if(analogRead(presion1) > 20){
    pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.show();
    delay(500);
        pixels.clear();
    pixels.show();
  }
  else if(analogRead(presion3) > 50){
    pixels.setPixelColor(2, pixels.Color(255,255,0));
    pixels.show();
    delay(500);
        pixels.clear();
    pixels.show();
  }
  else if(analogRead(presion4) > 50){
    pixels.setPixelColor(0, pixels.Color(0,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
  }
    delay(500);
  if(sigueN2){
    pixels.setPixelColor(1,pixels.Color(0,0,255));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    delay(500);
    pixels.setPixelColor(3,pixels.Color(0,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
  }
  sigueN2 = false;
    if(analogRead(presion2) > 20){
      pixels.setPixelColor(1,pixels.Color(0,0,255));
      pixels.show();
      delay(500);
      pixels.clear();
      pixels.show();
      sigColor1 = true;
  }
  else if(analogRead(presion3) > 50){
    pixels.setPixelColor(2, pixels.Color(255,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
  }
  else if(analogRead(presion4) > 10 && sigColor1){
    pixels.setPixelColor(4, pixels.Color(0,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    sigueN3 = true;
  }
  delay(500);
   if(sigueN3){
    pixels.setPixelColor(1,pixels.Color(0,0,255));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    delay(500);
    pixels.setPixelColor(3,pixels.Color(0,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    pixels.setPixelColor(0,pixels.Color(255,0,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
  }
  sigueN3 = false;
    if(analogRead(presion2) > 20){
      pixels.setPixelColor(1,pixels.Color(0,0,255));
      pixels.show();
      delay(500);
      pixels.clear();
      pixels.show();
      sigColor1 = true;
  }
  else if(analogRead(presion1) > 20 && sigColor2){
    pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.show();
    delay(500);
        pixels.clear();
    pixels.show();
    sigueN4 = true;
  }
  else if(analogRead(presion3) > 50){
    pixels.setPixelColor(2, pixels.Color(255,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
  }
  else if(analogRead(presion4) > 10 && sigColor1){
    pixels.setPixelColor(3, pixels.Color(0,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    sigColor2 = true;
  }
  delay(500);

   if(sigueN4){
    pixels.setPixelColor(1,pixels.Color(0,0,255));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    delay(500);
    pixels.setPixelColor(3,pixels.Color(0,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    pixels.setPixelColor(0,pixels.Color(255,0,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    pixels.setPixelColor(2,pixels.Color(255,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
  }
  sigueN4 = false;
    if(analogRead(presion2) > 20){
      pixels.setPixelColor(1,pixels.Color(0,0,255));
      pixels.show();
      delay(500);
      pixels.clear();
      pixels.show();
      sigColor1 = true;
  }
  else if(analogRead(presion1) > 20 && sigColor2){
    pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.show();
    delay(500);
        pixels.clear();
    pixels.show();
    sigColor3 = true;
  }
  else if(analogRead(presion3) > 50 && sigColor3){
    pixels.setPixelColor(2, pixels.Color(255,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    sigueN5 = true;
  }
  else if(analogRead(presion4) > 10 && sigColor1){
    pixels.setPixelColor(4, pixels.Color(0,255,0));
    pixels.show();
    delay(500);
    pixels.clear();
    pixels.show();
    sigColor2 = true;
  }
}