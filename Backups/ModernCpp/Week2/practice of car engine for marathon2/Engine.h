#ifndef ENGINE_H
#define ENGINE_H
#include <ostream>

class Engine
{
private:
    int _horsepower;
    int _torque;
public:
    Engine() =default;
    Engine(const Engine&)=delete;
    Engine(Engine&&)=delete;
    Engine& operator=(const Engine&)=delete;
    Engine& operator=(Engine&&)=delete;
    ~Engine()=default;
    Engine(int horsepower,int torque);

    int horsepower() const { return _horsepower; }
    void setHorsepower(int horsepower) { _horsepower = horsepower; }

    int torque() const { return _torque; }
    void setTorque(int torque) { _torque = torque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

#endif // ENGINE_H
