#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Adafruit_NeoPixel.h>

#include <Servo.h>

#include <SoftwareSerial.h>

#include <SPI.h>
#include <Wire.h>


#define PIN   A3
#define NUMPIXELS 29

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

using namespace std;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SoftwareSerial bluetoothSerial(10,11);

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

Servo servo1;  // crea el objeto servo
Servo servo2;
Servo servo3;

int pos = 0;    // posicion del servo
int pulsaciones = 0;

void setup(){
  servo1.attach(3);  
  servo2.attach(6);  
  servo3.attach(5);  
  
  Serial.begin(115200);
  bluetoothSerial.begin(9600);
  
  pixels.begin();
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  // Iniciamos la librería
  //se inicia con el logo de Adafruit
  display.display();
  delay(2000); // Pausa de 2 segundos

  // Limpiamos la pantalla
  display.clearDisplay();
  display.display();
}

void loop(){
  if(bluetoothSerial.available()){
    char data_received = bluetoothSerial.read();
    Serial.println("entro");
    switch(data_received){
      case '0':
        display.clearDisplay();
        display.display();
        break;
      case '1':
        display.clearDisplay();
        display.setTextSize(2);  // tamaño de letra 2
        display.setTextColor(SSD1306_WHITE);// Texto en blanco
        display.setCursor(0,0);             // Empieza a escribir arriba a la izquierda
        display.println(F("Hola\nMundo!"));
        display.display();
        break;
      case '2':
        display.clearDisplay();
        display.setCursor(0,0);             // Empieza a escribir arriba a la izquierda
        display.setTextSize(2);  // tamaño de letra 2
        display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Fondo blanco y texto negro
        display.println(F("Hola\nMundo!"));
        display.display();
        break;
      case 'r':
        for(int i = 0; i < NUMPIXELS; i++){
          pixels.setPixelColor(i, pixels.Color(255, 0, 0));
          pixels.show();  
        }      
        break;
      case 'g':
        for(int i = 0; i < NUMPIXELS; i++){
          pixels.setPixelColor(i, pixels.Color(0, 255, 0));
        }     
                  pixels.show();  
        break;
      case 'b':
        for(int i = 0; i < NUMPIXELS; i++){
          pixels.setPixelColor(i, pixels.Color(0, 0, 255));
          pixels.show();  
        }      
        break;      
      case 'a':
        for(int i = 0; i < NUMPIXELS; i++){
          int colorR = random(0,250);
          int colorB = random(0,250);
          int colorG = random(0,250);
          pixels.setPixelColor(i, pixels.Color(colorR, colorG, colorB));
          pixels.show();  
        }
        break;
      case 'n':
        for(int i = 0; i < NUMPIXELS;i++){
          pixels.setPixelColor(i,pixels.Color(0,0,0));
          pixels.show();
        }
        break;
      case 't':
        for (pos = 0; pos <= 50; pos += 1) {
          servo1.write(pos);          
          delay(15);                       
        }
        for (pos = 50; pos >= 0; pos -= 1) {
          servo1.write(pos);          
          delay(15);                       
        }
        break;
      case 'y':
        for (pos = 90; pos >= 0; pos -= 1) {
          servo2.write(pos);          
          delay(15);                       
        }
        for (pos = 0; pos <= 90; pos += 1) {
          servo2.write(pos);          
          delay(15);                       
        }

        break;
      case 'u':
        for (pos = 0; pos <= 90; pos += 1) {
          servo3.write(pos);          
          delay(15);                       
        }
        for (pos = 90; pos >= 0; pos -= 1) {
          servo3.write(pos);          
          delay(15);                       
        }
        break;
      case 'i':
        if(pulsaciones%3 == 0){
          for (pos = 0; pos <= 50; pos += 1) {
            servo1.write(pos);          
            delay(15);                       
          }
          delay(1000);
          for (pos = 50; pos >= 0; pos -= 1) {
            servo1.write(pos);          
            delay(15);                       
          }
        }else if(pulsaciones%3 == 1){
          for (pos = 0; pos <= 50; pos += 1) {
            servo1.write(pos);                 
            delay(15);                       
          }
 
          for (pos = 90; pos >= 0; pos -= 1) {
            servo2.write(pos);                   
            delay(15);                       
          }
             delay(1000);
          for (pos = 0; pos <= 90; pos += 1) {
            servo2.write(pos);                 
            delay(15);                       
          }         
          for (pos = 50; pos >= 0; pos -= 1) {
            servo1.write(pos);                   
            delay(15);                       
          }
        }else{
          for (pos = 0; pos <= 50; pos += 1) {
            servo1.write(pos);                 
            delay(15);                       
          }
          for (pos = 0; pos <= 90; pos += 1) {
            servo3.write(pos);                 
            delay(15);                       
          }
          for (pos = 90; pos >= 0; pos -= 1) {
            servo3.write(pos);                   
            delay(15);                       
          }
             delay(1000);

          for (pos = 50; pos >= 0; pos -= 1) {
            servo1.write(pos);                   
            delay(15);                       
          }
        }
        pulsaciones++;
        break;
    }
  }
}