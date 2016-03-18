#include "mbed.h"
#include "USBSerial.h"
#include "SensorInterface.cpp"

I2C i2c(P0_5, P0_4);

#include "Adafruit_ADS1015.h"
#include "Storage.h"

USBSerial serial(0x1f00, 0x2012, 0x0001, false);

Adafruit_ADS1015 ads1015[] = { Adafruit_ADS1015(0x48), Adafruit_ADS1015(0x49), Adafruit_ADS1015(0x4A), Adafruit_ADS1015(0x4B) } ;
int16_t analog[16] = { 0 };
bool digita[12] = { 0 };
Storage stor;   

DigitalOut myled(P0_2);

int main() {
    while(1) {
        myled = 1;
        wait(.1);
        myled = 0;
        wait(.1);
        
        ads1015[0].readADC_SingleEndedAll(analog[00], analog[01], analog[02], analog[03]);
        // ads1015[1].readADC_SingleEndedAll(analog[04], analog[05], analog[06], analog[07]);
        // ads1015[2].readADC_SingleEndedAll(analog[08], analog[09], analog[10], analog[11]);
        // ads1015[3].readADC_SingleEndedAll(analog[12], analog[13], analog[14], analog[15]);
        
        serial.printf("AIN0: %d \r\n",analog[00]);
        serial.printf("AIN1: %d \r\n",analog[01]);
        serial.printf("AIN2: %d \r\n",analog[02]);
        serial.printf("AIN3: %d \r\n \r\n",analog[03]);
    }
}
