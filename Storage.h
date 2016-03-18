#include <string>
#include "mbed.h"

extern I2C i2c;

class Storage {
  public:
    Storage(uint8_t _addr = 0x50);
    bool store(uint16_t, std::string, std::string, double, double, double, double, uint8_t);  
    bool load(uint16_t, std::string &, std::string &, double &, double &, double &, double &, uint8_t &);  
        
  private:
    uint8_t I2C_EEPROM_ADDR;
};