#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"
#include <ostream>

class ElectricCar : public Car
{
private:
    int _battery_capacity {0};
    float _time_to_charge {0.0f};
    float _motor_power {0.0f};
    float _max_power {0.0f};
    float _range {0.0f};
public:
    ElectricCar() = default;                                // Default constructor enable
    ElectricCar( const ElectricCar&) = delete;              //If you don't want copy constructor desabled
    ElectricCar(ElectricCar &&) = delete;                   //Disabled move constructor
    ElectricCar& operator=(const ElectricCar&) = delete;    //Disbaled equal to operator
    ElectricCar& operator = (ElectricCar&&) = delete;       //C++ brand new, deletde move assignment operator
    ~ElectricCar() = default;

    float Drive() override;
    void ShowElectricCarDetails();

    ElectricCar(std::string name, int acceleration, int top_speed, float price, int battery_capacity, float time_charge, float motor_power, float max_power, float range);

    float range() const { return _range; }
    void setRange(float range) { _range = range; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs);

};

#endif // ELECTRICCAR_H
