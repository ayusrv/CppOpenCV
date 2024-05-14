#ifndef COMPANY_H
#define COMPANY_H
#include<iostream>
#include "Employee.h"
#include<functional>
class Company
{
    private:
        std::string _name;
        std::reference_wrapper<Employee> _employee;
    public:
        Company()=default;
        Company(const Company &)=delete;
        Company(Company && )=delete;
        Company & operator=(const Company & )=delete;
        Company &operator=(Company &&)=delete;
        ~Company()=default;
        Company(std::string name ,std::reference_wrapper<Employee> employee):_name{name},_employee{employee}{}

        friend std::ostream &operator<<(std::ostream &os, const Company &rhs) {
            os << "_name: " << rhs._name
                << " _employee: " << rhs._employee;
            return os;
        }
};

#endif // COMPANY_H
