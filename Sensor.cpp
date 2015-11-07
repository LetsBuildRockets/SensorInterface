#include <string>
#include <sstream>
#include <algorithm>
#include <ctype.h>
#include <math.h>

#ifndef Sensor_H_
#define Sensor_H_
class Sensor {
  protected:
    std::string name;
    int index;
    int value;
    bool enabled;
    
  public:
    Sensor() {
      name = "UNNAMED SENSOR";
      index = -1; 
      value = -1;
      enable();
    }
    
   virtual void setValue(double x) {
      value = x;
    }
  
    // Disables the interface
    void disable() {
      enable(false);
    }
    
    // Enables/Disables the interface
    void enable(bool en = true) {
      enabled = en;
      // TODO: enable/disable interface
    }
  
    std::string getName() {
      return name;
    }
    
    int getIndex() {
      return index;
    }
    
    virtual int getValue() {
      return value;
    }
    
    std::string getJSON() {
      std::stringstream stream;
      stream << "{";
      stream << "\"name\": \"" << name << "\"";
      stream << ", " ;
      stream << "\"index\": " << index;
      stream << ", " ;
      stream << "\"value\": " << value;
      stream << "}";
      return stream.str();
    }
    
    void loadJSON(std::string json) {
      std::istringstream jsSS(json);
      std::string line;
      while(std::getline(jsSS, line, ',')) {
        std::istringstream lnSS(line);
        std::string data;
        std::string valueTitle;
        for(uint8_t index = 0; index < 2 && std::getline(lnSS, data, ':'); index++) {   
          if(index) {
            uint8_t qone = data.find("\"");
            std::string str;
            if(qone >= 0 && qone < 16) {
              str = data.substr(qone+1);
              str = str.substr(0,str.find("\""));
            }
            if(valueTitle.compare("name") == 0) {
              name = str;
            }
            else if (valueTitle.compare("index") == 0) {
              std::stringstream num(data);
              double result = 0.0;
              num >> result;
              this->index = result;   // lol accidently reused index... whoops. don't care
            }
          } else {
            uint8_t qone = data.find("\"");
            std::string str = data.substr(qone+1);
            str = str.substr(0,str.find("\""));
            std::transform(str.begin(), str.end(), str.begin(), tolower);
            valueTitle = str;
          }
        }
      }
    }
    
};
#endif