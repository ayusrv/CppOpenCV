#include "Bike.h"

//Output stream
std::ostream &operator<<(std::ostream &os, const Bike &rhs) {
    os << static_cast<const Vehicle &>(rhs);
    os    << " _type: ";
    if(rhs._type == BreakingSystem::ABS)
        os<<"ABS";
    else if(rhs._type == BreakingSystem::TRADITIONAL)
        os<<"Traditional";
    return os;
}

//Parameterized constructor
Bike::Bike(std::string registration_number, std::string brand, float price, BreakingSystem type)
        : Vehicle(registration_number, brand, price), _type{type} {}


//Calculating the service cost
float Bike::CalculateServicingCost()
{
    float previous_cost = 0.25 * price();

    return previous_cost + (0.18* price());
}
