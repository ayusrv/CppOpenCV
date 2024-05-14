/*
    A situation where only one element needs to be accessed and it is the most recent item inserted into the container

    e.g. : A ocmpiler executing functions calls
    f1(){
        f2()
    }
    call stack

    f2<---------- recent added, top most entry, will be accessed first!
    f1<---------- still pending
    there are no iterators with stack
*/

#include <stack>
#include "Functionalities.h"
#include "Employee.h"

using Container = std::stack<Employee>;

int main()
{
    Container s1;
    s1.push(Employee("AYush", 30000, "ASE", 2)); 
}