#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include "Car.h"

/*
    College student: Create Objects takes one vector of car pointers
                        to store objects of child type

    Professional student: CreateObjects is a top level function which takes one argiment of type
                            std::vector to car pointers BY REFERENCE. This function returns void
*/

/*

HEAP
----
Name       acc    top     price         cap  charge_time  motomax   range
[NexonEV | 80  |  150  |  1870000.0f  |  34 |  2  |  300  |  600  |  320]
<-------------CAR------------------->
<------------------------------ELECTIR CAR------------------------------->


MAIN
data
[0X100h]

*/

void CreateObjects(std::vector<Car*> &data);
void PrintObject(std::vector<Car*> &data);
void DeleteObject(std::vector<Car*> &data);

#endif // FUNCTIONALITIES_H
