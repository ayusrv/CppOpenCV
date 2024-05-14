#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <functional>
#include <memory>
#include "productType.h"
#include "productOrigin.h"

class product
{
private:
    std::string _productId;
    ProductType _type;
    float _productPrice;
    std::string _productBrand;
    ProductOrigin _origin;
    float _productTaxAmount;

public:
    // Default Constructor
    product() = default;

    // Parameterized Constructor
    product(std::string productId,ProductType type,float productPrice, std::string productBrand, ProductOrigin origin, float productTaxAmount );

    // Copy Constructor
    product(const product &) = delete;

    // Copy Assignment Operator
    product &operator=(const product &) = delete;

    // Move Constructor
    product(product &&) = delete;

    // Move Assignment Operator
    product &operator=(product &&) = delete;

    ~product() = default;

    std::string productId() const { return _productId; }
    void setProductId(const std::string &productId) { _productId = productId; }

    ProductType type() const { return _type; }
    void setType(const ProductType &type) { _type = type; }

    float productPrice() const { return _productPrice; }
    void setProductPrice(float productPrice) { _productPrice = productPrice; }

    std::string productBrand() const { return _productBrand; }
    void setProductBrand(const std::string &productBrand) { _productBrand = productBrand; }

    ProductOrigin origin() const { return _origin; }
    void setOrigin(const ProductOrigin &origin) { _origin = origin; }

    float productTaxAmount() const { return _productTaxAmount; }
    void setProductTaxAmount(float productTaxAmount) { _productTaxAmount = productTaxAmount; }

    friend std::ostream &operator<<(std::ostream &os, const product &rhs);
};

#endif // PRODUCT_H
