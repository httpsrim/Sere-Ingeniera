#include <Servo.h>

Servo servo1;  // crea el objeto servo
Servo servo2;
Servo servo3;

int pos = 0;    // posicion del servo

void setup() {
  servo1.attach(3);  // vincula el servo al pin digital 9
  servo2.attach(6);  // vincula el servo al pin digital 10
  servo3.attach(5);  // vincula el servo al pin digital 11
}

void loop() {
  //varia la posicion de 0 a 180, con esperas de 15ms
  for (pos = 0; pos <= 180; pos += 1) 
  {
    servo1.write(pos);   
    servo2.write(pos);             
    servo3.write(pos);          
    delay(15);                       
  }

  //varia la posicion de 180 a 0, con esperas de 15ms
  for (pos = 180; pos >= 0; pos -= 1) 
  {
    servo1.write(pos);   
    servo2.write(pos);             
    servo3.write(pos); 
    delay(15);                       
  }
}