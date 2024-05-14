#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

#include <iostream>


class ElectricVehicle
{
private:
    std::string _name;
    int _acceleration;
    float _top_speed;
    float _max_power;
    float _range;

public:
    ElectricVehicle() = default;
    ElectricVehicle(const ElectricVehicle &) = delete;
    ElectricVehicle(ElectricVehicle &&) = delete;
    ElectricVehicle &operator=(const ElectricVehicle &) = delete;
    ElectricVehicle &operator=(ElectricVehicle &&) = delete;
    ~ElectricVehicle() = default;
    ElectricVehicle(std::string name, int acceleration, float top_speed, float max_power, float range);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int acceleration() const { return _acceleration; }
    void setAcceleration(int acceleration) { _acceleration = acceleration; }

    float topSpeed() const { return _top_speed; }
    void setTopSpeed(float top_speed) { _top_speed = top_speed; }

    float maxPower() const { return _max_power; }
    void setMaxPower(float max_power) { _max_power = max_power; }

    float range() const { return _range; }
    void setRange(float range) { _range = range; }

    void Drive();
    void FinalSpeed();

    friend std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs);
};

#endif // ELECTRICVEHICLE_H
