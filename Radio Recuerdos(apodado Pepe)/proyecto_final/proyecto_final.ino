#include <NewTone.h>
#include <IRremote.h>
#include "MatrizLed.h"
const byte FLECHA_DER[8] = {
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
  };
const int buzz = 9;
const int r = A2;
const int b = A1;
const int g = A2;

const int pinCSmatriz = 7;
const int pinDATAINmatriz = 12;
const int pinCLKmatriz = 11;
const int RECV_PIN = 8;

const int KEY_UP = 24;
const int KEY_LEFT = 8;
const int KEY_OK = 28;
const int KEY_RIGHT = 90;
const int KEY_DOWN = 82;
const int KEY_1 = 69;
const int KEY_2 = 70;
const int KEY_3 = 71;
const int KEY_4 = 68;
const int KEY_5 = 64;
const int KEY_6 = 67;
const int KEY_7 = 7;
const int KEY_8 = 21;
const int KEY_9 = 9;
const int KEY_0 = 25;
const int KEY_ASTERISK = 22;
const int KEY_POUND = 13;

int teclaPulsada;


MatrizLed pantalla;
  
void sweetdreams(){
  pantalla.escribirFraseCompactaScroll("SweerDreams");
  analogWrite(r,2);
  analogWrite(b,210);
  analogWrite(g,55);
  
  NewTone(buzz,311.13);
  delay(400);
  noNewTone(buzz);
  delay(50);
  
   NewTone(buzz,311.13);
  delay(380);
  noNewTone(buzz);
  delay(50);
  
  NewTone(buzz,261.63);
  delay(350);
  noNewTone(buzz);
  delay(50);
  
  NewTone(buzz,311.13);
  delay(230);
  noNewTone(buzz);
  delay(50);
  
  NewTone(buzz,311.13);
  delay(380);
  noNewTone(buzz);
  delay(50);

  NewTone(buzz,311.13);
  delay(350);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,293.67);
  delay(520);
  noNewTone(buzz);
  delay(50); 

  NewTone(buzz,311.13);
  delay(270);
  noNewTone(buzz);
  delay(50); 

  NewTone(buzz,311.13);
  delay(200);
  noNewTone(buzz);
  delay(50); 
 
  NewTone(buzz,261.63);
  delay(300);
  noNewTone(buzz);
  delay(50);

  NewTone(buzz,311.13);
  delay(480);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,311.13);
  delay(260);
  noNewTone(buzz);
  delay(50); 
   
   NewTone(buzz,261.63);
  delay(250);
   noNewTone(buzz);
  delay(50);

  NewTone(buzz,311.13);
  delay(280);
  noNewTone(buzz);
  delay(50);

  NewTone(buzz,349.23);
  delay(375);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,311.13);
  delay(255);
  noNewTone(buzz);
  delay(50);

  NewTone(buzz,293.67);
  delay(300);
  noNewTone(buzz);
  delay(50);
}
void piratas(){
  pantalla.escribirFraseCompactaScroll("PiratasDelCaribe");
  analogWrite(r,25);
  analogWrite(b,185);
  analogWrite(g,255);
  
  NewTone(buzz,329.628);
  delay(160);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,391.995);
  delay(200);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,440);
  delay(250);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,440);
  delay(250);
   noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,440);
  delay(200);
  noNewTone(buzz);
  delay(50); 

  NewTone(buzz,493.883);
  delay(200);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,523.25);
  delay(220);
   noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,523.25);
  delay(250);
   noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,523.25);
  delay(200);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,587.33);
  delay(200);
  noNewTone(buzz);
  delay(50); 

  NewTone(buzz,493.883);
  delay(250);
   noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,493.883);
  delay(230);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,440);
  delay(200);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,391.994);
  delay(170);
  noNewTone(buzz);
  delay(50); 
  
  NewTone(buzz,440);
  delay(200);
  noNewTone(buzz);
  delay(50); 
  
  
}

void PinkFloyd(){
  pantalla.escribirFraseCompactaScroll("TheWall");
  NewTone(buzz,239.665);
 delay(350);
 noNewTone(buzz);
 delay(50);
 NewTone(buzz,329.628);
 delay(420);
 noNewTone(buzz);
 delay(50);
 NewTone(buzz,349.228);
 delay(350);
 noNewTone(buzz);
 delay(50);
 NewTone(buzz,329.628);
 delay(500);
 noNewTone(buzz);
 delay(400);
 NewTone(buzz,239.665);
 delay(350);
 noNewTone(buzz);
 delay(50);
 NewTone(buzz,329.628);
 delay(450);
 noNewTone(buzz);
 delay(50);
 NewTone(buzz,349.228);
 delay(350);
 noNewTone(buzz);
 delay(50);
 NewTone(buzz,329.628);
 delay(600);
 noNewTone(buzz);
 delay(350);
 NewTone(buzz,239.665);
 delay(350);
 noNewTone(buzz);
 delay(50);
 NewTone(buzz,329.628);
 delay(450);
 noNewTone(buzz);
 delay(50);
 NewTone(buzz,349.228);
 delay(450);
 noNewTone(buzz);
 delay(450);
}

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  pantalla.borrar();
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);  
  pinMode(b,OUTPUT);
  pantalla.begin(pinDATAINmatriz, pinCLKmatriz, pinCSmatriz, 4); 
  pantalla.setIntensidad(2);
  analogWrite(r,255);
  analogWrite(b,255);
  analogWrite(g,255);
  pantalla.escribirFraseCompactaScroll("RadioRecuerdos");
  pantalla.borrar();
}

void loop() {
  pantalla.escribirFraseCompactaScroll("SelectMusic"); 
  analogWrite(r,255);
  analogWrite(b,255);
  analogWrite(g,255);
  noNewTone(buzz);
 if (IrReceiver.decode())
  {
    if( IrReceiver.decodedIRData.decodedRawData != 0 ){
      teclaPulsada = IrReceiver.decodedIRData.command;
    }else{
      teclaPulsada = 0;
    }
    switch(teclaPulsada){
      case KEY_0:
        sweetdreams();
         break;
      case KEY_1:
        piratas();
        break;
      case KEY_2:
       PinkFloyd();
         break;
  }        
        IrReceiver.resume();
  }
}

/*Querido programador, o programadora:
 * Cuando escribí este código, sólo Dios y yo 
 * sabíamos cómo funcionaba.
 * Ahora,¡sólo Dios lo sabe!
 * 
 * A si que si está tratandp de "optimizar"
 * esta rutina y fracasa (seguramente),
 * por favor, incremente el siguiente contador
 * como una advertencia
 * para el siguiente colega:
 * total_horas_perdidas_aqui = 108
 */
