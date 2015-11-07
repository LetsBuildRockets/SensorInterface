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
      index = -1; 
      value[0] = -1;
      value[1] = -1;
      rate = 0;
      enable();
    }
    
    // Override the getValue function to keep the value to true, false, or -1.
    // Then calculate the array of values into two nibbles, shift them, and then return it :)
    int getValue() {
      int rtnVal = 0;
      for(int i = 0; i < 2; i++) {
        if(value[i] > 0)
          rtnVal += 1 << i*4;
        else if(value[i] < 0)
          rtnVal += 15 << i*4;
      }
      return rtnVal;
    }
    
    int getRate() {
      // TODO: load calculated rate from interrupt enabled microcontroller on the interface
    }
};
#endif