#include "Functionalities.h"

//Creatung the Objects
void CreateObject(Container &data)
{
    data.push_back(std::make_shared<Car>("HR260001", "Toyata", 5200000, CarType::COMERCIAL));
    data.push_back(std::make_shared<Car>("JH052726", "Maruti", 1200000, CarType::TRANSPORT));
    data.push_back(std::make_shared<Bike>("MH017000", "BMW", 5200000, BreakingSystem::ABS));
    data.push_back(std::make_shared<Bike>("PB018882", "Honda", 2100000, BreakingSystem::TRADITIONAL));
}

//Displaying the Objects
void DisplayObject(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }

    //Dynamic casting according to the data
    for(Pointer p : data){
        if(typeid(*p) == typeid(Car)){
            std::shared_ptr<Car> c = std::dynamic_pointer_cast<Car>(p);
            std::cout<<*c<<std::endl;
        }else{
            std::shared_ptr<Bike> b = std::dynamic_pointer_cast<Bike>(p);
            std::cout<<*b<<std::endl;
        }
    }
}

//Printing the service cost
void PrintCalculateServicingCost(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }
    //Printing the 0th index of the data
    std::cout<<data[0]->CalculateServicingCost()<<std::endl;

    // printing the last instances of the data
    std::cout<<data[data.size()-1]->CalculateServicingCost()<<std::endl;
}

//Printing the tax excemption
void PrintTaxExcemption(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }

    //Tpe casting accordingly
    for(Pointer p : data){
        std::cout<<p->TaxExcemptionAmount();
    }
}

//Printing the vehichle object
void PrintVehicleObject(Container &data, std::string registration_number)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }

    //Checking for the registration number
    // for(Pointer p : data){
    //     if(p->registrationNumber() == registration_number){
    //         std::cout<<p->price()<<" "<<p->brand()<<std::endl;
    //     }
    // }

    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](const Pointer& p){
            return p->registrationNumber()==registration_number;
        }
    );

    std::cout<<(*itr)->price()<<std::endl;
}
