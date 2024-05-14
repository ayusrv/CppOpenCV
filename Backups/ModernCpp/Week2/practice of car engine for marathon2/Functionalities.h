#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include "Cartype.h"
#include<vector>
#include "Car.h"
#include "Engine.h"
#include<memory>
#include<functional>
void createobject(std::vector<std::shared_ptr<Car>>&data,std::vector<std::shared_ptr<Engine>> &data1);
void calculate_avg_horse_power(std::function<int(std::vector<std::shared_ptr<Engine>>)>f1,std::vector<std::shared_ptr<Engine>>&data);
#endif // FUNCTIONALITIES_H
