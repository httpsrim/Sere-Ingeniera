#include <Adafruit_NeoPixel.h>
#define PIN   A4
#define NUMPIXELS 4

using namespace std;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(250, 250, 250));
    pixels.show();   
  }
}

void loop() {

    colorR = random(0,250);
    colorB = random(0,250);
    colorG = random(0,250);
    for(int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(colorR, colorG, colorB));
      pixels.show();  
    }
}
