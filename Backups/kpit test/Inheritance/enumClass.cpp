#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum Designation
{
    Clerk,
    Manager,
    Engineer
};

class Date
{
public:
    int day, month, year;

    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

class Employee
{
public:
    int id;
    string name;
    Date birthdate;
    Designation desg;
    float salary;

    Employee(int empId, const string &empName, const Date &empBirthdate, Designation empDesignation, float empSalary)
        : id(empId), name(empName), birthdate(empBirthdate), desg(empDesignation), salary(empSalary) {}
};

string getVal(enum Designation deg){
    switch(deg)
    {
        case 0: return "Clerk";
        case 1: return "Manager";
        case 2: return "Engineer";
        default: return "Doctor";
    }
}

int main()
{
    Employee employees[3] = {
        {101, "John", Date(10, 5, 1990), Engineer, 60000.0},
        {102, "Alice", Date(15, 8, 1985), Manager, 75000.0},
        {103, "Bob", Date(25, 12, 1982), Clerk, 50000.0}};
    cout << "Employee Details:\n";
    float mx=0,mn=10000000;
    for(const Employee &emp: employees){
        mx=max(mx,emp.salary);
        mn=min(mn,emp.salary);
    }
    for(const Employee &emp : employees){
        if(emp.salary==mn){
            cout << "Employee ID: " << emp.id << ",Employee Name: " << emp.name << ", Birthdate: "
             << emp.birthdate.day << "/" << emp.birthdate.month << "/" << emp.birthdate.year
             << ", Designation: " << getVal(emp.desg) << ", Salary: " << emp.salary << "\n";
        }
    }
    for(const Employee &emp: employees){
        if(emp.salary!=mn && emp.salary!=mx){
            cout << "Employee ID: " << emp.id << ",Employee Name: " << emp.name << ", Birthdate: "
             << emp.birthdate.day << "/" << emp.birthdate.month << "/" << emp.birthdate.year
             << ", Designation: " << getVal(emp.desg) << ", Salary: " << emp.salary << "\n";
        }
    }
    for(const Employee &emp: employees){
        if(emp.salary==mx){
            cout << "Employee ID: " << emp.id << ",Employee Name: " << emp.name << ", Birthdate: "
             << emp.birthdate.day << "/" << emp.birthdate.month << "/" << emp.birthdate.year
             << ", Designation: " << getVal(emp.desg) << ", Salary: " << emp.salary << "\n";
        }
    }
    return 0;
}