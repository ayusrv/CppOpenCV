#include "product.h"

product::product(std::string productId, ProductType type, float productPrice, std::string productBrand, ProductOrigin origin, float productTaxAmount)
:_productId(productId),_type(type),_productPrice(productPrice),_productBrand(productBrand),_origin(origin),_productTaxAmount(productTaxAmount)
{
    productTaxAmount = (productPrice *5)/100;
}
std::ostream &operator<<(std::ostream &os, const product &rhs) {
    os << "_productId: " << rhs._productId
       << " _type: " << static_cast<int> (rhs._type)
       << " _productPrice: " << rhs._productPrice
       << " _productBrand: " << rhs._productBrand
       << " _origin: " <<static_cast<int> (rhs._origin)
       << " _productTaxAmount: " << rhs._productTaxAmount;
    return os;
}
