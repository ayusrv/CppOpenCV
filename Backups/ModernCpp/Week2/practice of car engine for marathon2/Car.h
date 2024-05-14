#ifndef CAR_H
#define CAR_H
#include<iostream>
#include<functional>
#include "Engine.h"
#include "Cartype.h"
#include<memory>
class Car
{
private:
    std::reference_wrapper<Engine>_ref;
    std::string _car_no;
    std::string _id;
    int _price;
    std::string _model;
    cartype _type;
public:
    Car() =default;
    Car(const Car&)=delete;
    Car(Car&&)=delete;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&)=delete;
    ~Car()=default;
    Car(std::reference_wrapper<Engine>ref,std::string car_no,std::string id,int price,std::string model,cartype type);

    std::reference_wrapper<Engine>ref() const { return _ref; }
    void setRef(const std::reference_wrapper<Engine>&ref) { _ref = ref; }

    std::string carNo() const { return _car_no; }
    void setCarNo(const std::string &car_no) { _car_no = car_no; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    int price() const { return _price; }
    void setPrice(int price) { _price = price; }

    std::string model() const { return _model; }
    void setModel(const std::string &model) { _model = model; }

    cartype type() const { return _type; }
    void setType(const cartype &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

    
};

#endif // CAR_H
