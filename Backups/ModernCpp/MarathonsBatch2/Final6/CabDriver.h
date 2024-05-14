#ifndef CABDRIVER_H
#define CABDRIVER_H

#include <iostream>
#include "CarType.h"

class CabDriver
{
private:
    std::string _name;
    int _km;
    float _price;
    std::string _company;
    CarType _car_type;
    int _total_wheels;
public:
    CabDriver() = default;
    CabDriver(const CabDriver&) = delete;
    CabDriver(CabDriver&&) = delete;
    CabDriver& operator= (CabDriver&&) = delete;
    CabDriver& operator= (const CabDriver&) = delete;
    ~CabDriver() = default;
    CabDriver(std::string name, int km, float price, std::string company, CarType car_type, int total_wheels);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int km() const { return _km; }
    void setKm(int km) { _km = km; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    std::string company() const { return _company; }
    void setCompany(const std::string &company) { _company = company; }

    CarType carType() const { return _car_type; }
    void setCarType(const CarType &car_type) { _car_type = car_type; }

    int totalWheels() const { return _total_wheels; }
    void setTotalWheels(int total_wheels) { _total_wheels = total_wheels; }

    friend std::ostream &operator<<(std::ostream &os, const CabDriver &rhs);
};

#endif // CABDRIVER_H

/*
    class cabDriver{
        string name, int km, float price, string company, enum carType{Sedan SUV Hatchback}, totalWHeels 
    }

    Functionalities{
        1-> take lambda function inputs in vector and apply them accordingly
        2-> take pair in input and n in input
        3-> unordered<set> of names
        4-> priorityQueue to sort by price
        
    }

*/
