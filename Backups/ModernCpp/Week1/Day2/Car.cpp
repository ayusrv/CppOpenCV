#include "Car.h"

// Constructor delication means-> use multiple constrictors together of the same class to make the object
Car::Car(std::string id, std::string model, Engine *engine, CarType ctype)
    : _id{id}, _model{model}, _engine{engine},_type{ctype}{}

//We cannot use delegated cobstructors and member list initialization in the same constructor

Car::Car(std::string id, float price, std::string model, Engine *engine, CarType ctype)
    : Car(id, model, engine, ctype){
        _price = price;
    }



std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_id: " << rhs._id
       << " _price: " << rhs._price
       << " _model: " << rhs._model
       << " _engine: " << rhs._engine;
    return os;
}
