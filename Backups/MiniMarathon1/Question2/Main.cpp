#include "Functionalities.h"

int main()
{
    Conatiner data;
    CreateObject(data);
    try
    {
        DisplayObject(data);
        std::cout << "Toatl instances: " << countInstances(data) << std::endl;
        std::cout << "Employee salary is abouve 10000: " << EmployeesSalary(data) << std::endl;
        std::cout << "Average Tax Excemption: " << AverageTaxExcemption(data) << std::endl;
        NInstances(data, 3);
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what();
    }
}