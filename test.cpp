#include <iostream>

#include "SensorInterface.cpp"



int main() {
  SensorInterface interface;
  DigitalSensor d;
  d.setValue(123);
  d.loadJSON("{\"name\": \"doodle SENSOR\", \"index\": 1, \"value\": 1}");
  std::cout << d.getJSON() << std::endl;
  return 0;
}