#include "ElectricCar.h"
#include <iostream>

//Default Constructor
ElectricCar::ElectricCar() {}

//Getter Setter for Battery Capacity
int ElectricCar::batteryCapacity() { return battery_capacity; }
void ElectricCar::setBatteryCapacity(int batteryCapacity) { battery_capacity = batteryCapacity; }

//Getter Setter fot Time to Chnage
float ElectricCar::timeToCharge() { return time_to_charge; }
void ElectricCar::setTimeToCharge(float timeToCharge) { time_to_charge = timeToCharge; }

//Getter Setter for Motor Power
float ElectricCar::motorPower() { return motor_power; }
void ElectricCar::setMotorPower(float motorPower) { motor_power = motorPower; }

//Getter Setter for MAX POWER
float ElectricCar::maxPower() { return max_power; }
void ElectricCar::setMaxPower(float maxPower) { max_power = maxPower; }

//Getter Setter fot getRange
float ElectricCar::getRange() { return range; }
void ElectricCar::setRange(float range_) { range = range_; }

//Calling the destructor
ElectricCar::~ElectricCar()
{
    std::cout << "Destructor Called: " << std::endl;
}

//Overriding the drive class
void ElectricCar::drive()
{
    std::cout << "Total Range Covered: " << getRange() << std::endl;
}

//Taking the input
std::istream &operator>>(std::istream &in, ElectricCar &e)
{
    std::string name;
    int acceleration;
    int top_speed;
    float ex_showroom;
    float cost_registration;
    float road_tax;
    float insurance;
    float on_road_price;
    std::cout << "Enter Your Name: ";
    in>>name;
    std::cout << "Enter Acceleration: ";
    in >> acceleration;
    std::cout << "Enter Top Speed: ";
    in >> top_speed;
    std::cout << "Enter Ex Showroom Price: ";
    in >> ex_showroom;
    cost_registration = ex_showroom * 0.05;
    road_tax = ex_showroom * 0.04;
    insurance = ex_showroom * 0.08;
    on_road_price = cost_registration + ex_showroom + insurance + on_road_price + road_tax;
    e.setName(name);
    e.setAcceleration(acceleration);
    e.setTopSpeed(top_speed);
    e.setExShowroom(ex_showroom);
    e.setInsurance(insurance);
    e.setCostRegistration(cost_registration);
    e.setOnRoadPrice(on_road_price);
    e.setRoadTax(road_tax);
    std::cout << "Enter Battery Capacity: ";
    in >> e.battery_capacity;
    std::cout << "Enter time to charge: ";
    in >> e.time_to_charge;
    std::cout << "Enter Motor Power: ";
    in >> e.motor_power;
    std::cout << "Enter max power: ";
    in >> e.max_power;
    std::cout << "Enter Range: ";
    in >> e.range;
    return in;
}

//Printing the output
std::ostream &operator<<(std::ostream &out, ElectricCar &e)
{
    out << "Battery Capacity: " << e.batteryCapacity() << std::endl;
    out << "Time to Charge: " << e.timeToCharge() << std::endl;
    out << "Motor Power: " << e.motorPower() << std::endl;
    out << "Maximum Power: " << e.maxPower() << std::endl;
    out << "Range: " << e.getRange() << std::endl;
    return out;
}

//SHowing the details
void ElectricCar::showElectricCarDetails()
{
    std::cout << "Buyer Name: " << getName() << std::endl;
    std::cout << "Car Acceleration: " << getAcceleration() << std::endl;
    std::cout << "Top Speed: " << topSpeed() << std::endl;
    std::cout << "Ex SHowroom Price: " << exShowroom() << std::endl;
    std::cout << "Registration Cost: " << costRegistration() << std::endl;
    std::cout << "Road Tax: " << roadTax() << std::endl;
    std::cout << "Insurance: " << getInsurance() << std::endl;
    std::cout << "On Road Price: " << onRoadPrice() << std::endl;
    std::cout << "Battery Capacity: " << batteryCapacity() << std::endl;
    std::cout << "Time to Charge: " << timeToCharge() << std::endl;
    std::cout << "Motor Power: " << motorPower() << std::endl;
    std::cout << "Maximum Power: " << maxPower() << std::endl;
    std::cout << "Range: " << getRange() << std::endl;
}