#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <vector>
#include <memory>
#include "Automobile.h"
#include "EmptyContainerException.h"

using Pointer = std::shared_ptr<Automobile>; //Shared pointer for AUtomobile class
using Container = std::vector<Pointer>; //Vector for storing POINTER

//Creating an object
void CreateObject(Container &data);

//Display an object
void DisplayObject(Container &data);

//Calculating average price
float AverageMilage(Container &data);

//Getting nub=mber of instance of same automobile type
int NumberInstances(Container &data, std::string automobile_type);

//Cheking is price above 20000
bool PriceAbove20000(Container &data);



#endif // FUNCTIONALITIES_H
