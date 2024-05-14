#ifndef ELECTRICCAR
#define ELECTRICCAR
#include "CarSpecification.h"

class ElectricCar: public CarSpecification{

    private:

    //Setting the input
        int battery_capacity;
        float time_to_charge;
        float motor_power;
        float max_power;
        float range;

    public:

    //Default Constructor
        ElectricCar();

    //Getter Setter for Battery Capacity
        int batteryCapacity();
        void setBatteryCapacity(int batteryCapacity);

    //Getter Setter fot Time to Chnage
        float timeToCharge();
        void setTimeToCharge(float timeToCharge);

    //Getter Setter for Motor Power
        float motorPower();
        void setMotorPower(float motorPower);

    //Getter Setter for MAX POWER
        float maxPower();
        void setMaxPower(float maxPower);

    //Getter Setter fot getRange
        float getRange();
        void setRange(float range_);

    //Taking INput and output
        friend std::istream & operator >> (std::istream &in, ElectricCar &e);
        friend std::ostream & operator<< (std::ostream &out, ElectricCar &e);
        
    //Destructor
        ~ElectricCar();

    //Calling the drive
        void drive();

    //Show Function to display the details
        void showElectricCarDetails();

};

#endif
