/*#include <SoftwareSerial.h>


SoftwareSerial bluetoothSerial(10,11);

void setup(){
  Serial.begin(9600);
  bluetoothSerial.begin(9600);
  // Comprbamos que la pantalla funciona correctamente
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

  delay(2000);
}

void loop(){
  if(bluetoothSerial.available()){
    char data_received = bluetoothSerial.read();
    if(data_received == '1'){
      display.clearDisplay();
      display.setTextSize(1);  // tamaño de letra 1
      display.setTextColor(SSD1306_WHITE);// Texto en blanco
      display.setCursor(0,0);             // Empieza a escribir arriba a la izquierda
      display.println(F("Hola Mundo!"));
    }
    else if(data_received == '2'){
      display.clearDisplay();
      display.setCursor(0,0);  
      display.setTextSize(1);  // tamaño de letra 1
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Fondo blanco y texto negro
      display.println("Hola Mundo!");
    }
    else{
      Serial.println(data_received);
      bluetoothSerial.write("Select either 1 or 2\n");
    }
  }
}*/

#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SoftwareSerial bluetoothSerial(10,11);

int led = 13;

void setup(){
  pinMode(led,OUTPUT);
  Serial.begin(115200);
  bluetoothSerial.begin(9600);
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
    bluetoothSerial.write("Select either 1 or 2 for texts, 0 to turn it off");
    char data_received = bluetoothSerial.read();
    if(data_received == '1'){
      display.clearDisplay();
      display.setTextSize(2);  // tamaño de letra 2
      display.setTextColor(SSD1306_WHITE);// Texto en blanco
      display.setCursor(0,0);             // Empieza a escribir arriba a la izquierda
      display.println(F("Hola\nMundo!"));
      display.display();
    }
    else if(data_received == '2'){
      display.clearDisplay();
      display.setCursor(0,0);             // Empieza a escribir arriba a la izquierda
      display.setTextSize(2);  // tamaño de letra 2
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Fondo blanco y texto negro
      display.println(F("Hola\nMundo!"));
      display.display();
    }
    else if(data_received == '0'){
      display.clearDisplay();
      display.display();
    }
  }
}