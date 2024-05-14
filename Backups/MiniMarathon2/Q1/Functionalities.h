#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <functional>
#include <vector>
#include "SizeInvalidException.h"

using Container = std::vector<std::string>;
using FType = std::function<void(std::string)>;
using ContainerFType = std::vector<FType>;


void CreateObjects(ContainerFType& fun, Container& data);
void Adapter(ContainerFType& fun, Container& data);
extern FType StringVowels;
extern FType CheckPrefix;
extern FType LastCharacters;
extern FType FirstLetter;
extern FType Consecutive;

#endif // FUNCTIONALITIES_H