#include <Arduino.h>
struct pinmap{
  uint8_t tx;
  uint8_t rx;
};
// #define serial Serial2
// pinmap um7104={4,5};
SerialPIO serial(13,12);
pinmap um7106={12,13};
void setup() {
Serial.begin(9600);
// serial.setTX(um7106.tx);
// serial.setRX(um7106.rx);
//
// serial.setTX(um7106.tx);
// serial.setRX(um7106.rx);
// serial.setFIFOSize(256);
serial.begin(115200,SERIAL_8E2);
pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  while(1){
    if(serial.available()){
      Serial.write(serial.read());
    }
    if(Serial.available()){
      while(!serial.availableForWrite()){}
      serial.write(Serial.read());
    }
    digitalWrite(LED_BUILTIN,millis()%1000>500);

  }
  // put your main code here, to run repeatedly:
}

