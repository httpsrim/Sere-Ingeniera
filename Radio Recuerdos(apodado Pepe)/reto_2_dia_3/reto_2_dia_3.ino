#include "MatrizLed.h"
const byte BARRA_SONIDO[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};
const byte iconito[8] = {
  B00100100,
  B00011000,
  B00111100,
  B11011011,
  B11111111,
  B11111111,
  B10011001,
  B11100111
};

MatrizLed pantalla;

// Contador para mostrar un ejemplo de uso con cifras que incrementan
int minutos = 1;
int segundos = 10;

void mostrarmarcianito(){
  pantalla.escribirBits(iconito,12); 
  delay(1000);
  pantalla.borrar();  
}


void setup() {
  pantalla.begin(12, 11, 7, 4); 
  pantalla.setIntensidad(2);
}

void loop() {
  mostrarmarcianito();
  pantalla.escribirFraseScroll("Ines");  
  delay(1000);
  pantalla.borrar();
  pantalla.escribirFraseScroll("SereIngeniera",4);
  delay(1000);
  pantalla.borrar();
  pantalla.escribirFraseScroll("2021");
  delay(1000);
  pantalla.borrar();
  pantalla.escribirFraseScroll("OwO");
  delay(1000);
  pantalla.borrar();
  mostrarmarcianito();
}
