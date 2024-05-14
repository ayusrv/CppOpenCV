#ifndef CAR_H
#define CAR_H

#include "Engine.h"
#include <functional>
#include <ostream>

class Car
{
private:
    std::string _m_car_reg_num;
    float _m_price;
    std::reference_wrapper<Engine> _m_car_engine;
public:
    Car()=default;
    Car(const Car &)=delete;
    Car(Car && )=delete;
    Car & operator=(const Car & )=delete;
    Car &operator=(Car &&)=delete;
    Car(std::string m_car_reg_num, float m_price, std::reference_wrapper<Engine> m_car_engine);
    ~Car()=default;

    std::string mCarRegNum() const { return _m_car_reg_num; }
    void setMCarRegNum(const std::string &m_car_reg_num) { _m_car_reg_num = m_car_reg_num; }

    float mPrice() const { return _m_price; }
    void setMPrice(float m_price) { _m_price = m_price; }

    std::reference_wrapper<Engine> mCarEngine() const { return _m_car_engine; }
    void setMCarEngine(const std::reference_wrapper<Engine> &m_car_engine) { _m_car_engine = m_car_engine; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
