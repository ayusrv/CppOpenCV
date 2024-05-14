#ifndef DIESELCAR
#define DIESELCAR
#include "CarSpecification.h"

class DieselCar: public CarSpecification{
    private:

    //Taking the input
        float rated_fuel_cosumption;
        float rated_co2_emission;

    public:

    //Default Constructor
        DieselCar();

    //Getter Setter for the fuelConsumption
        float ratedFuelCosumption();
        void setRatedFuelCosumption(float ratedFuelCosumption);

    //Getter Setter for the CO2 Emission
        float ratedCo2Emission();
        void setRatedCo2Emission(float ratedCo2Emission);

    //taking input and output by overriding
        friend std::istream & operator >> (std::istream &in, DieselCar &d);
        friend std::ostream & operator<< (std::ostream &out, DieselCar &d);
        
    //Destructor
        ~DieselCar();

    //Overriding the drive function
        void drive();

    //Show function to display the details
        void showDieselCarDetails();
        
};

#endif
