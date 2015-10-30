#include <string>
#include <sstream>

#ifndef Sensor_H_
#define Sensor_H_
class Sensor {
  protected:
    std::string name;
    short index;
    int value;
    bool enabled;
    
  public:
    Sensor(){
      name = "UNNAMED SENSOR";
      index = -1; 
      value = -1;
      enable();
    }
    
    void setValue(int x) {
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
    
    short getIndex() {
      return index;
    }
    
    virtual int getValue() {
      if(enabled)
        return value;
      else 
        return -1;
    }
    
    std::string getJSON(){
      std::stringstream stream;
      stream << "{";
      stream << "\"name\": \"" << getName() << "\"";
      stream << ", " ;
      stream << "\"index\": " << getIndex();
      stream << ", " ;
      stream << "\"value\": " << getValue();
      stream << "}";
      return stream.str();
    }
};
#endif