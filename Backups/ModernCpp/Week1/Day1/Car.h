#ifndef CAR_H
#define CAR_H
#include<iostream>

class Car
{
private:
    std::string _name {""};
    int _acceleration {0};
    int _top_speed {0};
    float _ex_showrrom_price {0.0f};
public:

    Car() = default;                        // Default constructor enable
    Car( const Car&) = delete;              //If you don't want copy constructor desabled
    Car(Car &&) = delete;                   //Disabled move constructor
    Car& operator=(const Car&) = delete;    //Disbaled equal to operator
    Car& operator = (Car&&) = delete;       //C++ brand new, deletde move assignment operator
    virtual ~Car() = default;               //Default destructor enabled

    Car(std::string name, int acceleration, int top_speed, float price);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int acceleration() const { return _acceleration; }
    void setAcceleration(int acceleration) { _acceleration = acceleration; }

    int topSpeed() const { return _top_speed; }
    void setTopSpeed(int top_speed) { _top_speed = top_speed; }

    float exShowrromPrice() const { return _ex_showrrom_price; }
    void setExShowrromPrice(float ex_showrrom_price) { _ex_showrrom_price = ex_showrrom_price; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    virtual float Drive() = 0;
    
};

#endif // CAR_H