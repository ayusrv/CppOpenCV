#include "Employee.h"
#include "Project.h"

Employee::Employee(std::string employee_id, std::string employee_name, float salary, std::shared_ptr<Project> project)
        : _employee_id{employee_id}, _employee_name{employee_name}, _project{project}, _salary{salary} {}

float Employee::TaxExemptionAmount()
{
    if(_salary<1000000){
        // std::cout<<(_salary*5)/100<<std::endl;
        return (_salary*5)/100;
    }else{
        // std::cout<<(_salary*10)/100<<std::endl;
        return (_salary*10)/100;
    }
}

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_employee_id: " << rhs._employee_id
       << " _employee_name: " << rhs._employee_name
       << " _salary: " << rhs._salary
       << " _project: " << *(rhs._project);
    return os;
}
