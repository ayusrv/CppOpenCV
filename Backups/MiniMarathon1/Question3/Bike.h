#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"
#include "BreakingSystem.h"
#include <ostream>
class Bike : public Vehicle
{
private:
    BreakingSystem _type;
public:
    Bike() = delete; //Deleting the default constructor
    ~Bike() = default; //Defult of Destructor
    Bike(const Bike&) = delete; //Deleting the Copy COnstructor
    Bike(Bike&&) = delete; //Deleteing the move symantic
    Bike& operator = (Bike&) = delete; //Deleting the = operator
    Bike& operator = (Bike&&) = delete; //Deleting the = operator
    Bike(std::string registration_number, std::string brand, float price, BreakingSystem type);

    //Overridng the calculate service cost
    float CalculateServicingCost() override;

    BreakingSystem getBs() const { return _type; }
    void setBs(const BreakingSystem &bs_) { _type = bs_; }

    friend std::ostream &operator<<(std::ostream &os, const Bike &rhs);
};

#endif // BIKE_H
