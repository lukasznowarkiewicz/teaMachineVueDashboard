#include "setup.h"
#include "definitions.h"
#include "Adafruit_PCF8575.h" // library for IO expanders on I2C line
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
