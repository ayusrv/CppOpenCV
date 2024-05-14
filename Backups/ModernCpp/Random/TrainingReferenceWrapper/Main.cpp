#include<iostream>
#include<functional>
#include "Functionalities.h"

int main(){
    CompanyContainer data1;
    EmployeeContainer data2;
    CreateObjects(data1,data2);
    PrintObjects(data1);
    PrintEmployee(data2);
    std::cout<<"----------------------------------------\n";
    DeleteCompany(data1);
    PrintEmployee(data2);
    PrintObjects(data1);
    return 0;
}