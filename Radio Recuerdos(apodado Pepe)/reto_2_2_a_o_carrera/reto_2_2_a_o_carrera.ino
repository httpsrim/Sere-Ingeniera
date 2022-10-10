const int verde = 12;
const int rojo = 13;
const int boton = 7;
int val;
void setup() {
Serial.begin(9600);
pinMode(verde,OUTPUT);
pinMode(rojo,OUTPUT);
pinMode(boton,INPUT_PULLUP);
}

void loop(){
val=digitalRead(boton);
if (val==LOW){
digitalWrite(verde,HIGH);
delay(750);
digitalWrite(verde,LOW);
digitalWrite(rojo,HIGH);
delay(750);
digitalWrite(rojo,LOW);
}
else{
  digitalWrite(verde,LOW);
  digitalWrite(rojo,LOW);
  }
}


//void loop() {
//if(value == HIGH){
//digitalWrite(verde,HIGH);
//delay(750);
//digitalWrite(verde,LOW);
//digitalWrite(rojo,HIGH);
//delay(750);
//digitalWrite(rojo,LOW);
//}
//else{
 // digitalWrite(verde,LOW);
  //digitalWrite(rojo,LOW);
//}
//}
