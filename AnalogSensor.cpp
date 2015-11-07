#include <math.h>
#include <vector>

#include "Sensor.cpp"

#ifndef AnalogSensor_H_
#define AnalogSensor_H_
class AnalogSensor : public Sensor {
  protected:
    double value;
    std::vector<double> data;
    int nLength;
    
  public:
    AnalogSensor() : Sensor(){
      nLength = 1;
      data.resize(1, 0);
    }
    
    void setValue(double x) {
      value = x;
      data.push_back(x);
      data.erase(data.begin());
    }
    
    void setnLength(int _nl) {
      nLength = _nl;
      data.resize(nLength, value);
    }
    
    int getValue() {
      return value;
    }
    
    double getValueDouble() {
      return value;
    }
    
    double getRMS() {
      double rms = 0;
      for(int eger = 0; eger < nLength; eger++) {
        rms += pow(data[eger], 2);
      }
      rms = sqrt(rms/nLength);
      return rms;
    }
    
    double getAverage() {
      double avg = 0;
      for(int eger = 0; eger < nLength; eger++) {
        avg += data[eger];
      }
      avg /= nLength;
      return avg;
    }
};
#endif