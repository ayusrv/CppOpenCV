#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "CarType.h"
#include <ostream>

class Car : public Vehicle
{
private:
    CarType _type;
public:
    Car() = delete; //Deleting the default constructor
    ~Car() = default; //Defult of Destructor
    Car(const Car&) = delete; //Deleting the Copy COnstructor
    Car(Car&&) = delete; //Deleteing the move symantic
    Car& operator = (Car&) = delete; //Deleting the = operator
    Car& operator = (Car&&) = delete; //Deleting the = operator
    Car(std::string registration_number, std::string brand, float price, CarType type);

    //Overriding cost service 
    float CalculateServicingCost() override;
    
    //Overrding tax excemption
    float TaxExcemptionAmount() override;

    CarType type() const { return _type; }
    void setType(const CarType &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
