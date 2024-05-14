#include "Functionalities.h"

//Creating an object
void CreateObject(Container &data)
{
    data.push_back(std::make_shared<Automobile>("BMW", AutomobileType::PRIVATE, 40000, 13.5));
    data.push_back(std::make_shared<Automobile>("Honda", AutomobileType::PRIVATE, 15000, 17.5));
    data.push_back(std::make_shared<Automobile>("Dodge", AutomobileType::TRANSPORT, 6000, 11.5));
    data.push_back(std::make_shared<Automobile>("Maruti", AutomobileType::TRANSPORT, 5000, 16.5));
}

//Display an object
void DisplayObject(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }   
    for(Pointer p : data){
        std::cout<<*p<<std::endl;
    }
}

//Calculating average price
float AverageMilage(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }
    float _average_milage = 0.0f;
    for(Pointer p : data){
        _average_milage += p->automobileMilage();
    }

    return _average_milage/data.size();
}

//Getting number of instance of same automobile type
int NumberInstances(Container &data, std::string automobile_type)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }
    int count=0;
    AutomobileType type;
    if(automobile_type=="PRIVATE"){
        type = AutomobileType::PRIVATE;
    }else{
        type = AutomobileType::TRANSPORT;
    }
    for(Pointer p: data){
        if(p->automobileType() == type){
            count++;
        }
    }
    return count;
}

//Cheking is price above 20000
bool PriceAbove20000(Container &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }
    for(Pointer p : data){
        if(p->automobilePrice() > 20000){
            return true;
        }
    }
    return false;
}
