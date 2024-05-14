#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

/*
    defaulted & deleted special member function
    override
    member list intialization
    in-class initialization
    for-each (range based for loop)
    enum class
    constructor delegation
*/

#include<array> //STL Array
#include "Car.h"
#include <memory>

using CarPointer = std::shared_ptr<Car>;

using Conatiner = std::array<CarPointer,3>; //Aab kahi v conatiner likho complier samajh jayeaga kya likhna hai

void createObjects(Conatiner& data);

// void deleteObjects(const Conatiner& data);

std::string convertENumCarType(CarType);

/*
    Calculate Total hoursepower
    input : Container
    Output : int
*/

int TotalHoursePower(const Conatiner& data);

// Is this condition true of false: ALl cars in the container have a price above 700000

bool IsContainerAllCarAbove700000(const Conatiner& data);

//return the _enginePointer of the cat whose price is lowest
//if multiple car instance have the same minimum, consider first car

Engine* EnginePointerToMinPriceCar(const Conatiner& data);

//Find the average torque for engine in the car

float AverageEngineTorque(const Conatiner& data);

//A function to print the model name of the car whose ID is passed as a parameter

std::string FindCarModelByID(const Conatiner& data, const std::string id);

#endif // FUNCTIONALITIES_H
