/*
    How to use STL Algorithm effectively
*/

#include "Functionalities.h"

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);

    //Count instances matching a condition
    Employee emp;
    int ans = std::count_if(data1.begin(), data1.end(), check(emp));
    int ans2 = std::count_if(data2.begin(), data2.end(), [](const Employee* e){return e->designation()=="SDE";});
    int ans3 = std::count_if(data3.begin(), data3.end(), [](const std::shared_ptr<Employee> e){return e->designation()=="SDE";});
    std::cout<<ans<<" "<<ans2<<" "<<ans3<< std::endl;
    return 0;
}

//Count if takes predicated (lambda expression jo boolean return krega) and return the count
    //count instances matching with given condition, condition is written 