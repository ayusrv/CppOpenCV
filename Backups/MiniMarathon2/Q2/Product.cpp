#include "Product.h"

std::ostream &operator<<(std::ostream &os, const Product &rhs) {
    os << "_product_id: " << rhs._product_id;
    os<< " _product_type: ";
    if(rhs.productType()==ProductType::APPLIANCE)
        os<<"Appliance ";
    else if(rhs.productType()==ProductType::FOOD)
        os<<"Food";
    else if(rhs.productType()==ProductType::PERFUME)
        os<<"Perfume";
    os << " _product_price: " << rhs._product_price
    <<" _brand_name: "<<rhs._product_brand
       << " _product_origin: ";

    if(rhs.productOrigin() == ProductOrigin::DOMESTIC)
        os<<"Domestic ";
    else if(rhs.productOrigin() == ProductOrigin::IMPORTED)
        os<<"Imported";
    os << " _product_tax: " << rhs._product_tax;
    return os;
}

Product::Product(std::string product_id, ProductType product_type, float product_price, std::string brand_name,ProductOrigin product_origin, float product_tax)
        : _product_id{product_id}, _product_type{product_type}, _product_price{product_price}, _product_brand{brand_name}, _product_origin{product_origin}, _product_tax{product_tax} {}