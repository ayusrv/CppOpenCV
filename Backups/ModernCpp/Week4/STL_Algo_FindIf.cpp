#include "Functionalities.h"
#include <functional>
// std::findIf -> return {iterator} to the first matching operator, if match not found it returns end iterator

template <typename T, typename P>
typename T::const_iterator Search(const T &data, P fn)
{
    auto itr = std::find_if(data.begin(), data.end(), fn);

    // check itr mai kya aaya hai last aaya hai ya phela aaya hai
    try
    {
        if (itr == data.end())
        {
            throw std::runtime_error("Object not found");
            return itr;
        }
        else
        {
            // std::cout << "Object Found: " << *itr << std::endl;
            return itr;
        }
    }
    catch (std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl;
        return itr;
    }
}

int main()
{
    EmployeeContainer data1;
    EmployeePointerContainer data2;
    EmployeeSmartPointerContainer data3;
    CreateEmployees(data1);
    CreateEmployeesPointer(data2);
    CreateEmployeesSmartPointer(data3);

    auto itr = Search<EmployeeContainer, std::function<bool(const Employee &)>>(data1, [](const Employee &e)
                                                                     { return e.designation() == "SDE"; });

    // EmployeeContainer::const_iterator

    auto itr2 = Search<EmployeePointerContainer, std::function<bool(const Employee *)>>(data2, [](const Employee *e)
                                                                            { return e->designation() == "ASE"; });

    std::cout<<*itr<<std::endl;
    std::cout<<**itr2<<std::endl;
}