#include "AnalogSensor.cpp"
#include "DigitalSensor.cpp"
#include "DigitalSensorInterrupt.cpp"

class SensorInterface {
  public:
    AnalogSensor analog[16];
    DigitalSensor digital[12];
    DigitalSensorInterrupt digitalI[4];
    
    SensorInterface() {
      
    }
};