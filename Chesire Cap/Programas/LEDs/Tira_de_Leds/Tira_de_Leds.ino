  #include <Adafruit_NeoPixel.h>
  #define PIN   A3
  #define NUMPIXELS 29

  using namespace std;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
bool primeraVez = true;

void setup() {
  Serial.begin(9600);
  pixels.begin();
  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(250, 250, 250));
    pixels.show();   
  }
}

void loop() {


    if(primeraVez){
      for(int i = 0; i < NUMPIXELS; i++){
        int colorR = random(0,250);
        int colorB = random(0,250);
        int colorG = random(0,250);
        pixels.setPixelColor(i, pixels.Color(colorR, colorG, colorB));
        pixels.show();  
      }
    }
    delay(2000);
    primeraVez = false;
        if(!primeraVez){
      for(int i = 0; i < NUMPIXELS; i++){
        int colorR = random(0,250);
        int colorB = random(0,250);
        int colorG = random(0,250);
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        pixels.show();  
      }
        }
}
