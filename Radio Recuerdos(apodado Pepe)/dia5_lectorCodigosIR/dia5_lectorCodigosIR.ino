#include <IRremote.h>

const int RECV_PIN = 8;

void setup()
{
   Serial.begin(9600);
   IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
}

void loop()
{
   if (IrReceiver.decode())
   {
      Serial.println(IrReceiver.decodedIRData.decodedRawData,HEX);
      Serial.println(IrReceiver.decodedIRData.decodedRawData);
      Serial.print("Seleccionar--> ");
      Serial.println(IrReceiver.decodedIRData.command);
      Serial.println("\n-----------------------------");
    delay(1000);
      IrReceiver.resume();
      
   }
}
