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
    pinMode(sugarLvl1, INPUT);
    pinMode(Future_A1, INPUT);
    pinMode(Future_A2, INPUT);
    pinMode(Future_A3, INPUT);
}

void setupLeftExpander(){
    pinMode(OUT1_screw1RL, OUTPUT);
    pinMode(OUT2_screw1RR, OUTPUT);
    pinMode(OUT3_screw2RL, OUTPUT);
    pinMode(OUT4_screw2RR, OUTPUT);
    pinMode(OUT5_screw3RL, OUTPUT);
    pinMode(OUT6_screw3RR, OUTPUT);
    pinMode(OUT7_screw4RL, OUTPUT);
    pinMode(OUT8_screw4RR, OUTPUT);
    pinMode(screwFeederLvl1, INPUT);
    pinMode(screwFeederLvl2, INPUT);
    pinMode(screwFeederLvl3, INPUT);
    pinMode(screwFeederLvl4, INPUT);
    pinMode(dripTrayLvl, INPUT);
    pinMode(cupSensor, INPUT);
    pinMode(Future_O5, OUTPUT);
    pinMode(Future_O6, OUTPUT);
  }

void setupTopExpander(){
    pinMode(OUT1_pump1, OUTPUT);
    pinMode(OUT2_pump2, OUTPUT);
    pinMode(OUT3_pump3, OUTPUT);
    pinMode(OUT4_pump4, OUTPUT);
    pinMode(OUT5_pump5, OUTPUT);
    pinMode(OUT5_pump6, OUTPUT);
    pinMode(liquidLvl1, INPUT);
    pinMode(liquidLvl2, INPUT);
    pinMode(liquidLvl3, INPUT);
    pinMode(liquidLvl4, INPUT);
    pinMode(liquidLvl5, INPUT);
    pinMode(liquidLvl6, INPUT);
    pinMode(waterTankLvl1, INPUT);
    pinMode(waterTankLvl2, INPUT);
    pinMode(wasteTankLvl, INPUT);
    pinMode(Future_I0, INPUT);
}

void setupRightExpander(){
    pinMode(Future_I1, INPUT);
    pinMode(Future_I2, INPUT);
    pinMode(Future_I3, INPUT);
    pinMode(Future_I4, INPUT);
    pinMode(Future_I5, INPUT);
    pinMode(Future_I6, INPUT);
    pinMode(Future_O1, OUTPUT);
    pinMode(Future_O2, OUTPUT);
    pinMode(Future_O3, OUTPUT);
    pinMode(Future_O4, OUTPUT);
    pinMode(Future_rel1, OUTPUT);
    pinMode(ultrasonicAccelerator, OUTPUT);
    pinMode(compressor, OUTPUT);
    pinMode(hosesActuatorRL, OUTPUT);
    pinMode(hosesActuatorRR, OUTPUT);
    pinMode(peltierModule, OUTPUT);
}

void setAllOFF(){
    digitalWrite(waterHeater1, LOW);
    digitalWrite(waterHeater2, LOW);
    digitalWrite(waterPump1, LOW);
    digitalWrite(waterPump2, LOW);
    
    pcf2.begin(0x20, &Wire);
    digitalWrite(OUT1_screw1RL, LOW);
    digitalWrite(OUT2_screw1RR, LOW);
    digitalWrite(OUT3_screw2RL, LOW);
    digitalWrite(OUT4_screw2RR, LOW);
    digitalWrite(OUT5_screw3RL, LOW);
    digitalWrite(OUT6_screw3RR, LOW);
    digitalWrite(OUT7_screw4RL, LOW);
    digitalWrite(OUT8_screw4RR, LOW);
    digitalWrite(Future_O5, LOW);
    digitalWrite(Future_O6, LOW);

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
    Serial.println("Set all OUTs OFF");
}

void setAllON() {
    digitalWrite(waterHeater1, HIGH);
    digitalWrite(waterHeater2, HIGH);
    digitalWrite(waterPump1, HIGH);
    digitalWrite(waterPump2, HIGH);
    
    pcf2.begin(0x20, &Wire);
    digitalWrite(OUT1_screw1RL, HIGH);
    digitalWrite(OUT2_screw1RR, HIGH);
    digitalWrite(OUT3_screw2RL, HIGH);
    digitalWrite(OUT4_screw2RR, HIGH);
    digitalWrite(OUT5_screw3RL, HIGH);
    digitalWrite(OUT6_screw3RR, HIGH);
    digitalWrite(OUT7_screw4RL, HIGH);
    digitalWrite(OUT8_screw4RR, HIGH);
    digitalWrite(Future_O5, HIGH);
    digitalWrite(Future_O6, HIGH);
    
    pcf2.begin(0x21, &Wire);
    digitalWrite(OUT1_pump1, HIGH);
    digitalWrite(OUT2_pump2, HIGH);
    digitalWrite(OUT3_pump3, HIGH);
    digitalWrite(OUT4_pump4, HIGH);
    digitalWrite(OUT5_pump5, HIGH);
    digitalWrite(OUT5_pump6, HIGH);
    digitalWrite(Future_O1, HIGH);
    
    pcf2.begin(0x23, &Wire);
    digitalWrite(Future_O2, HIGH);
    digitalWrite(Future_O3, HIGH);
    digitalWrite(Future_O4, HIGH);
    digitalWrite(Future_rel1, HIGH);
    digitalWrite(ultrasonicAccelerator, HIGH);
    digitalWrite(compressor, HIGH);
    digitalWrite(hosesActuatorRL, HIGH);
    digitalWrite(hosesActuatorRR, HIGH);
    digitalWrite(peltierModule, HIGH);
    Serial.println("Set all OUTs ON");
}
