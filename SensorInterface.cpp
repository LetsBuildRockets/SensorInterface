#include <vector>

#include "AnalogSensor.cpp"
#include "DigitalSensor.cpp"

class SensorInterface {
  protected:
    std::vector<AnalogSensor> analog;
    std::vector<DigitalSensor> digital;
    
  public:
    SensorInterface() {
      analog.reserve(16);
      digital.reserve(16);
    }
};