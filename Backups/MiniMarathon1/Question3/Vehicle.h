#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
class Vehicle
{
private:
    std::string _registration_number;
    std::string _brand;
    float _price;
public:
    Vehicle() = delete; //Deleting the default constructor
    ~Vehicle() = default; //Defult of Destructor
    Vehicle(const Vehicle&) = delete; //Deleting the Copy COnstructor
    Vehicle(Vehicle&&) = delete; //Deleteing the move symantic
    Vehicle& operator = (Vehicle&) = delete; //Deleting the = operator
    Vehicle& operator = (Vehicle&&) = delete; //Deleting the = operator
    Vehicle(std::string registration_number, std::string brand, float price);

    std::string registrationNumber() const { return _registration_number; }
    void setRegistrationNumber(const std::string &registration_number) { _registration_number = registration_number; }

    std::string brand() const { return _brand; }
    void setBrand(const std::string &brand) { _brand = brand; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    //Pire virtual fnction calculate service cost
    virtual float CalculateServicingCost() = 0;

    //Virtual tax excemption
    virtual float TaxExcemptionAmount();

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
