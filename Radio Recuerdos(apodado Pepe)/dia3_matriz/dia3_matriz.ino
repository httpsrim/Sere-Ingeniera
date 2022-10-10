#include "MatrizLed.h"

// Estos datos representan nuestros iconos. 
// Podéis añadir todos los que necesitéis pero deben tener la misma estructura y distinto nombre!
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
const byte FLECHA_DER[8] = {
  B11111111,
  B11000011,
  B10000001,
  B10011001,
  B11110011,
  B11100011,
  B11100111,
  B11111111
};

// Creamon un objeto del mundo real de tipo MatrizLed que vamos a llamar pantalla (le podéis cambiar el nombre!)
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
  // Para ejecutar cualquier operación relativa a la pantalla basta con poner su nombre y nos aparecerán las operaciones posibles
  // En programación a estas operaciones se les llama métodos mientras que a la entidad que recibe el mensaje, objeto

  // Este método borra la información que guardaba el objeto pantalla
  pantalla.borrar();

  // Podemos escribir un icono como una secuencia de bits y diciédole al método qué icono y en qué columna situarlo
  pantalla.escribirBits(FLECHA_DER);    // Si no indicamos posición, por defecto es 0
  pantalla.escribirBits(FLECHA_DER, 8);
  pantalla.escribirBits(FLECHA_DER, 16);
  pantalla.escribirBits(FLECHA_DER, 24);
  delay(1000);
  pantalla.borrar();


  // Para escribir una frase disponemos del método escribirFrase que escribirá tantos caracteres como pantallas tengamos.
  pantalla.escribirFrase("UwU");   //Posición por defecto 0
  delay(1000);
  pantalla.borrar();
  
  // Para escribir una frase disponemos del método escribirFrase que escribirá tantos caracteres como pantallas tengamos.
  pantalla.escribirFrase("ewe",4);
  delay(1000);
  pantalla.borrar();

  // También podemos usar el siguiente método para escribir de forma más compacta
  pantalla.escribirFraseCompacta("OwO");
  delay(1000);
  pantalla.borrar();

  // Este método escribe una frase larga de forma interactiva. Las letras se desplazan por la pantalla
  // Se puede indicar una pausa como segundo parámetro del método para que vaya más lento
  // (No se puede más rápido, Arduino tampoco es un avión)
  pantalla.escribirFraseScroll("awa");
  delay(1000);
  pantalla.borrar();

  pantalla.escribirCifra(3210);
  delay(1000);


  //Método que coge dos variables numéricas (minutos y segundos) y las muestra separadas por :
  mostrarMinutosSegundos();

  // Si tras escribir un mensaje, icono o cualquier otro caracter predefinido queremos añadir leds, debemos hacerlo después
  // Esto ocurre porque cada número, letra o icono ocupa 8x8 leds y borra lo que esté abajo así que la única forma de añadir tildes, puntos, comas... es con setLed
  pantalla.setLed(1, 5, 0); // Se debe indicar: nMatriz, Fila y Columna. Utiliza la tabla proporcionada para entenderlo!
  pantalla.setLed(1, 4, 0);
  delay(1000);
  pantalla.borrar();
}


void mostrarMinutosSegundos(){
  String min, seg;
  if(minutos<10){
    min = '0' + String(minutos);
  }else{
    min = String(minutos);
  }

  if(segundos<10){
    seg = '0' + String(segundos);
  }else{
    seg = String(segundos);
  }

  pantalla.escribirFrase(min+seg);
  separadorDosPuntos();
}

void separadorDosPuntos(){
  pantalla.setLed(1, 5, 0); // Se debe indicar: nMatriz, Fila y Columna. Utiliza la tabla proporcionada para entenderlo!
  pantalla.setLed(1, 2, 0);
}
