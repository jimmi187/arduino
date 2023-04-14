#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 2;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

// Example of data captured by IRrecvDumpV2.ino
uint16_t rawData1[71] = {9116, 4478,  588, 528,  606, 550,  588, 546,  592, 544,  590, 548,  586, 548,  564, 572,  612, 522,  590, 1656,  588, 1634,  590, 1672,  618, 1626,  616, 1628,  590, 1654,  594, 1654,  614, 1630,  562, 572,  588, 546,  590, 544,  618, 518,  590, 1636,  584, 572,  588, 1654,  
588, 548,  614, 1630,  562, 1680,  586, 1658,  588, 1656,  618, 518,  564, 1680,  616, 522,  588, 1656,  588, 39976,  9110, 2236,  588};
// Example Samsung A/C state captured from IRrecvDumpV2.ino

uint16_t rawData[67] = {9058, 4532,  590, 544,  592, 546,  588, 548,  590, 546,  588, 544,  590, 550,  592, 544,  590, 548,  586, 1656,  588, 1654,  588, 1656,  590, 1654,  590, 1654,  590, 1654,  590, 1656,  588, 1656,  590, 544,  590, 546,  588, 548,  562, 572,  564, 1680,  616, 520,  564, 1682,  
562, 572,  588, 1656,  590, 1654,  590, 1654,  564, 1682,  588, 546,  588, 1656,  590, 548,  586, 1654,  592};
uint8_t samsungState[kSamsungAcStateLength] = {
    0x02, 0x92, 0x0F, 0x00, 0x00, 0x00, 0xF0,
    0x01, 0xE2, 0xFE, 0x71, 0x40, 0x11, 0xF0};

void setup() {
  irsend.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
}

void loop() {
  // Serial.println("NEC");
  // irsend.sendNEC(0x00FFE01FUL);
  // delay(2000);
  // Serial.println("Sony");
  // irsend.sendSony(0xa90, 12, 2);  // 12 bits & 2 repeats
  // delay(2000);
  // Serial.println("a rawData capture from IRrecvDumpV2");
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  irsend.sendRaw(rawData, 67, 38);  // Send a raw data capture at 38kHz.
  delay(5000);

  // Serial.println("a Samsung A/C state from IRrecvDumpV2");
  // irsend.sendSamsungAC(samsungState);
  // delay(2000);
}