#include "setup.h"
#include "definitions.h"
#include "Adafruit_PCF8575.h" // library for IO expanders on I2C line
Adafruit_PCF8575 pcf2;
void setupGPIOPins() {
    // setup for GPIOs diretly connected to PICO
    pinMode(waterHeater1, OUTPUT);
    pinMode(waterHeater2, OUTPUT);
    pinMode(waterPump1, OUTPUT);
    pinMode(waterPump2, OUTPUT);
    pinMode(DS18B20_1wire, OUTPUT); // dla 1-wire
    pinMode(teaBrewerServo1, OUTPUT); // dla PWM
    pinMode(teaBrewerServo2, OUTPUT); // dla PWM
    pinMode(Future_PWM1, OUTPUT); // dla PWM
    pinMode(Future_PWM2, OUTPUT); // dla PWM
    pinMode(Future_PWM3, OUTPUT); // dla PWM
    pinMode(SDA, OUTPUT); // dla I2C
    pinMode(SCL, OUTPUT); // dla I2C
    pinMode(rgbLightR, OUTPUT); // dla PWM
    pinMode(rgbLightG, OUTPUT); // dla PWM
    pinMode(rgbLightB, OUTPUT); // dla PWM
    pinMode(ledStrip, OUTPUT); // dla PWM
    pinMode(RP2UARTTX, OUTPUT); // dla UART TX
    pinMode(RP2UARTRX, OUTPUT); // dla UART RX
    pinMode(sugarLvl2, INPUT);
    pinMode(sugarServo1, OUTPUT); // dla PWM
    pinMode(sugarServo2, OUTPUT); // dla PWM
//    pinMode(ingridServo, OUTPUT); // dla PWM // temporarly disabled due to stability issues
    pinMode(22, INPUT);
    pinMode(sugarLvl1, INPUT);
    pinMode(Future_A1, INPUT);
    pinMode(Future_A2, INPUT);
    pinMode(Future_A3, INPUT);
}

void setupLeftExpander(){
    pcf2.begin(0x20, &Wire);
    pcf2.pinMode(liquidConveyor1, OUTPUT);
    pcf2.pinMode(liquidConveyor1, OUTPUT);
    pcf2.pinMode(liquidConveyor2, OUTPUT);
    pcf2.pinMode(liquidConveyor3, OUTPUT);
    pcf2.pinMode(liquidConveyor4, OUTPUT);
    pcf2.pinMode(liquidConveyor5, OUTPUT);
    pcf2.pinMode(liquidConveyor6, OUTPUT);
    pcf2.pinMode(screwConveyor3, OUTPUT);
    pcf2.pinMode(screwConveyor4, OUTPUT);
    pcf2.pinMode(screwFeederLvl1, INPUT);
    pcf2.pinMode(screwFeederLvl2, INPUT);
    pcf2.pinMode(screwFeederLvl3, INPUT);
    pcf2.pinMode(screwFeederLvl4, INPUT);
    pcf2.pinMode(dripTrayLvl, INPUT);
    pcf2.pinMode(cupSensor, INPUT);
    pcf2.pinMode(Future_O5, OUTPUT);
    pcf2.pinMode(Future_O6, OUTPUT);
  }

void setupTopExpander(){
    pcf2.begin(0x21, &Wire);
    pcf2.pinMode(OUT1_pump1, OUTPUT);
    pcf2.pinMode(OUT2_pump2, OUTPUT);
    pcf2.pinMode(OUT3_pump3, OUTPUT);
    pcf2.pinMode(OUT4_pump4, OUTPUT);
    pcf2.pinMode(OUT5_pump5, OUTPUT);
    pcf2.pinMode(OUT5_pump6, OUTPUT);
    pcf2.pinMode(liquidLvl1, INPUT);
    pcf2.pinMode(liquidLvl2, INPUT);
    pcf2.pinMode(liquidLvl3, INPUT);
    pcf2.pinMode(liquidLvl4, INPUT);
    pcf2.pinMode(liquidLvl5, INPUT);
    pcf2.pinMode(liquidLvl6, INPUT);
    pcf2.pinMode(waterTankLvl1, INPUT);
    pcf2.pinMode(waterTankLvl2, INPUT);
    pcf2.pinMode(wasteTankLvl, INPUT);
    pcf2.pinMode(Future_I0, INPUT);

}

void setupRightExpander(){
    pcf2.begin(0x23, &Wire);
    pcf2.pinMode(Future_I1, INPUT);
    pcf2.pinMode(Future_I2, INPUT);
    pcf2.pinMode(Future_I3, INPUT);
    pcf2.pinMode(Future_I4, INPUT);
    pcf2.pinMode(Future_I5, INPUT);
    pcf2.pinMode(Future_I6, INPUT);
    pcf2.pinMode(Future_O1, OUTPUT);
    pcf2.pinMode(Future_O2, OUTPUT);
    pcf2.pinMode(Future_O3, OUTPUT);
    pcf2.pinMode(Future_O4, OUTPUT);
    pcf2.pinMode(Future_rel1, OUTPUT);
    pcf2.pinMode(ultrasonicAccelerator, OUTPUT);
    pcf2.pinMode(compressor, OUTPUT);
    pcf2.pinMode(hosesActuatorRL, OUTPUT);
    pcf2.pinMode(hosesActuatorRR, OUTPUT);
    pcf2.pinMode(peltierModule, OUTPUT);

}

void setAllOFF() {
    digitalWrite(waterHeater1, HIGH);
    digitalWrite(waterHeater2, HIGH);
    digitalWrite(waterPump1, HIGH);
    digitalWrite(waterPump2, HIGH);

    pcf2.begin(0x20, &Wire);
    pcf2.digitalWrite(liquidConveyor1, HIGH);
    pcf2.digitalWrite(liquidConveyor2, HIGH);
    pcf2.digitalWrite(liquidConveyor3, HIGH);
    pcf2.digitalWrite(liquidConveyor4, HIGH);
    pcf2.digitalWrite(liquidConveyor5, HIGH);
    pcf2.digitalWrite(liquidConveyor6, HIGH);
    pcf2.digitalWrite(screwConveyor3, HIGH);
    pcf2.digitalWrite(screwConveyor4, HIGH);
    pcf2.digitalWrite(Future_O5, HIGH);
    pcf2.digitalWrite(Future_O6, HIGH);

    pcf2.begin(0x21, &Wire);
    pcf2.digitalWrite(OUT1_pump1, HIGH);
    pcf2.digitalWrite(OUT2_pump2, HIGH);
    pcf2.digitalWrite(OUT3_pump3, HIGH);
    pcf2.digitalWrite(OUT4_pump4, HIGH);
    pcf2.digitalWrite(OUT5_pump5, HIGH);
    pcf2.digitalWrite(OUT5_pump6, HIGH);
    pcf2.digitalWrite(Future_O1, HIGH);

    pcf2.begin(0x23, &Wire);
    pcf2.digitalWrite(Future_O2, HIGH);
    pcf2.digitalWrite(Future_O3, HIGH);
    pcf2.digitalWrite(Future_O4, HIGH);
    pcf2.digitalWrite(Future_rel1, HIGH);
    pcf2.digitalWrite(ultrasonicAccelerator, HIGH);
    pcf2.digitalWrite(compressor, HIGH);
    pcf2.digitalWrite(hosesActuatorRL, HIGH);
    pcf2.digitalWrite(hosesActuatorRR, HIGH);
    pcf2.digitalWrite(peltierModule, HIGH);
    Serial.println("Set all OUTs OFF");
}


void setAllON() {
    digitalWrite(waterHeater1, LOW);
    digitalWrite(waterHeater2, LOW);
    digitalWrite(waterPump1, LOW);
    digitalWrite(waterPump2, LOW);
    
    pcf2.begin(0x20, &Wire);
    pcf2.digitalWrite(liquidConveyor1, LOW);
    pcf2.digitalWrite(liquidConveyor2, LOW);
    pcf2.digitalWrite(liquidConveyor3, LOW);
    pcf2.digitalWrite(liquidConveyor4, LOW);
    pcf2.digitalWrite(liquidConveyor5, LOW);
    pcf2.digitalWrite(liquidConveyor6, LOW);
    pcf2.digitalWrite(screwConveyor3, LOW);
    pcf2.digitalWrite(screwConveyor4, LOW);
    pcf2.digitalWrite(Future_O5, LOW);
    pcf2.digitalWrite(Future_O6, LOW);
    
    pcf2.begin(0x21, &Wire);
    digitalWrite(OUT1_pump1, LOW);
    digitalWrite(OUT2_pump2, LOW);
    digitalWrite(OUT3_pump3, LOW);
    digitalWrite(OUT4_pump4, LOW);
    digitalWrite(OUT5_pump5, LOW);
    digitalWrite(OUT5_pump6, LOW);
    digitalWrite(Future_O1, LOW);
    
    pcf2.begin(0x23, &Wire);
    digitalWrite(Future_O2, LOW);
    digitalWrite(Future_O3, LOW);
    digitalWrite(Future_O4, LOW);
    digitalWrite(Future_rel1, LOW);
    digitalWrite(ultrasonicAccelerator, LOW);
    digitalWrite(compressor, LOW);
    digitalWrite(hosesActuatorRL, LOW);
    digitalWrite(hosesActuatorRR, LOW);
    digitalWrite(peltierModule, LOW);
    Serial.println("Set all OUTs ON");
}
