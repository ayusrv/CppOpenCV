#include "Functionalities.h"

// void CreateObjects(Container& data){
//     data.push_back(std::make_shared<ElectricVehicle>("Tesla",50,250,120,25));
//     data.push_back(std::make_shared<Diesel>("Dodge",50,250,3,2.5));
//     data.push_back(std::make_shared<ElectricVehicle>("Nexon",50,250,120,25));
//     data.push_back(std::make_shared<ElectricVehicle>("Mustang",50,300,5,2.5));
// }

// void DisplayObjects(Container& data){
//     for(VType v : data){
//         if(std::holds_alternative<std::shared_ptr<ElectricVehicle>>(v)){
//             std::shared_ptr<ElectricVehicle> ev = std::get<1>(v);
//             std::cout<<*ev<<std::endl;
//         }else{
//             std::shared_ptr<Diesel> d = std::get<0>(v);
//             std::cout<<*d<<std::endl;
//         }
//     }
// }

// void DriveData(Container &data)
// {
//     for(VType v : data){
//         std::visit([](auto&& val){val->Drive(); std::cout<<std::endl;},v);
//     }
// }

FnType CreateObjects=[](Container &data){
    data.push_back(std::make_shared<ElectricVehicle>("Tesla",50,250,120,25));
    data.push_back(std::make_shared<Diesel>("Dodge",50,250,3,2.5));
    data.push_back(std::make_shared<ElectricVehicle>("Nexon",50,250,120,25));
    data.push_back(std::make_shared<ElectricVehicle>("Mustang",50,300,5,2.5));
};


FnType DriveData=[](Container &data){
    for(VType v : data){
        std::visit([](auto&& val){val->Drive(); std::cout<<std::endl;},v);
    }
};

FnType DisplayObjects=[](Container &data){
    for(VType v : data){
        if(std::holds_alternative<std::shared_ptr<ElectricVehicle>>(v)){
            std::shared_ptr<ElectricVehicle> ev = std::get<1>(v);
            std::cout<<*ev<<std::endl;
        }else{
            std::shared_ptr<Diesel> d = std::get<0>(v);
            std::cout<<*d<<std::endl;
        }
    }
};



