#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include "ProductOrigin.h"
#include "ProductType.h"

class Product
{
private:
    std::string _product_id;
    ProductType _product_type;
    float _product_price;
    std::string _product_brand;
    ProductOrigin _product_origin;
    float _product_tax;
    
public:
    Product() = delete;
    ~Product() = default;
    Product(const Product&) = delete;
    Product(Product&&) = delete;
    Product& operator = (const Product&) = delete;
    Product& operator = (const Product&&) = delete;
    Product(std::string product_id, ProductType product_type, float product_price, std::string brand_name, ProductOrigin product_origin, float product_tax);

    std::string productId() const { return _product_id; }
    void setProductId(const std::string &product_id) { _product_id = product_id; }

    ProductType productType() const { return _product_type; }
    void setProductType(const ProductType &product_type) { _product_type = product_type; }

    float productPrice() const { return _product_price; }
    void setProductPrice(float product_price) { _product_price = product_price; }

    ProductOrigin productOrigin() const { return _product_origin; }
    void setProductOrigin(const ProductOrigin &product_origin) { _product_origin = product_origin; }

    float productTax() const { return _product_tax; }
    void setProductTax(float product_tax) { _product_tax = product_tax; }

    std::string productBrand() const { return _product_brand; }
    void setProductBrand(const std::string &product_brand) { _product_brand = product_brand; }

    friend std::ostream &operator<<(std::ostream &os, const Product &rhs);
};

#endif // PRODUCT_H
