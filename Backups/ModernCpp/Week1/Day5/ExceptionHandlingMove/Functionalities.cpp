#include "Functionalities.h"
#include "ExceptionHandle.h"

void CreateObject(conatiner &data)
{
    data.push_back(new ClassB(8776, new ClassA(70,"Ayush")));
    data.push_back(new ClassB(86, new ClassA(20,"Harsh")));
}

void PrintObject(conatiner &data)
{
    if(data.empty()){
        throw ExceptionHandle("No data available");
    }
    for(ClassB* cb : data){
        std::cout<<"Phone Number: "<<cb->phNo()<<std::endl;
        std::cout<<"Age: "<<cb->getAClass()->getAge()<<std::endl;
        std::cout<<"Name: "<<cb->getAClass()->getName()<<std::endl;
    }
}

void DeleteObject(conatiner &data)
{
    if(data.empty()){
        throw ExceptionHandle("No data available");
    }
    for(ClassB* c : data){
        delete c->getAClass();
        delete c;
    }
}
