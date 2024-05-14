#include "Employee.h"
#include "Functionalities.h"
#include <algorithm>

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);

    //Note if there are two or more max values first max returns
    auto mx = std::max_element(
        data1.begin(),
        data1.end(),
        [](const Employee& emp1, const Employee& emp2){
            return emp1.salary()<emp2.salary();
        }
    ); //Comparision logic or comperator

    //If two employees EMP1 and EMP2 are compared, emp1 is greater than emp2 only if emp1.salary > emp2.salary
    std::cout<<"Designation of max sal employee is: "<<mx->designation()<<std::endl;

    auto mx2 = std::min_element(
        data2.begin(),
        data2.end(),
        [](const Employee* emp1, const Employee* emp2){
            return emp1->salary()<emp2->salary();
        }
    ); //Comparision logic or comperator

    //If two employees EMP1 and EMP2 are compared, emp1 is greater than emp2 only if emp1.salary > emp2.salary
    std::cout<<"Designation of max sal employee is: "<<(*mx2)->designation()<<std::endl;
}