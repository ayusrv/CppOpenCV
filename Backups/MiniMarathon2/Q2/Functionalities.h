#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <functional>
#include <memory>
#include "Product.h"
#include "EnumNotFound.h"
#include "EmptyContainerException.h"

using Type = std::shared_ptr<Product>;
using ContainerAddress = std::vector<std::reference_wrapper<Product>>;
using Container = std::vector<Type>;

extern std::function<void(Container&)> CreateObjects;
extern std::function<float(Container&, ProductType)> AveragePrice;
extern std::function<void(Container&, unsigned int)> DisplayNTaxAounts;
extern std::function<void(Container&)> ProductTaxAmount;
extern std::function<void(Container&)> PrintGroupCategory;
extern std::function<Container(Container&, std::string)> SameBrand;
Container Adapter(Container& data,unsigned int);

#endif // FUNCTIONALITIES_H
