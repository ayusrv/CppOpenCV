#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "EngineType.h"
#include "EngineCylinder.h"

class Engine
{
private:
    EngineType _eType{EngineType::REGULAR};
    float _engineHorsePower{0.0f};
    std::string _engineNumber{""};
    EngineCylinder _cType{EngineCylinder::CYLINDER_4};
    float _engineTorque{0.0f};

public:
    Engine()=default;          // Default constructor enabled 
    
    Engine(const Engine&)=delete;              // Copy constructor disabled
    
    Engine(Engine&&)=delete;                   // Move Constructor disabled
    
    Engine& operator=(const Engine&)=delete;      // Copy Assignment Operator diabled
    
    Engine& operator=(Engine&&)=delete;       // Move Assignment Operator disabled
    
    ~Engine()=default;                      // Default destructor enabled

    Engine(EngineType _eType, float engineHorsePower, std::string engineNumber, EngineCylinder cType, float engineTorque);

    EngineType eType() const { return _eType; }
    void setEType(const EngineType &eType) { _eType = eType; }

    float engineHorsePower() const { return _engineHorsePower; }
    void setEngineHorsePower(float engineHorsePower) { _engineHorsePower = engineHorsePower; }

    std::string engineNumber() const { return _engineNumber; }
    void setEngineNumber(const std::string &engineNumber) { _engineNumber = engineNumber; }

    EngineCylinder cType() const { return _cType; }
    void setCType(const EngineCylinder &cType) { _cType = cType; }

    float engineTorque() const { return _engineTorque; }
    void setEngineTorque(float engineTorque) { _engineTorque = engineTorque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
