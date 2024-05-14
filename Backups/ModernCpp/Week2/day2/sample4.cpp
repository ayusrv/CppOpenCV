#include <iostream>
#include <vector>
#include <memory>
#include <functional>
#include "EmptyContainerException.h"

class Employee;

using EmployeePointer = std::shared_ptr<Employee>;

class Employee
{
private:
    int _id;
    std::string _name;
    float _salary;

public:
    Employee() = delete;
    Employee(const Employee &) = delete;
    Employee(Employee &&) = delete;
    Employee &operator=(Employee &&) = delete;
    Employee &operator=(const Employee &) = delete;
    ~Employee() = default;
    Employee(int id, std::string name, float salary)
        : _id{id}, _name{name}, _salary{salary} {}

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    float operator+(const Employee &rhs)
    {
        return _salary + rhs._salary;
    }

    void operator()()
    {
        std::cout << "tax for the employee at 10%: " << (_salary * 0.1f);
    }
    float salary() const { return _salary; }
};
inline std::ostream &operator<<(std::ostream &os, const Employee &rhs)
{
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary;
    return os;
}

/*
    Objective: Take a container of raw pointers to Employee
    and filter and print details based on predicate passed
*/

void Adapter(const std::vector<EmployeePointer> &data, std::function<bool(EmployeePointer)> predicate)
{
    for (EmployeePointer ptr : data)
    {
        if (ptr)
        {
            if (predicate(ptr))
            {
                std::cout << *ptr << std::endl;
            }
        }
        // else
        // {
        //     throw EmptyContainerException("Nullptr");
        // }
    }
}

// bool checkError()

int main()
{
    std::vector<EmployeePointer> data{
        std::make_shared<Employee>(101, "Ayush", 10000),
        std::make_shared<Employee>(102, "Aman", 1000),
        nullptr,
        std::make_shared<Employee>(102, "Raj", 9000)};
    try
    {
        Adapter(
            data,
            [](EmployeePointer emp)
            {
                // checking the nullptr exception
                return emp->salary() > 8000;
            });
    }
    catch (EmptyContainerException &ex)
    {
        std::cout << ex.what();
    }
}