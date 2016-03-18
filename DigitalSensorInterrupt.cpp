#include <string>

#include "Sensor.cpp"

#ifndef DigitalSensorInterrupt_H_
#define DigitalSensorInterrupt_H_
class DigitalSensorInterrupt : public Sensor {
  protected:
    int value[2];
    int rate;
  public:
    DigitalSensorInterrupt() {
      name = "UNNAMED SENSOR";
      index = 0; 
      value[0] = 0;
      value[1] = 0;
      rate = 0;
      enable();
    }
    
    // Override the getValue function to keep the value to true, false, or 0.
    // Then calculate the array of values into two nibbles, shift them, and then return it :)
    int getValue() {
      int rtnVal = 0;
      rtnVal = value[0] << 0;
      rtnVal = value[1] << 4;
      return rtnVal;
    }
    
    int getRate() {
      // TODO: load calculated rate from interrupt enabled microcontroller on the interface
    }
};
#endif