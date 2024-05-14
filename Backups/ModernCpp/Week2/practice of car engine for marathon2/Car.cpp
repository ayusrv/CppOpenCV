#include "Car.h"

Car::Car(std::reference_wrapper<Engine> ref, std::string car_no, std::string id, int price, std::string model, cartype type):_ref{ref},_car_no{car_no},_id{id},_price{price},_model{model},_type{type}
{}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_ref: " << rhs._ref
       << " _car_no: " << rhs._car_no
       << " _id: " << rhs._id
       << " _price: " << rhs._price
       << " _model: " << rhs._model
       << " _type: " <<static_cast<int> (rhs._type);
    return os;
}




