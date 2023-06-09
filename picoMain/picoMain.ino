#include "Arduino.h"
#include "Adafruit_PCF8575.h" // library for IO expanders on I2C line
#include "definitions.h"
#include "setup.h"
Adafruit_PCF8575 pcf;
void setup() {
  Serial.begin(115200);
  Serial.println("Tea Machine PICO control board");
  Serial.println("Init begin");
  setupGPIOPins();
  pcf.begin(0x20, &Wire);
  setupLeftExpander();
  pcf.begin(0x21, &Wire);
  setupTopExpander();
  pcf.begin(0x23, &Wire);
  setupRightExpander();
  Serial.println("Init DONE");
  
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 
  digitalWrite(LED_BUILTIN, HIGH);  
//  Serial.println("LED_BUILTIN, HIGH");
//  delay(100);
//  pcf.begin(0x20, &Wire);
//  for (uint8_t p=0; p<16; p++) {
//    pcf.digitalWrite(p, LOW);  // turn LED on by sinking current to ground
//  }
//  Serial.println("PCFs low");
//  delay(1000);
//  for (uint8_t p=0; p<16; p++) {
//    pcf.digitalWrite(p, HIGH); // turn LED off by turning off sinking transistor
//  }
//  Serial.println("PCFs high");
//  delay(1000);
//
//  pcf.begin(0x21, &Wire);
//    for (uint8_t p=0; p<16; p++) {
//    pcf.digitalWrite(p, LOW);  // turn LED on by sinking current to ground
//  }
//    Serial.println("PCFs low");
//delay(1000);
//  for (uint8_t p=0; p<16; p++) {
//    pcf.digitalWrite(p, HIGH); // turn LED off by turning off sinking transistor
//  }
//  Serial.println("PCFs high");
//
//  pcf.begin(0x23, &Wire);
//    for (uint8_t p=0; p<16; p++) {
//    pcf.digitalWrite(p, LOW);  // turn LED on by sinking current to ground
//  }
//    Serial.println("PCFs low");
//delay(1000);
//  for (uint8_t p=0; p<16; p++) {
//    pcf.digitalWrite(p, HIGH); // turn LED off by turning off sinking transistor
//  }
//  Serial.println("PCFs high");
//  
//  digitalWrite(LED_BUILTIN, LOW);   
//  for(uint8_t i=0; i<28 ; i++){
//     if(i!=10 && i!=11 && i!=22){
//      digitalWrite(i, HIGH);
//    }
//    delay(100);
//    if(i!=10 && i!=11 && i!=22){
//      digitalWrite(i, LOW);
//    }
//  }
  digitalWrite(RP2UARTTX, HIGH);
  digitalWrite(waterHeater2, HIGH);
  delay(1000);
  digitalWrite(RP2UARTTX, LOW);
  digitalWrite(waterHeater2, LOW);
   delay(1000);
}
