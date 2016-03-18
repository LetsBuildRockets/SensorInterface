// EEPROM Allocatoin
// 0-15 Name
// 16-23 Units
// 24-31 A
// 32-39 B
// 40-47 C
// 48-55 D
// 56-63 Refresh Rate

#include "mbed.h"
#include <stdint.h>
#include <string>
#include "Storage.h"

#define STORAGE_LENGTH 64
#define NAME_LENGTH 16
#define UNIT_LENGTH 8
#define TRANSMIT_LENGTH STORAGE_LENGTH + 2

Storage::Storage(uint8_t _addr) : I2C_EEPROM_ADDR(_addr) {
    
}

bool Storage::load(uint16_t pageIndex, std::string &nameString, std::string &unitString, double &aDouble, double &bDouble, double &cDouble, double &dDouble, uint8_t &rRateInt) {
    if(pageIndex > 511) return false;
    
    char transmitArray[2] = { 0 };
    transmitArray[0] = (char) (pageIndex *64 + 63);
    transmitArray[1] = (char) (pageIndex * 64);
    i2c.write((I2C_EEPROM_ADDR << 1), transmitArray, 2);
    
    char rtn[2];
    i2c.read((I2C_EEPROM_ADDR << 1), rtn, 64);
    char name[NAME_LENGTH] = { 0 };
    char unit[UNIT_LENGTH] = { 0 };
    uint8_t a[sizeof(double)] = { 0 };
    uint8_t b[sizeof(double)] = { 0 };
    uint8_t c[sizeof(double)] = { 0 };
    uint8_t d[sizeof(double)] = { 0 };
    uint8_t rRate[sizeof(uint8_t)] = { 0 };
    
    uint8_t begIndex = 0;
    for(int eger = 0; eger < NAME_LENGTH && begIndex < STORAGE_LENGTH; eger++) {
        name[eger] = rtn[begIndex];
        begIndex += 1;
    }
    for(int eger = 0; eger < UNIT_LENGTH && begIndex < STORAGE_LENGTH; eger++) {
        unit[eger] = rtn[begIndex];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(double) && begIndex < STORAGE_LENGTH; eger++) {
        a[eger] = rtn[begIndex];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(double) && begIndex < STORAGE_LENGTH; eger++) {
        b[eger] = rtn[begIndex];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(double) && begIndex < STORAGE_LENGTH; eger++) {
        c[eger] = rtn[begIndex];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(double) && begIndex < STORAGE_LENGTH; eger++) {
        d[eger] = rtn[begIndex];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(uint8_t) && begIndex < STORAGE_LENGTH; eger++) {
        rRate[eger] = rtn[begIndex];
        begIndex += 1;
    }
    
    nameString = string(name);
    unitString = string(unit);
    
    std::memcpy(&aDouble, a, sizeof(double));
    std::memcpy(&bDouble, b, sizeof(double));
    std::memcpy(&cDouble, c, sizeof(double));
    std::memcpy(&dDouble, d, sizeof(double));
    
    std::memcpy(&rRateInt, rRate, sizeof(uint8_t));
    return true;    
}

bool Storage::store(uint16_t pageIndex, std::string nameString, std::string unitString, double aDouble, double bDouble, double  cDouble, double dDouble, uint8_t rRateInt) {
    if(pageIndex > 511) return false;
    
    uint8_t storage[STORAGE_LENGTH] = { 0 };
    char name[NAME_LENGTH] = { 0 };
    char unit[UNIT_LENGTH] = { 0 };
    uint8_t a[sizeof(double)] = { 0 };
    uint8_t b[sizeof(double)] = { 0 };
    uint8_t c[sizeof(double)] = { 0 };
    uint8_t d[sizeof(double)] = { 0 };
    uint8_t rRate[sizeof(uint8_t)] = { 0 };
    
    std::strncpy(name, nameString.c_str(), NAME_LENGTH - 1);
    std::strncpy(unit, unitString.c_str(), UNIT_LENGTH - 1);
    name[NAME_LENGTH - 1] = 0;
    unit[UNIT_LENGTH - 1] = 0;
    
    std::memcpy(a, &aDouble, sizeof(double));
    std::memcpy(b, &bDouble, sizeof(double));
    std::memcpy(c, &cDouble, sizeof(double));
    std::memcpy(d, &dDouble, sizeof(double));
    
    std::memcpy(rRate, &rRateInt, sizeof(uint8_t));
    
    uint8_t begIndex = 0;
    for(int eger = 0; eger < NAME_LENGTH && begIndex < STORAGE_LENGTH; eger++) {
        storage[begIndex] = name[eger];
        begIndex += 1;
    }
    for(int eger = 0; eger < UNIT_LENGTH && begIndex < STORAGE_LENGTH; eger++) {
        storage[begIndex] = unit[eger];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(double) && begIndex < STORAGE_LENGTH; eger++) {
        storage[begIndex] = a[eger];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(double) && begIndex < STORAGE_LENGTH; eger++) {
        storage[begIndex] = b[eger];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(double) && begIndex < STORAGE_LENGTH; eger++) {
        storage[begIndex] = c[eger];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(double) && begIndex < STORAGE_LENGTH; eger++) {
        storage[begIndex] = d[eger];
        begIndex += 1;
    }
    for(int eger = 0; eger < sizeof(uint8_t) && begIndex < STORAGE_LENGTH; eger++) {
        storage[begIndex] = rRate[eger];
        begIndex += 1;
    }
    
    char transmitArray[TRANSMIT_LENGTH] = { 0 };
    strcat(transmitArray, (char*)(pageIndex *64 + 63));
    strcat(transmitArray, (char*)(pageIndex * 64));
    strcat(transmitArray, (char*) storage);
    i2c.write((I2C_EEPROM_ADDR << 1), transmitArray, TRANSMIT_LENGTH);
    
    return true;
}