#ifndef CORPORATEEMPLOYEE_H
#define CORPORATEEMPLOYEE_H

#include "Employee.h"
#include <ostream>


class CorporateEmployee : public Employee
{
private:
    std::string _id;
public:
    CorporateEmployee() = delete;
    CorporateEmployee(const CorporateEmployee&) = default;
    CorporateEmployee(CorporateEmployee&&) = default;
    CorporateEmployee& operator= (CorporateEmployee&&) = default;
    CorporateEmployee& operator= (const CorporateEmployee&) = default;
    CorporateEmployee(std::string name, std::string address, int age, Gender gender, float salary, EmployeeType emp_type, std::string id);
    ~CorporateEmployee() = default;

    float CalculateTax();

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    friend std::ostream &operator<<(std::ostream &os, const CorporateEmployee &rhs);
};

#endif // CORPORATEEMPLOYEE_H
