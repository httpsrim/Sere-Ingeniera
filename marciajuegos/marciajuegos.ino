//declarar los leds
int led0 = 6;
int led1 = 4;
int led2= 2;
int led3 = 3;
//declarar fotoresistencias
int foto0 = A0;
int foto1 = A1;
int foto2 = A2;
int foto3 = A3;
//declarar limite para fotoresistencia
int limite = 800;
//declarar bajas(bichos que he disparado)
int bajas = 0;
int bajas_ganar = 20;
//declarar contador
int contador = 0;
//declarar escapar
int escapar = 0;
int escapar_perder = 5;
//declarar buzzer

int sonido = 5;
//bool encendido,para apagarencenderLED
int R = 11;
int B = 10;
int G = 9;
bool encendido0 = false;
bool encendido1 = false;
bool encendido2 = false;
bool encendido3 = false;


void setup() {
  Serial.begin(9600);
  //leds/rgb/buzzer son de salida
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(sonido,OUTPUT);  
  pinMode(led0 , OUTPUT);
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT); 
  //fotoresistencias son de entrada   
  pinMode(foto0 , INPUT);   
  pinMode(foto1 , INPUT);
  pinMode(foto2 , INPUT);
  pinMode(foto3 , INPUT);
  }

void loop()
{
 if(bajas>bajas_ganar){
 //ir al void win
  win();
 }
 if (escapar < 5){
  //ir al void jugar
  jugar();
  //si no,(se pierde)     
  } else{
   //ir al void loose
loose();
  }
}
   
void jugar(){
      disparar();  
      //si el contador es mas de 5s,
    if (contador > 5000)  {
        //contador se pone a 0s
      contador = 0;
       //va al void apagarencenderLED
apagarencenderLED();
      }          
}


void apagarencenderLED(){ 
  //numeros aleatorios
  //declarar n como numero random entre 0>=x<=3
  int n = random(0,4); 
  Serial.println(n);
    //si sale n=0,hacer lo siguiente
    if (n==0){
      if(encendido0){
      apagar(led0);
      encendido0=false; 
      escapar++;
    }
    else{
    encender(led0);
    encendido0 = true;

  }
    }
     //si sale n=1,hacer lo siguiente
    if (n==1){
    if(encendido1){
    apagar(led1);
    escapar++;
    encendido1=false;  
    
    }
    else{
    encender(led1);
    encendido1=true;

    }
  }
   //si sale n=2,hacer lo siguiente
  if (n==2){
    if(encendido2){
    apagar(led2);
    escapar++;
    encendido2=false;
    
  }
    else{
     encender(led2);
     encendido2=true; 
   
    }
  }
   //si sale n=3,hacer lo siguiente
   if (n==3){
    if(encendido3){
    apagar(led3);
    encendido3=false;
    escapar++;
  }
    else{
     encender(led3);
     encendido3=true; 
     
    }
  }
}


  
//declarar void disparar, para apagar las fotresistencias
void disparar(){
if (analogRead(foto0) > limite && encendido0==true)
  {
      apagar(led0);
      bajas++;
      encendido0 = false;
    }

if (analogRead(foto1) > limite && encendido1==true)
  {
    apagar(led1);
    encendido1 = false; 
    bajas++;
  }
if (analogRead(foto3) > limite && encendido2==true)
 {
      apagar(led2);
      encendido2 = false; 
      bajas++;
    }
if (analogRead(foto2) > limite && encendido3==true){
      apagar(led3);
      encendido3 = false;
      bajas++;
    }
      contador++;
}

//apagar led
void apagar(int led)
  {
  digitalWrite(led,LOW);
  }

//encender led
void encender(int led)
  {
  digitalWrite(led,HIGH);
  }

void win(){
  //declarar un void,para cuando ganes
 //encienden los leds
  encender(led0);
 encender(led1);
  encender(led2);
  encender(led3);
  //rgba celeste
analogWrite(R,0);
analogWrite(G,143);
analogWrite(B,43);
  digitalWrite(sonido,HIGH);
  tone(sonido,520);
  delay(360);
  tone(sonido,140);
  delay(290);
  tone(sonido,35);
  delay(999);
  tone(sonido,860);
  delay(640);
  tone(sonido,120);
  delay(17);
  tone(sonido,52);
  delay(380);
  tone(sonido,750);
  delay(444);
  tone(sonido,666);
  delay(999);
  noTone(sonido);
 digitalWrite(sonido,LOW);
}

void loose()
{
  //declarar un void,para cuando pierdess
 //apagan los leds
  apagar(led0);
  apagar(led1);
  apagar(led2);
  apagar(led3);
  digitalWrite(sonido,HIGH);
  tone(sonido,659.26);
  delay(1000);
  tone(sonido,1259.26);
  delay(400);
  tone(sonido,659.26);
  delay(100);
  tone(sonido,783.99);
  delay(2000);
  tone(sonido,880);
  delay(123);
  tone(sonido,560);
  delay(420);
  tone(sonido,820);
  delay(210);
  tone(sonido,183);
  delay(48);
  noTone(sonido);
 digitalWrite(sonido,LOW);
}
