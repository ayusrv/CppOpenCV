#include <iostream>
#include <functional>
#include <vector>
using DataConatiner = std::vector<int>;
using FType = std::function<int(DataConatiner&)>;
using Container = std::vector<FType>;
using Standardize = std::function<void(DataConatiner&)>;

void CreateObject(Container &data);
void PrintObject(Container &data, DataConatiner &data2);
void CreateObjects2(std::vector<Standardize> fun, DataConatiner &v);
void sum(DataConatiner &data);
void sub(DataConatiner &data);
void mul(DataConatiner &data);
void sum1(int a, int b);