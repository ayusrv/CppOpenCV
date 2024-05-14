#include "CarSpecification.h"
#include <iostream>

//Default Constructor
CarSpecification::CarSpecification() {}


//Getter Setter foR Name
std::string CarSpecification::getName() { return name; }
void CarSpecification::setName(std::string &name_) { name = name_; }


//Getter Setter for Acceleration
int CarSpecification::getAcceleration() { return acceleration; }
void CarSpecification::setAcceleration(int acceleration_) { acceleration = acceleration_; }

//Getter Setter fot TopSPeed
int CarSpecification::topSpeed() { return top_speed; }
void CarSpecification::setTopSpeed(int topSpeed) { top_speed = topSpeed; }

//Getter Setter for ExShowroom
float CarSpecification::exShowroom() { return ex_showroom; }
void CarSpecification::setExShowroom(float exShowroom) { ex_showroom = exShowroom; }

//Getter Setter for Cost Registration
float CarSpecification::costRegistration() { return cost_registration; }
void CarSpecification::setCostRegistration(float costRegistration) { cost_registration = costRegistration; }

//Getter Setter for Road Tax
float CarSpecification::roadTax() { return road_tax; }
void CarSpecification::setRoadTax(float roadTax) { road_tax = roadTax; }

//Getter Setter for GetInsurance
float CarSpecification::getInsurance() { return insurance; }
void CarSpecification::setInsurance(float insurance_) { insurance = insurance_; }

//Getter Setter for on road price
float CarSpecification::onRoadPrice() { return on_road_price; }
void CarSpecification::setOnRoadPrice(float onRoadPrice) { on_road_price = onRoadPrice; }

//Taking the input for the variables
std::istream & operator >>(std::istream &in, CarSpecification &c){
    std::cout<<"Enter Your Name: ";
    in>>c.name;
    std::cout<<"Enter Acceleration: ";
    in>>c.acceleration;
    std::cout<<"Enter Top Speed: ";
    in>>c.top_speed;
    std::cout<<"Enter Ex Showroom Price: ";
    in>>c.ex_showroom;
    c.cost_registration = c.ex_showroom*0.05;
    c.road_tax = c.ex_showroom*0.04;
    c.insurance = c.ex_showroom*0.08;
    c.on_road_price = c.cost_registration + c.ex_showroom + c.insurance + c.on_road_price + c.road_tax;
    return in;
}

//Printing the output
std::ostream & operator << (std::ostream &out, CarSpecification &c){
    out<<"Buyer Name: "<<c.name<<std::endl;
    out<<"Car Acceleration: "<<c.acceleration<<std::endl;
    out<<"Top Speed: "<<c.top_speed<<std::endl;
    out<<"Ex SHowroom Price: "<<c.ex_showroom<<std::endl;
    out<<"Registration Cost: "<<c.cost_registration<<std::endl;
    out<<"Road Tax: "<<c.road_tax<<std::endl;
    out<<"Insurance: "<<c.insurance<<std::endl;
    out<<"On Road Price: "<<c.on_road_price<<std::endl;
    return out;
}

//Destructor
CarSpecification::~CarSpecification(){
    std::cout<<"Destructor Called: "<<std::endl;
}