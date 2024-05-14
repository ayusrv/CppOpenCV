#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "EngineType.h"

class Engine
{
private:
    std::string _m_engine_number;
    int _m_engine_torque;
    int _m_hoursepower;
    EngineType _m_engine_type;
public:
    Engine() = delete;
    Engine(const Engine&) = delete;
    Engine(Engine&&) = default;
    Engine& operator = (const Engine&) = delete;
    Engine& operator = (Engine&&) = delete;
    ~Engine() = default;
    Engine(std::string m_engine_number, int m_engine_torque, int m_hoursepower, EngineType m_engine_type);

    std::string mEngineNumber() const { return _m_engine_number; }
    void setMEngineNumber(const std::string &m_engine_number) { _m_engine_number = m_engine_number; }

    int engineTorque() const { return _m_engine_torque; }
    void setEngineTorque(int engine_torque) { _m_engine_torque = engine_torque; }

    int mHoursepower() const { return _m_hoursepower; }
    void setMHoursepower(int m_hoursepower) { _m_hoursepower = m_hoursepower; }

    EngineType mEngineType() const { return _m_engine_type; }
    void setMEngineType(const EngineType &m_engine_type) { _m_engine_type = m_engine_type; }

    std::string EnumToString(const EngineType& e) const;

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
