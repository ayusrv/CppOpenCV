#ifndef EVCAR_H
#define EVCAR_H

#include <iostream>

#include "EPowerType.h"
#include "BatteryType.h"

class EvCar{
    private: 
        std::string _id;
        std::string _brand_name;
        float _price;
        EPowerType _engine_type;
        BatteryType _battery_type;
    public:
        EvCar() = default;
        EvCar(const EvCar&) = delete;
        EvCar(EvCar&&) = delete;
        EvCar& operator = (const EvCar&) = delete;
        EvCar& operator = (EvCar&&) = delete;
        EvCar(std::string id, std::string brand_name, float price, EPowerType engine_type, BatteryType battery_type);
        ~EvCar() = default;

        float CalculateRegistrationCharges();

        std::string id() const { return _id; }
        void setId(const std::string &id) { _id = id; }

        std::string brandName() const { return _brand_name; }
        void setBrandName(const std::string &brand_name) { _brand_name = brand_name; }

        float price() const { return _price; }
        void setPrice(float price) { _price = price; }

        EPowerType engineType() const { return _engine_type; }
        void setEngineType(const EPowerType &engine_type) { _engine_type = engine_type; }
        
        BatteryType batteryType() const { return _battery_type; }
        void setBatteryType(const BatteryType &battery_type) { _battery_type = battery_type; }

        friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_H
