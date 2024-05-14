#ifndef Diesel_H
#define Diesel_H

#include <iostream>

class Diesel
{
private:
    std::string _name;
    int _acceleration;
    float _top_speed;
    float _rated_fuel_cosumption;
    float _rated_co2_emission;

public:
    Diesel() = default;
    Diesel(const Diesel &) = delete;
    Diesel(Diesel &&) = delete;
    Diesel &operator=(const Diesel &) = delete;
    Diesel &operator=(Diesel &&) = delete;
    ~Diesel() = default;
    Diesel(std::string name, int acceleration, float top_speed, float rated_fuel_cosumption, float rated_co2_emission);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    int acceleration() const { return _acceleration; }
    void setAcceleration(int acceleration) { _acceleration = acceleration; }

    float topSpeed() const { return _top_speed; }
    void setTopSpeed(float top_speed) { _top_speed = top_speed; }

    void Drive();
    void Pollution();

    float ratedFuelCosumption() const { return _rated_fuel_cosumption; }
    void setRatedFuelCosumption(float rated_fuel_cosumption) { _rated_fuel_cosumption = rated_fuel_cosumption; }

    float ratedCo2Emission() const { return _rated_co2_emission; }
    void setRatedCo2Emission(float rated_co2_emission) { _rated_co2_emission = rated_co2_emission; }

    friend std::ostream &operator<<(std::ostream &os, const Diesel &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Diesel &rhs);
};

#endif // Diesel_H
