#include <iostream>

#include "SensorInterface.cpp"



int main() {
  SensorInterface interface;
  interface.digital[0].setValue(123);
  std::cout << interface.digitalI[0].getValue() << std::endl;
  return 0;
}