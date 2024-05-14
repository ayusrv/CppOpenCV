#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Section.h"
#include <memory>
#include <iostream>
#include <vector>
using Container = std::vector<std::shared_ptr<Section>>;

void CreateObjects(Container &data);
void PrintObjects(Container &data);

#endif // FUNCTIONALITIES_H