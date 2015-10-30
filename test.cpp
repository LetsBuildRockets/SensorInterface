#include <iostream>

#include "SensorInterface.cpp"



int main() {
  SensorInterface interface;
  DigitalSensor d;
  d.setValue(123);
  std::cout << d.getJSON() << std::endl;
  return 0;
}