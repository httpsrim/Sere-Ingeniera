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

void setup() {
  // Inicializamos el objeto creado diciendo dónde está conectado y cuántas pantallas tiene
  pantalla.begin(12, 11, 7, 4); // dataPin, clkPin, csPin, numero de matrices de 8x8
  // Podemos cambiar el brillo de nuestra pantalla (entre 0 y 15)
  pantalla.setIntensidad(2);
  //Método por si tu modelo es tiene el código 1088A5 en el mismo lado que -> in out-> . Descomentar
  //pantalla.setModelo(1);
}

void loop() {
  mostrarcorasao();
}

void mostrarcorasao(){
  pantalla.escribirBits(iconito); 
  pantalla.escribirBits(iconito,8); 
  pantalla.escribirBits(iconito,16);
  pantalla.escribirBits(iconito,24);  
}
}
