#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
class Employee
{
    private:
        int _id;
        std::string _ename;

    public:
        Employee() = default;
        Employee(const Employee &) = delete;
        Employee(Employee &&) = delete;
        Employee &operator=(const Employee &) = delete;
        Employee &operator=(Employee &&) = delete;
        ~Employee() = default;

        Employee(int id, std::string name) : _id{id}, _ename{name} {}

        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs)
        {
            os << "_id: " << rhs._id
            << " _ename: " << rhs._ename;
            return os;
        }
};

#endif // EMPLOYEE_H
