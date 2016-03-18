#include "AnalogSensor.cpp"
#include "DigitalSensor.cpp"
#include "DigitalSensorInterrupt.cpp"
#include "mbed.h"
class SensorInterface {
  public:
    AnalogSensor analog[16];
    DigitalSensor digital[12];
    DigitalSensorInterrupt digitalI[4];
    
    SensorInterface() {
      
    }
    
    void periodic() {
      for(int eger = 0; eger < 16; eger++)
        analog[eger].periodic();
    }
};