#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000, 2, 5, 19); // (speed, receive, transmit, push to talk);
int xAxis = 35;
int yAxis = 34;

const char *msg = "hello";
const int number = 45553;
int data[2];

void setup()
{
  Serial.begin(115200);
  if (!driver.init()){
    Serial.println("init failed");
  }

}

void loop()
{
    
  data[0] = map(analogRead(xAxis),0,4095,0,511);
  data[1] =  map(analogRead(yAxis),0,4095,0,511);
  Serial.print(data[0]);
  Serial.print(data[1]);
  

  // driver.send((uint8_t *)msg, strlen(msg));
  // driver.waitPacketSent();
  // delay(1);
      // driver.send((uint8_t *)&number, 4);
      // driver.waitPacketSent();
      // delay(1);
      
      driver.send((uint8_t *)data, sizeof(data));
      driver.waitPacketSent();
      delay(1);
      
  // uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  // uint8_t buflen = sizeof(buf);

  // if (driver.recv(buf, &buflen)) // Non-blocking  
  // {
  //   driver.printBuffer("Got:", buf, buflen);
  // }
  
    
}