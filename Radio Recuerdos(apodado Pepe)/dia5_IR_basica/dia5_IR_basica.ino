#include <NewTone.h>

#include <IRremote.h>
#include "MatrizLed.h"

const int buzz = 9;
const int r = A0;
const int b = A2;
const int g = A1;

const int pinCSmatriz = 7;
const int pinDATAINmatriz = 12;
const int pinCLKmatriz = 11;

int dia = 5;
int mes = 5;

const byte heart[8] = {
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
};
const byte corasao[8] = {
  B00000000,
  B00101100,
  B01000010,
  B10001100,
  B01000010,
  B00101100,
  B00000000,
  B00000000
};
const byte arbol[8] = {
  B00010000,
  B00101000,
  B00101000,
  B01000100,
  B01000100,
  B10000010,
  B01101100,
  B00010000
};
const byte carita[8] = {
  B01111110,
  B10000001,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B10000001,
  B01111110
};
const byte estrella[8] = {
  B00010000,
  B10010010,
  B01010100,
  B00111000,
  B00111000,
  B01010100,
  B10010010,
  B00010000
};

const byte circulo[8] = {
  B01111110,
  B10000001,
  B10011001,
  B10100101,
  B10100101,
  B10011001,
  B10000001,
  B01111110
};

const byte carasonriente[8]{
  B00000000,
  B00000000,
  B00100100,
  B00100100,
  B00000000,
  B01000010,
  B00111100,
  B00000000
};

MatrizLed pantalla;

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

void apagarled(){
  analogWrite(r,0);
  analogWrite(g,0);
  analogWrite(b,0);
}

void funcion1(){
  analogWrite(r,255);
  analogWrite(g,230);
  analogWrite(b,0);
  delay(2000);
  analogWrite(r,240);
  analogWrite(g,120);
  analogWrite(b,240);  
  delay(3000);
  apagarled();
}

void funcion2(){
 for(int i = -8;i<32;i++){
 pantalla.escribirBits(heart,i);
}
pantalla.borrar();
}

void funcion3(){
  pantalla.escribirBits(arbol);
  pantalla.escribirBits(carita,8);
  pantalla.escribirBits(estrella,16);
  pantalla.escribirBits(circulo,24);
  delay(1000);
}

void funcion4(){
  pantalla.borrar();
  pantalla.escribirFrase("HOLA");
  cancion();
}

void cancion(){
  NewTone(buzz,440);
  delay(500);
  NewTone(buzz,311.11);
  delay(500);
  NewTone(buzz,261.11);
  delay(500);
  NewTone(buzz,426);
  delay(500);
  noNewTone(buzz);
  delay(1000); 
}

void funcion5(){
  analogWrite(r,0);
  analogWrite(g,255);
  analogWrite(b,0);
  delay(1000);
  analogWrite(r,135);
  analogWrite(g,130);
  analogWrite(b,0);
  delay(1000);
  analogWrite(r,255);
  analogWrite(g,0);
  analogWrite(b,0);
  delay(1000);
}

void funcion6(){
    pantalla.escribirFraseCompacta("InesJ");
}

void funcion7(){
  pantalla.borrar();
  analogWrite(r,0);
  analogWrite(g,0);
  analogWrite(b,255);
  pantalla.escribirFrase("Azul");
  delay(1000);
}

void funcion8(){
   ledarduino();
   rgbfav();
   noNewTone(buzz);
}

void rgbfav(){
   analogWrite(r,234);
   analogWrite(g,193);
   analogWrite(b,91);
   sonido();
   delay(1000);
}

void sonido(){
  NewTone(buzz,234);
}

void ledarduino(){
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500);    
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500);    
   digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500);   
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500);    
   digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500);  
}

void funcion9(){
   String m, d;
  if(mes<10){
    m = '0' + String(mes);
  }
  else{
    m= String(mes);
  }

  if(dia<10){
   d = '0' + String(dia);
  }
  else{
    d = String(dia);
  }
  pantalla.escribirFrase(d+m);
  separadorBarra();
  delay(1000);
}

void separadorBarra() {
  pantalla.setLed(1, 7, 0);  
  pantalla.setLed(1, 6, 0);
  pantalla.setLed(1, 5, 0);  
  pantalla.setLed(1, 4, 0);
  pantalla.setLed(1, 3, 0);  
  pantalla.setLed(1, 2, 0);
  pantalla.setLed(1, 1, 0);  
  pantalla.setLed(1, 0, 0);
}

void funcion10(){
  pantalla.borrar();
  pantalla.escribirBits(carasonriente,12);
  delay(3000);
  pantalla.borrar();
}

void funcion11(){
 pantalla.borrar();
  rojo();
  verde();
  azul();
  analogWrite(r,0);
  analogWrite(g,0);
  analogWrite(b,0);
}

void rojo(){
pantalla.borrar();
analogWrite(r,255);
analogWrite(b,0);
analogWrite(g,0); 
pantalla.escribirFrase("rojo"); 
delay(1000);
}

void verde(){
pantalla.borrar();
analogWrite(r,0);
analogWrite(b,0);
analogWrite(g,255); 
pantalla.escribirFraseCompacta("verde"); 
delay(1000);
}

void azul(){
pantalla.borrar();
analogWrite(r,0);
analogWrite(b,255);
analogWrite(g,0); 
pantalla.escribirFrase("azul"); 
delay(1000);
}

void funcion12(){
  for(int i = 0;i < 5;i++){
  pantalla.borrar();
  pantalla.escribirFrase(i);
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500);   
  Serial.println(i);
  }
  NewTone(buzz,629.11);
  delay(1000);
  noNewTone(buzz);
}

void funcion13(){
  pantalla.borrar();
  pantalla.escribirBits(corasao,12);
  delay(1000);
}

void setup()
{
   Serial.begin(9600);
   IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
   pantalla.borrar();
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);  
  pinMode(b,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pantalla.begin(pinDATAINmatriz, pinCLKmatriz, pinCSmatriz, 4); 
  pantalla.setIntensidad(2);
}

void loop()
{
  //Si se recibe una señal codificada -> decodificarla
  if (IrReceiver.decode())
  {
    if( IrReceiver.decodedIRData.decodedRawData != 0 ){
      teclaPulsada = IrReceiver.decodedIRData.command;
    }else{
      teclaPulsada = 0;
    }

    //Según el valor recibido se realiza un bloque u otro
    switch(teclaPulsada){
      case KEY_0:
         funcion1();
         break;
      case KEY_1:
        funcion2();
        break;
       case KEY_2:
         funcion3();
         break;
       case KEY_3:
         funcion4();
         break;
       case KEY_4:
         funcion5();
         break;
       case KEY_5:
         funcion6();
         break;
       case KEY_6:
         funcion7();
         break;
       case KEY_7:
         funcion8();
         break;
       case KEY_8:
         funcion9();
         break;
       case KEY_9:
         funcion10();
         break;
       case KEY_ASTERISK:
         funcion11();
         break;
       case KEY_UP:
         funcion12();
         break;
       case KEY_OK:
         funcion13();
         break;
         default:
      pantalla.borrar();
    //Reinicia el sensor para leer otro dato
  }        
        IrReceiver.resume();
  }
}
