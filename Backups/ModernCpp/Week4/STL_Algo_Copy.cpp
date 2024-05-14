#include "Employee.h"
#include "Functionalities.h"
#include <algorithm>
#include <numeric>

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);

    EmployeeContainer result1(data1.size()); //Destination is of same size as source

    /*Copy if issue, 
        1) copy semantic has to be supported
        2) we don't know how many instances will satisfy the condition
        3) to copy from source to destination, destination has to already be initialized with memory allocaated to it
    */
    EmployeePointerContainer result2(data2.size()); //Destination is of same size as source
    //Copy all the data
    std::copy(
        data1.begin(),
        data1.end(),
        result1.begin()
    );

    for(Employee e : result1)
    {
        std::cout<<e<<std::endl;
    }
    std::cout<<std::endl<<"--------------------------------------"<<std::endl<<std::endl;

    //Copy the data if it contains
    auto itr = std::copy_if(
        data2.begin(),
        data2.end(),
        result2.begin(),
        [](const Employee* emp){
            return emp->salary()>25000;
        }
    );

    //FIX THE SIZE DIFFERENCE ISSUE
    std::size_t actual_size = std::distance(result2.begin(), itr);
    result2.resize(actual_size);

    for(Employee* e : result2)
    {
        std::cout<<*e<<std::endl;
    }
}