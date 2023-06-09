#include "Arduino.h"
#include "Adafruit_PCF8575.h" // library for IO expanders on I2C line
#include "definitions.h"
#include "setup.h"
Adafruit_PCF8575 pcf;
void setup() {
//  while (!Serial) { delay(10); } // awaiting for serial port to be connected
  delay(1000);
  Serial.begin(19200);
  Serial.println("Tea Machine PICO control board");
  Serial.println("Init begin");
  setupGPIOPins();
  pcf.begin(0x20, &Wire);
  setupLeftExpander();
  pcf.begin(0x21, &Wire);
  setupTopExpander();
  pcf.begin(0x23, &Wire);
  setupRightExpander();
  setAllOFF();
  delay(1000);
  setAllON();
  delay(5000);
  setAllOFF();
  delay(1000);
  Serial.println("Init DONE");
  
}

void loop() {
    if (Serial.available()) {
      String command = Serial.readStringUntil('\n');
      handleCommand(command);  
  }
  digitalWrite(LED_BUILTIN, HIGH);
  

}

void handleCommand(String command) {
  command.trim();
  String typeOfModule = command.substring(0, 1);
  String module = command.substring(0, 2);
  String action = command.substring(3);
  if(typeOfModule == "L" || typeOfModule == "W" ||typeOfModule == "H"  || typeOfModule == "S" ){
    if(module == "W1"){
      if(action == "ON"){
        digitalWrite(waterHeater1, HIGH);  
      }else if(action == "OFF"){
        digitalWrite(waterHeater1, LOW);
      }
    }
  }else if (typeOfModule == "C" || typeOfModule == "F" ){
    
  }else{
    Serial.println("Unknown type of device");
  }
  
}
