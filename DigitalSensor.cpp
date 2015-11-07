#include "Sensor.cpp"

#ifndef DigitalSensor_H_
#define DigitalSensor_H_
class DigitalSensor : public Sensor {
  public:
    DigitalSensor() : Sensor(){
      
    }
    
    // Override the getValue function to keep the value to true, false, or -1.
    int getValue() {
      if(value == 0)
        return 0;
      else if (value > 0)
        return 1;
      else
        return -1;
    }
};
#endif