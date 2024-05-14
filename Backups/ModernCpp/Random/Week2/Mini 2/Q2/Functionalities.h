#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"product.h"
#include<vector>
#include<memory>
#include<set>


using ProductPointer=std::shared_ptr<product>;
using ProductContainer=std::vector<ProductPointer>;

void CreateObejects(ProductContainer& data);

//extern std::function<float(ProductContainer&,ProductType type)>AverageProductPrice;

//extern std::function<float(ProductContainer&)>ReturnProductTaxAmount;

// extern std::function<ProductContainer(ProductContainer&,int n)>LastNInstances;

//  extern std::function<std::set<std::string>(ProductContainer &data)> ReturnUniqueProductsBrand;

//extern std::function<std::array<int,2>(ProductContainer &data)> ReturnCount;

extern std::function<ProductContainer( ProductContainer&,std::string brand)> ReturnAdresses;

#endif // FUNCTIONALITIES_H
