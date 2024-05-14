#include<iostream>
#include "Employee.h"
#include "Company.h"

using CompanyContainer=std::vector<Company *>;
using EmployeeContainer=std::vector<Employee *>;


void CreateObjects(CompanyContainer & data1,EmployeeContainer &data2){
    data2.push_back(new Employee(1,"Himanshu Kaushik"));
    data1.push_back(new Company("KPIT",*data2[0]));
}



void PrintObjects(CompanyContainer &data){
    if(data.empty()){
        std::cout<<"Maa chud gai company ki"<<std::endl;
        return;
    }
    for(Company * c:data){
        if(c){
            std::cout<<*c<<std::endl;
        }
        else{
            std::cout<<"Tu chud chuka hai 3 baar "<<std::endl;
            return;
        } 
    }
}

void DeleteCompany(CompanyContainer &data){
    for (Company * c:data){
        delete c;
    }
    data.clear();
}

void PrintEmployee(EmployeeContainer &data){
    for(Employee * e:data){
        std::cout<<*e<<std::endl;
    }
}