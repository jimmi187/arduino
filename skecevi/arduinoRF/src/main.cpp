

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000, 4, 2, 0); // (speed, receive, transmit, push to talk);

void setup()
{
  Serial.begin(9600);
  if (!driver.init()){
    Serial.println("init failed");
  }
}

void loop()
{
    
      const char *msg = "hello";
      driver.send((uint8_t *)msg, strlen(msg));
      driver.waitPacketSent();
      Serial.println("sta se desava");
      delay(200);
      
  

  // uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  // uint8_t buflen = sizeof(buf);

  // if (driver.recv(buf, &buflen)) // Non-blocking  
  // {
  //   driver.printBuffer("Got:", buf, buflen);
  // }
  
    
}