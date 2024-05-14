#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle(std::string name, int acceleration, float top_speed, float max_power, float range)
                : _name{name}, _acceleration{acceleration}, _top_speed{top_speed}, _max_power{max_power}, _range{range} {}

std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs) {
    os << "_name: " << rhs._name
       << " _acceleration: " << rhs._acceleration
       << " _top_speed: " << rhs._top_speed
       << " _max_power: " << rhs._max_power
       << " _range: " << rhs._range;
    return os;
}

void ElectricVehicle::Drive()
{
    std::cout << "Total Range Covered: " << range() << std::endl;
}

void ElectricVehicle::FinalSpeed()
{
    std::cout<<"Final speed is: "<<(_acceleration*_top_speed)/2<<std::endl;
}
