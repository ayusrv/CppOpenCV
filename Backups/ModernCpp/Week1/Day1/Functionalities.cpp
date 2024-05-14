#include "Functionalities.h"
#include "ElectricCar.h"

void CreateObjects(std::vector<Car *> &data)
{
    data.push_back(new ElectricCar("NexonEV",80,150,1870000.90f, 33, 2, 300, 600, 320));
    data.push_back(new ElectricCar("XUV400",70,140,1670000.90f, 31, 2, 280, 600, 320));
}

void PrintObject(std::vector<Car*> &data){
    for(Car* c: data){
        if(typeid(*c) != typeid(ElectricCar)){
            ElectricCar *ec = dynamic_cast<ElectricCar*>(c);
            std::cout<<*ec<<std::endl;
        }
    }
}

void DeleteObject(std::vector<Car *> &data)
{
    //Modern

    // delete[] &data;

    for(Car* it: data){
        delete it;
    }

}
