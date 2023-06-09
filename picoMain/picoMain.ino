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
  setupLeftExpander();
  setupTopExpander();
  setupRightExpander();
  setAllOFF();
  delay(1000);
  setAllON();
  delay(1000);
  setAllOFF();
  pcf.begin(0x20, &Wire);
  delay(1000);
  resetLeftIO();
  delay(100);
  setAllOFF();
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
    if(module == "H1"){
      if(action == "ON"){
        digitalWrite(waterHeater1, HIGH);  
        Serial.println("H1-ON-OK");
      } else if(action == "OFF"){
        digitalWrite(waterHeater1, LOW);
        Serial.println("H1-OFF-OK");
      }
    } else if(module == "H2"){
      if(action == "ON"){
        digitalWrite(waterHeater2, HIGH);  
        Serial.println("H2-ON-OK");
      } else if(action == "OFF"){
        digitalWrite(waterHeater2, LOW);
        Serial.println("H2-OFF-OK");
      }
    } else if(module == "W1"){
      if(action == "ON"){
        digitalWrite(waterPump1, HIGH);  
        Serial.println("W1-ON-OK");
      } else if(action == "OFF"){
        digitalWrite(waterPump1, LOW);
        Serial.println("W1-OFF-OK");
      }
    } else if(module == "W2"){
      if(action == "ON"){
        digitalWrite(waterPump2, HIGH);  
        Serial.println("W2-ON-OK");
      } else if(action == "OFF"){
        digitalWrite(waterPump2, LOW);
        Serial.println("W2-OFF-OK");
      }
    } else if(module == "L1"){
      if(action == "ON"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor1, LOW);  
        Serial.println("L1-ON-OK");
      } else if(action == "OFF"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor1, HIGH);
        Serial.println("L1-OFF-OK");
      }
    } else if(module == "L2"){
      if(action == "ON"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor2, LOW);  
        Serial.println("L2-ON-OK");
      } else if(action == "OFF"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor2, HIGH);
        Serial.println("L2-OFF-OK");
      }
    } else if(module == "L3"){
      if(action == "ON"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor3, LOW);  
        Serial.println("L3-ON-OK");
      } else if(action == "OFF"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor3, HIGH);
        Serial.println("L3-OFF-OK");
      }
    } else if(module == "L4"){
      if(action == "ON"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor4, LOW);  
        Serial.println("L4-ON-OK");
      } else if(action == "OFF"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor4, HIGH);
        Serial.println("L4-OFF-OK");
      }
    } else if(module == "L5"){
      if(action == "ON"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor5, LOW);  
        Serial.println("L5-ON-OK");
      } else if(action == "OFF"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor5, HIGH);
        Serial.println("L5-OFF-OK");
      }
    } else if(module == "L6"){
      if(action == "ON"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor6, LOW);  
        Serial.println("L6-ON-OK");
      } else if(action == "OFF"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(liquidConveyor6, HIGH);
        Serial.println("L6-OFF-OK");
      }
    } else if(module == "S3"){
      if(action == "ON"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(screwConveyor3, LOW);  
        Serial.println("S3-ON-OK");
      } else if(action == "OFF"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(screwConveyor3, HIGH);
        Serial.println("S3-OFF-OK");
      }
    } else if(module == "S4"){
      if(action == "ON"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(screwConveyor4, LOW);  
        Serial.println("S4-ON-OK");
      } else if(action == "OFF"){
        pcf.begin(0x20, &Wire);
        pcf.digitalWrite(screwConveyor4, HIGH);
        Serial.println("S4-OFF-OK");
      }
    }
  } else if (typeOfModule == "C" || typeOfModule == "F" ){
    
  } else if (module == "AL" && action == "OFF"){
    setAllOFF();
  }
  else {
    Serial.println("Unknown type of device");
  }
}

void resetLeftIO(){
    pcf.digitalWrite(liquidConveyor1, HIGH);
    pcf.digitalWrite(liquidConveyor2, HIGH);
    pcf.digitalWrite(liquidConveyor3, HIGH);
    pcf.digitalWrite(liquidConveyor4, HIGH);
    pcf.digitalWrite(liquidConveyor5, HIGH);
    pcf.digitalWrite(liquidConveyor6, HIGH);
    pcf.digitalWrite(screwConveyor3, HIGH);
    pcf.digitalWrite(screwConveyor4, HIGH);
    pcf.digitalWrite(Future_O5, HIGH);
    pcf.digitalWrite(Future_O6, HIGH);
}
