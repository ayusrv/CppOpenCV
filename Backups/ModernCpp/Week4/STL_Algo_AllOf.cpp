//CHeck if all instances meet the condition, Return true if all meet else false
//return a boolean

#include "Functionalities.h"

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);

    std::cout<<std::boolalpha<<std::all_of(
        data3.begin(),
        data3.end(),
        [](const EmpSptr& e){return e->salary()>15000;}
    );

    // EmployeeContainer p;
    // std::copy_if(data1.begin(), data1.end(), p, [](Employee& e){
    //     return e.designation()=="SDE";
    // });

    // for(Employee e: p)
    // {
    //     std::cout<<e<<std::endl;
    // }
    
}


