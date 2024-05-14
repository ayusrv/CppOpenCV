#include "Engine.h"

Engine::Engine(EngineType eType, float engineHorsePower, std::string engineNumber, EngineCylinder cType, float engineTorque)
:_eType{eType}, _engineHorsePower{engineHorsePower}, _engineNumber{engineNumber} ,_cType{cType}, _engineTorque{engineTorque}
{}


std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    std::string t1;
    if(rhs._eType==EngineType::REGULAR){
        t1="REGULAR";
    }
    else{
        t1="TURBOCHARGE";
    }
    std::string t2;
    if(rhs._cType==EngineCylinder::CYLINDER_4){
        t1="4 CYLINDER";
    }
    else{
        t1="6 CYLINDER";
    }
    os << "Engine Type: " << t1<<std::endl
       << "Engine Horse Power: " << rhs._engineHorsePower<<std::endl
       << "Engine Number: " << rhs._engineNumber<<std::endl
       << "Cylinder Type: " << t2<<std::endl
       << "Engine Torque: " << rhs._engineTorque<<std::endl;
    return os;
}
