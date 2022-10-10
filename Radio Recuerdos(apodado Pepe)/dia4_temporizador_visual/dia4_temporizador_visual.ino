#include "MatrizLed.h"

//Declaramos una variable para guardar el número del pin donde hemos conectado el Buzzer
const int buzz = 9;
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
const int r = A0;
const int b = A2;
const int g = A1;

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
  tone(buzz, tonos[x]);
  delay(tiempos[x]);
  noTone(buzz);
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
    delay(775);
  }
}

void setup() {
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);  
  pinMode(b,OUTPUT);
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

void apagarled(){
  analogWrite(r,0);
  analogWrite(g,0);
  analogWrite(b,0);
  delay(1000);
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
  tone(buzz,440);
  delay(500);
  tone(buzz,311.11);
  delay(500);
  tone(buzz,261.11);
  delay(500);
  tone(buzz,426);
  delay(500);
  noTone(buzz);
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
   noTone(buzz);
}

void rgbfav(){
   analogWrite(r,234);
   analogWrite(g,193);
   analogWrite(b,91);
   sonido();
   delay(1000);
}

void sonido(){
  tone(buzz,234);
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
  tone(buzz,629.11);
  delay(1000);
  noTone(buzz);
}

void funcion13(){
  pantalla.borrar();
  pantalla.escribirBits(corasao,12);
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
 funcion1();
 funcion2();
 funcion3();
 funcion4();
 funcion5();
 funcion6();
 funcion7();
 funcion8();
 funcion9();
 funcion10();
 funcion11();
 funcion12();
 funcion13();
  
}
