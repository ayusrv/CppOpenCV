#include "Functionalities.h"

void CreateObject(Conatiner &data)
{
    data.push_back(std::make_shared<Employee>("219382","Ayush",20000, std::make_shared<Project>("Modern",3000)));
    data.push_back(std::make_shared<Employee>("201983","Rohit",15000, std::make_shared<Project>("Java",4000)));
    data.push_back(std::make_shared<Employee>("219382","ROhan",30000, std::make_shared<Project>("Rust",7000)));
    data.push_back(std::make_shared<Employee>("219382","Suraj",40000, std::make_shared<Project>("GO",6000)));
    data.push_back(std::make_shared<Employee>("219382","Aryan",50000, std::make_shared<Project>("React",1000)));
}

void DisplayObject(Conatiner &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }   
    for(Pointer p : data){
        std::cout<<*p<<std::endl;
    }
}

int countInstances(Conatiner &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    } 
    int count=0;
    for(Pointer p : data){
        if(p->project()->projectBudget() > 5000){
            count++;
        }
    }
    return count;
}

bool EmployeesSalary(Conatiner &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    } 
    for(Pointer p : data){
        if(p->salary()<=10000){
            return false;
        }
    }
    return true;
}

float AverageTaxExcemption(Conatiner &data)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    } 
    float average = 0;
    for(Pointer p : data){
        std::cout<<p->TaxExemptionAmount()<<std::endl;
        average += p->TaxExemptionAmount();
    }
    return average/data.size();
}

void NInstances(Conatiner &data, int n)
{
    if(data.empty()){
        throw EmptyContainerException("Data is not available");
    }   
    if(n<=0 || n>data.size())
    {
        std::cout<<"Invalid data provided"<<std::endl;
    }

    for(int i= data.size()-1 ; i>=data.size()-n;i--){
        std::cout<<*data[i]<<std::endl;
    }
}
