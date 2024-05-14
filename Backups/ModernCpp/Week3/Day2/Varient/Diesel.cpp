#include "Diesel.h"

Diesel::Diesel(std::string name, int acceleration, float top_speed, float rated_fuel_cosumption, float rated_co2_emission)
        : _name{name}, _acceleration{acceleration}, _top_speed{top_speed}, _rated_fuel_cosumption{rated_fuel_cosumption}, _rated_co2_emission{rated_co2_emission} {}

void Diesel::Drive()
{
    std::cout<<"Total fuel consumption: "<<_rated_fuel_cosumption<<std::endl;
}

void Diesel::Pollution()
{
    std::cout<<"Total pollution by diesel car: "<<(_rated_co2_emission*_rated_fuel_cosumption)/0.25<<std::endl;
}

std::ostream &operator<<(std::ostream &os, const Diesel &rhs) {
    os << "_name: " << rhs._name
       << " _acceleration: " << rhs._acceleration
       << " _top_speed: " << rhs._top_speed
       << " _rated_fuel_cosumption: " << rhs._rated_fuel_cosumption
       << " _rated_co2_emission: " << rhs._rated_co2_emission;
    return os;
}
