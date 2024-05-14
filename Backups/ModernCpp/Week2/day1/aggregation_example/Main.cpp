#include <iostream>

struct Employee{
    int _id;
    float _salary;
    Employee(int id, float salary) : _id{id}, _salary{salary} {}
    ~Employee() {}
};

void magic(Employee** arr){
    std::cout<<arr[0]->_salary;
}

void f3(){
    Employee* e1 = new Employee(10,900.5f);
    Employee* e2 = new Employee(30,6655.89f);
    Employee* e[2] = {e1,e2};
    magic(e);
}

int main(){
    f3();
}