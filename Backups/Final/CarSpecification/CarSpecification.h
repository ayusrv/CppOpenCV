#ifndef CARSPECIFICATION
#define CARSPECIFICATION

#include<iostream>
class CarSpecification{
    
    //Taking the input
    private:
        std::string name;
        int acceleration;
        int top_speed;
        float ex_showroom;
        float cost_registration;
        float road_tax;
        float insurance;
        float on_road_price;

    public:

    //Creating the constructor
        CarSpecification();

    //Getter Setter for Name
        std::string getName();
        void setName(std::string &name_);

    //Getter Setter for Acceleration
        int getAcceleration();
        void setAcceleration(int acceleration_);

    //Getter Setter fot TopSPeed
        int topSpeed();
        void setTopSpeed(int topSpeed);

    //Getter Setter for ExShowroom
        float exShowroom();
        void setExShowroom(float exShowroom);

    //Getter Setter for Cost Registration
        float costRegistration();
        void setCostRegistration(float costRegistration);

    //Getter Setter for Road Tax
        float roadTax();
        void setRoadTax(float roadTax);

    //Getter Setter for GetInsurance
        float getInsurance() ;
        void setInsurance(float insurance_);

    //Getter Setter for on road price
        float onRoadPrice();
        void setOnRoadPrice(float onRoadPrice);

    //Taking INput and outpur
        friend std::istream & operator >> (std::istream &in, CarSpecification &c);
        friend std::ostream & operator<< (std::ostream &out, CarSpecification &c);

    //Virtual abstract function
        virtual void drive() = 0;

    //Destructor
        ~CarSpecification();
};

#endif