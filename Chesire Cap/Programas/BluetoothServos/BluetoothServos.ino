#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(10,11);  //RX, TX

Servo servo1;  // crea el objeto servo
Servo servo2;
Servo servo3;

int pos = 0;    // posicion del servo
int pulsaciones = 0;

void setup() {
  servo1.attach(3);  // vincula el servo al pin digital 9
  servo2.attach(6);  // vincula el servo al pin digital 10
  servo3.attach(5);  // vincula el servo al pin digital 11
  
  Serial.begin(115200);
  bluetoothSerial.begin(9600);
}

void loop(){
  Serial.println("holis");
  if(bluetoothSerial.available()){
    Serial.println("entro");
    char data_received = bluetoothSerial.read();
    Serial.println(data_received);
    switch(data_received){
      case '1':
        Serial.println("entro");
        for (pos = 0; pos <= 180; pos += 1) {
          servo1.write(pos);          
          delay(15);                       
        }
        for (pos = 180; pos >= 0; pos -= 1) {
          servo1.write(pos);          
          delay(15);                       
        }
        Serial.println("hecho");
        break;
      case '2':
        for (pos = 0; pos <= 180; pos += 1) {
          servo2.write(pos);          
          delay(15);                       
        }
        for (pos = 180; pos >= 0; pos -= 1) {
          servo2.write(pos);          
          delay(15);                       
        }
        break;
      case '3':
        for (pos = 0; pos <= 180; pos += 1) {
          servo3.write(pos);          
          delay(15);                       
        }
        for (pos = 180; pos >= 0; pos -= 1) {
          servo3.write(pos);          
          delay(15);                       
        }
        break;
      case 'c':
        if(pulsaciones%3 == 0){
          for (pos = 0; pos <= 180; pos += 1) {
            servo1.write(pos);          
            delay(15);                       
          }
          for (pos = 180; pos >= 0; pos -= 1) {
            servo1.write(pos);          
            delay(15);                       
          }
        }else if(pulsaciones%3 == 1){
          for (pos = 0; pos <= 180; pos += 1) {
            servo1.write(pos);    
            servo2.write(pos);                
            delay(15);                       
          }
          for (pos = 180; pos >= 0; pos -= 1) {
            servo1.write(pos); 
            servo2.write(pos);                   
            delay(15);                       
          }
        }else{
          for (pos = 0; pos <= 180; pos += 1) {
            servo1.write(pos); 
            servo2.write(pos);     
            servo3.write(pos);               
            delay(15);                       
          }
          for (pos = 180; pos >= 0; pos -= 1) {
            servo1.write(pos); 
            servo2.write(pos);     
            servo3.write(pos);                 
            delay(15);                       
          }
        }
        pulsaciones++;
        break;
    }
  }
}