#include "Engine.h"

Engine::Engine(std::string m_engine_number, int m_engine_torque, int m_hoursepower, EngineType m_engine_type)
        : _m_engine_number{m_engine_number}, _m_engine_torque{m_engine_torque}, _m_engine_type{m_engine_type}, _m_hoursepower{m_hoursepower} {}

std::string Engine::EnumToString(const EngineType &e) const
{
    if(e==EngineType::CRDI) return "CRDI";
    else if(e==EngineType::MPFI) return "MPFI";
    return "TURBOCHARGED";
}

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_m_engine_number: " << rhs._m_engine_number
       << " _m_engine_torque: " << rhs._m_engine_torque
       << " _m_hoursepower: " << rhs._m_hoursepower
       << " _m_engine_type: " << rhs.EnumToString(rhs._m_engine_type);
    return os;
}