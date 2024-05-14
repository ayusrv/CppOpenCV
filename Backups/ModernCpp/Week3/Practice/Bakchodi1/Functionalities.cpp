#include "Functionalities.h"
std::mutex mt;
FReturn CreateObject = [](VehicleType &data)
{
    data.push_back(std::make_shared<Vehicle>(std::make_shared<Car>("Alto", 4), 10.3));
    data.push_back(std::make_shared<Vehicle>(std::make_shared<Car>("Zen", 4), 20.4));
    data.push_back(std::make_shared<Vehicle>(std::make_shared<Bike>("Splendor", 2), 30.5));
    data.push_back(std::make_shared<Vehicle>(std::make_shared<Bike>("Passion Pro", 2), 40.5));
};

FReturn DisplayObject = [](VehicleType &data)
{
    std::lock_guard<std::mutex> ls(mt);
    for (auto v : data)
    {
        std::cout << *v << std::endl;
    }
};

FReturn UnCommonData = [](VehicleType &data)
{
    std::lock_guard<std::mutex> ls(mt);
    for (auto v : data)
    {
        if (std::holds_alternative<CarPointer>(v->variant()))
        {
            std::cout << "PRINTING THE NAME OF THE CAR \n";
            CarPointer cp = std::get<1>(v->variant());
            std::cout << cp->carName() << "\n";
        }
        else
        {
            std::cout << "Printing the Bike Name: \n";
            BikePointer bp = std::get<0>(v->variant());
            std::cout << bp->bikeType() << "\n";
        }
    }
};

FReturn CommonData = [](VehicleType &data)
{
    std::lock_guard<std::mutex> ls(mt);
    for (auto v : data)
    {
        std::visit([](auto &&args)
                   { std::cout<<"Wheels: "<<args->wheels()<<"\n"; },
                   v->variant());
    }
};