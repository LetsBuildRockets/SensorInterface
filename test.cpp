#include <iostream>

#include "SensorInterface.cpp"

int main() {
  SensorInterface interface;
  interface.digital[0].setValue(1);
  std::cout << interface.digital[0].getValue() << std::endl;
  return 0;
}