#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarCategory.h"
#include "RimSize.h"

class Car
{
private:
    std::string _brand_name;
    std::string _chassis_number;
    Category _category;
    float _price;
    RimSize _tyre_rim_size;
    int _expected_tyre_pressure;
    
public:
    Car()=default;
    Car(const Car &)=delete;
    Car(Car && )=delete;
    Car & operator=(const Car & )=delete;
    Car &operator=(Car &&)=delete;
    ~Car()=default;
    Car(std::string brand_name, std::string chassis_number, Category category, float price, RimSize tyre_rim_sime, int expected_tyre_pressure);

    std::string brandName() const { return _brand_name; }
    void setBrandName(const std::string &brand_name) { _brand_name = brand_name; }

    std::string chassisNumber() const { return _chassis_number; }
    void setChassisNumber(const std::string &chassis_number) { _chassis_number = chassis_number; }

    Category getCategory() const { return _category; }
    void setCategory(const Category &category_) { _category = category_; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    RimSize tyreRimSime() const { return _tyre_rim_size; }
    void setTyreRimSime(const RimSize &tyre_rim_size) { _tyre_rim_size = tyre_rim_size; }

    int expectedTyrePressure() const { return _expected_tyre_pressure; }
    void setExpectedTyrePressure(int expected_tyre_pressure) { _expected_tyre_pressure = expected_tyre_pressure; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
