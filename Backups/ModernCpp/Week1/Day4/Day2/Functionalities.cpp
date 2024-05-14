#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundException.h"

void createObjects(Conatiner &data)
{
    data[0] = std::make_shared<Car>(
        "C101",
        779000.0f,
        "Dezire", 
        new Engine(
            300,
            100.0f
        ),
        CarType::SEDAN
    );

    data[1] = std::make_shared<Car>(
        "C102",
        759000.0f,
        "Baleno", 
        new Engine(
            200,
            150.0f
        ),
        CarType::SUV
    );

    data[2] = std::make_shared<Car>(
        "C103",
        479000.0f,
        "HOnda City", 
        new Engine(
            500,
            300.0f
        ),
        CarType::SEDAN
    );
}

std::string convertENumCarType(CarType car){
    switch (car)
    {
    case CarType::HATCHBACK :
        return "HatchBack";
    
    case CarType::SEDAN:
        return "Sedan";

    case CarType::SUV:
        return "SUV";

    default:
        return "";
    }
    return "";
}


int TotalHoursePower(const Conatiner &data)
{

    if(data.empty()){
        throw EmptyContainerException("Data is empty");
    }

    int total = 0.0f;

    for(const CarPointer& c : data){
        total += c->engine()->horsepower();
    }
    return total;
}

bool IsContainerAllCarAbove700000(const Conatiner &data)
{

    if(data.empty()){
        throw EmptyContainerException("Data is empty");
    }

    for(const CarPointer& c: data){
        if(c->price() <= 700000.0f) return false;
    }
    return true;
}

Engine *EnginePointerToMinPriceCar(const Conatiner &data)
{

    if(data.empty()){
        throw EmptyContainerException("Data is empty");
    }

    //assume the first data value as your min;
    float min_price = data[0]->price();
    Engine* e = data[0]->engine();
    // for(int i=1;i<data.size();i++){
    //     if(min_price>data[i]->price()){
    //         e = data[i]->engine();
    //     }
    // }

    for(const CarPointer& c : data){
        if(c->price() < min_price){
            min_price = c->price();
            e = c->engine();
        }
    }

    return e;
}

float AverageEngineTorque(const Conatiner &data)
{

    if(data.empty()){
        throw EmptyContainerException("Data is empty");
    }
    float average_value = 0;
    // float average_value {0}; Both can be fine
    for(const CarPointer& c: data){
        average_value+=c->engine()->torque();
    }
    return average_value/data.size();
}

std::string FindCarModelByID(const Conatiner &data, const std::string id)
{

    if(data.empty()){
        throw EmptyContainerException("Data is empty");
    }

    for(const CarPointer& c : data){
        if(c->model()==id){
            return c->model();
        }
    }

    throw IdNotFoundException("Id not found");
}



/*

    A basic layout of a smart pointer
                                                                    HEAP
                                                                0X100H
                                                                [ 101 | HARSHIT | 80000.0f ]
    Stack Memory
    [
        mptr
        [ 0X100H]

    ]

    <------- Shared Pointer--->
*/