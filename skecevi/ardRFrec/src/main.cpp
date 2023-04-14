#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
#include <stdlib.h>
RH_ASK driver(2000, 13, 2, 0); // (speed, receive, transmit, push to talk);
int data[2];
int driveL = 11;
int driveD = 10;
int dir1L = 9;
int dir1D = 8;
int dir2L = 7;
int dir2D = 6;
int rotDir;
// int ledPin = 2;


void setup()
{
  Serial.begin(9600);
  if (!driver.init()){
    Serial.println("init failed");
  }

  pinMode(driveL,OUTPUT);
  pinMode(driveD ,OUTPUT);
  pinMode(dir1L ,OUTPUT);
  pinMode(dir2L ,OUTPUT);
  pinMode(dir1D ,OUTPUT);
  pinMode(dir2D ,OUTPUT);
  // pinMode(ledPin, OUTPUT);
}

void drive(boolean rotdir){
  if(rotDir == 1){
    digitalWrite(dir1L, HIGH);
    digitalWrite(dir1D, HIGH);
    digitalWrite(dir2L, LOW);
    digitalWrite(dir2D, LOW);
    digitalWrite(driveL, HIGH);
    digitalWrite(driveD, HIGH);
  }else if(rotDir == 2){
    digitalWrite(dir1L, LOW);
    digitalWrite(dir1D, LOW);
    digitalWrite(dir2L, HIGH);
    digitalWrite(dir2D, HIGH);
    digitalWrite(driveL, HIGH);
    digitalWrite(driveD, HIGH);
  }else if(rotDir == 3){
    
    digitalWrite(dir1L, LOW);
    digitalWrite(dir1D, HIGH);
    digitalWrite(dir2L, HIGH);
    digitalWrite(dir2D, LOW);
    digitalWrite(driveL, HIGH);
    digitalWrite(driveD, HIGH);
  
  }else if(rotDir == 4){
    
    digitalWrite(dir1L, HIGH);
    digitalWrite(dir1D, LOW);
    digitalWrite(dir2L, LOW);
    digitalWrite(dir2D, HIGH);
    digitalWrite(driveL, HIGH);
    digitalWrite(driveD, HIGH);
  
  }else if(rotDir == 0){
    digitalWrite(driveL, LOW);
    digitalWrite(driveD, LOW);
    
  }
        
  }

void loop()
{


      

      

      
        
      
      // uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
      // uint8_t buflen = sizeof(buf);

      // if (driver.recv(buf, &buflen)) // Non-blocking  
      int receivedData[3]={};
      uint8_t buflen = sizeof(receivedData);
      if(driver.recv((uint8_t*)receivedData, &buflen))
      {
        int x = receivedData[0];
        int y = receivedData[2];
        Serial.print("ovo je x: ");
        Serial.println(x);
        Serial.print("ovo je y: ");
        Serial.println(y);
        if(x > 266 && y < 250 && y > 200){
          rotDir = 1;
          // digitalWrite(ledPin, HIGH);
        }else if(x < 200 && y < 250 && y > 200){
          rotDir = 2;
          // digitalWrite(ledPin, HIGH);
        }else if(y > 266 && x < 250 && x > 200){
          rotDir = 3;
          // digitalWrite(ledPin, HIGH);
        }else if(y < 200 && x < 250 && x > 200){
          rotDir = 4;
          // digitalWrite(ledPin, HIGH);
        }else{
          // digitalWrite(ledPin, LOW);
          rotDir = 0;
        }
        
      }

drive(rotDir);
      
        // for(byte i = 0; i < 3; ++i){
        //   Serial.print("ovo je i: ");
        //   Serial.println(i);
        //   Serial.print(receivedData[i]);
        //   Serial.print("\t");
        //   Serial.println(receivedData[i], HEX);
        // }








        // String msg;
        // for(int i=0; i<buflen; i++){
        //   msg += (char)buf[i];
        // }
        // driver.printBuffer("Got:", buf, buflen);
        // Serial.print("message: ");
        // if(msg.equalsIgnoreCase("hello")){
        //   Serial.println(msg);
        // }else{
        //   int c = int(buf);
        //   Serial.println(c);
        // }


        
      
      
  

  // uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  // uint8_t buflen = sizeof(buf);

  // if (driver.recv(buf, &buflen)) // Non-blocking  
  // {
  //   driver.printBuffer("Got:", buf, buflen);
  // }
  
}


