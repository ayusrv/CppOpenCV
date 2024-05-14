#ifndef ICECAR_H
#define ICECAR_H

#include <iostream>

#include "EngineType.h"

class ICECar{
    private:
        std::string _id;
        std::string _brand_name;
        float _price;
        EngineType _engine_type;

    public:
        ICECar() = default;
        ICECar(const ICECar&) = delete;
        ICECar(ICECar&&) = delete;
        ICECar& operator = (const ICECar&) = delete;
        ICECar& operator = (ICECar&&) = delete;
        ICECar(std::string id, std::string brand_name, float price, EngineType engine_type);
        ~ICECar() = default;

        float CalculateRegistrationCharges();

        EngineType engineType() const { return _engine_type; }
        void setEngineType(const EngineType &engine_type) { _engine_type = engine_type; }

        float price() const { return _price; }
        void setPrice(float price) { _price = price; }

        std::string brandName() const { return _brand_name; }
        void setBrandName(const std::string &brand_name) { _brand_name = brand_name; }

        std::string id() const { return _id; }
        void setId(const std::string &id) { _id = id; }

        friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);
};

#endif // ICECAR_H
