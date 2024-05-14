#include "ElectricCar.h"

ElectricCar::ElectricCar(std::string name, int acceleration, int top_speed, float price, int battery_capacity, float time_charge, float motor_power, float max_power, float range)
            :Car(name, acceleration, top_speed, price), _battery_capacity{battery_capacity}, _time_to_charge{time_charge}, 
              _motor_power{motor_power}, _max_power{max_power}, _range{range}{}

float ElectricCar::Drive(){return _range;}

void ElectricCar::ShowElectricCarDetails()
{
    std::cout
       << " _battery_capacity: " << _battery_capacity
       << " _time_to_charge: " << _time_to_charge
       << " _motor_power: " << _motor_power
       << " _max_power: " << _max_power
       << " _range: "<<_range;
}

std::ostream &operator<<(std::ostream &os, const ElectricCar &rhs) {
    os << static_cast<const Car &>(rhs)
       << " _battery_capacity: " << rhs._battery_capacity
       << " _time_to_charge: " << rhs._time_to_charge
       << " _motor_power: " << rhs._motor_power
       << " _max_power: " << rhs._max_power
       << " _range: "<<rhs._range;
    return os;
}