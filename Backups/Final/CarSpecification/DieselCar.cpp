#include "DieselCar.h"
#include <iostream>

//Default Constructor
DieselCar::DieselCar() {}

//Getter Setter for the fuelConsumption
float DieselCar::ratedFuelCosumption() { return rated_fuel_cosumption; }
void DieselCar::setRatedFuelCosumption(float ratedFuelCosumption) { rated_fuel_cosumption = ratedFuelCosumption; }

//Getter Setter for the CO2 Emission
float DieselCar::ratedCo2Emission() { return rated_co2_emission; }
void DieselCar::setRatedCo2Emission(float ratedCo2Emission) { rated_co2_emission = ratedCo2Emission; }

//taking input and output by overriding
void DieselCar::showDieselCarDetails(){
    std::cout<<"Fuel Consumption: "<<ratedFuelCosumption()<<std::endl;
    std::cout<<"CO2 Emission: "<<ratedCo2Emission()<<std::endl;
}

//Overriding the drive function
void DieselCar::drive(){
    std::cout<<"Fuel Required: "<<ratedFuelCosumption()<<std::endl;
}

//Taking the input
std::istream & operator >>(std::istream &in, DieselCar &d){
    std::cout<<"Enter Fuel Consumption: ";
    in>>d.rated_fuel_cosumption;
    std::cout<<"Enter Rated CO2 Emission: ";
    in>>d.rated_co2_emission;
    return in;
}

//Printing the output
std::ostream & operator << (std::ostream &out, DieselCar &d){
    out<<"Fuel Consumption: "<<d.rated_fuel_cosumption<<std::endl;
    out<<"CO2 Emission: "<<d.rated_co2_emission<<std::endl;
    return out;
}

//Destructor Called
DieselCar::~DieselCar(){
    std::cout<<"Destructor Diesel"<<std::endl;
}


