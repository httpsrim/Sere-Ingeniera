#include "MatrizLed.h"

//Declaramos una variable para guardar el número del pin donde hemos conectado el Buzzer
const int pinBuzzer = 9;
const int pinPulsador = 2;
const int pinActivarAlarma = 3;

const int pinCSmatriz = 7;
const int pinDATAINmatriz = 12;
const int pinCLKmatriz = 11;

//Tabla de 10 celdas, en cada celda un valor decimal
const float tonos[] = { 987.77, 987.77, 987.77, 1174.66, 880, 987.77, 987.77, 987.77, 1174.66, 987.77, 987.77, 494 };
//Tabla de 10 celdas que representa el tiempo de duración de cada tono de la tabla anterior. Debe coincidir en número de elementos
const float tiempos[] = { 100, 50, 50, 100, 75, 50, 75, 100, 50, 50 };

//Constante guarda número de elementos de la tabla
const int nTonos = 10;

//Variable para controlar la posición de la tabla actual
int nTonoActual = 0;

//Las variables volatile pueden cambiar su valor dentro de las funciones de interrupción
//Creamos una variable para controlar si el boton se ha pulsado
volatile boolean alarmaOFF = false;

// Este dato representa nuestro icono.
const byte FLECHA_DER[8] = {
  B00001000,
  B00001100,
  B11111110,
  B11111111,
  B11111110,
  B00001100,
  B00001000,
  B00000000
};

// Creamon un objeto del mundo real de tipo MatrizLed que vamos a llamar pantalla (le podéis cambiar el nombre!)
MatrizLed pantalla;

// Contador para mostrar un ejemplo de uso con cifras que incrementan
int minutos = 1;
int segundos = 30;

void pararAlarma() {
  //Establecemos la variable de control a verdadero
  alarmaOFF = true;
}

void activarAlarma() {
  //Establecemos la variable de control a verdadero
  alarmaOFF = false;
}

void sonarNota(int x) {
  //tonos[x] nos permite acceder al tono de la posición x de la tabla -> Así vamos pasando por todos los tonos
  tone(pinBuzzer, tonos[x]);
  delay(tiempos[x]);
  noTone(pinBuzzer);
  delay(50);
}

void mostrarMinutosSegundos(){
  //Estas variables representan los dígitos que se van a mostrar por pantalla
  String min, seg;
  if(minutos<10){
    min = '0' + String(minutos);
  }else{
    min = String(minutos);
  }

  if(segundos<10){
   seg = '0' + String(segundos--);
  }else{
    seg = String(segundos--);
  }
  pantalla.escribirFrase(min+seg);
  separadorDosPuntos();
}

// Función que representa " : "
void separadorDosPuntos() {
  pantalla.setLed(1, 5, 0);  // Se debe indicar: nMatriz, Fila y Columna. Utiliza la tabla proporcionada para entenderlo!
  pantalla.setLed(1, 2, 0);
}

void lanzarTemporizador() {
   while (minutos>0 || segundos>0){
  mostrarMinutosSegundos();
    if (segundos>0){
     segundos-1;
    }
    else if(minutos>0){  
    minutos = minutos-1;
    segundos = 59; //????
    } 
  Serial.println(minutos);
  Serial.println(segundos);

    //**Aquí podéis encender el led de algún color
    delay(775);
    //**Aquí deberíais apagar el led
  }
}

void setup() {
  Serial.begin(9600);
  // Inicializamos el objeto creado diciendo dónde está conectado y cuántas pantallas tiene
  pantalla.begin(pinDATAINmatriz, pinCLKmatriz, pinCSmatriz, 4);  // dataPin, clkPin, csPin, numero de matrices de 8x8
  // Podemos cambiar el brillo de nuestra pantalla (entre 0 y 15)
  pantalla.setIntensidad(2);

  //Declaro el pin del botón como un pin de lectura (PULL_UP indica el modo de conexión del botón)
  pinMode(pinPulsador, INPUT_PULLUP);
  pinMode(pinActivarAlarma, INPUT_PULLUP);

  //Declaramos el led interno para poder usarlo
  pinMode(LED_BUILTIN, OUTPUT);

  //Esta función establece una conexión inmediata entre el pulsador y la función alarma
  attachInterrupt(digitalPinToInterrupt(pinPulsador), pararAlarma, RISING);
  attachInterrupt(digitalPinToInterrupt(pinActivarAlarma), activarAlarma, RISING);


  //RETO 3 AMPLIACIÓN
  for(int i=-8 ; i<32 ; i++){
    pantalla.escribirBits(FLECHA_DER, i);
    delay(100);
    pantalla.borrar();
  }
}

void loop() {
 
  //Si la alarma no está OFF, es decir, la alarma está activa, lanzamos el temporizador
  if (alarmaOFF == false) {
    lanzarTemporizador();
    pantalla.escribirFrase("BOOM");

    while (alarmaOFF == false) {  //Más eficiente si ponemos while(!alarmaOFF){...}
      sonarNota(nTonoActual);
      nTonoActual = (nTonoActual + 1) % 10;
    }
  }
  else{
    pantalla.borrar();
  }
  
}
