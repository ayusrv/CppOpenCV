#include "Employee.h"
#include "Functionalities.h"
#include <algorithm>
#include <numeric>

int main()
{
     EmployeeContainer data1;
     EmployeePointerContainer data2;
     EmployeeSmartPointerContainer data3;
     CreateEmployees(data1);
     CreateEmployeesPointer(data2);
     CreateEmployeesSmartPointer(data3);

     /*
         rule1: default operation is binary +
     */

     // Total salary combined for all employee
     std::cout<<std::accumulate(
         data1.begin(),
         data1.end(),
         0.0f, // INitial value as third parameter
         [](float answer_upto_current_pointe, const Employee emp)
         {
              return answer_upto_current_pointe + emp.salary();
         })<<std::endl;

     std::cout<<std::accumulate(
         data2.begin(),
         data2.end(),
         0.0f, // INitial value as third parameter
         [](float answer_upto_current_pointe, const Employee* emp)
         {
              return answer_upto_current_pointe + emp->salary();
         })<<std::endl;

     std::cout<<std::accumulate(
         data3.begin(),
         data3.end(),
         0.0f, // INitial value as third parameter
         [](float answer_upto_current_pointe, const EmpSptr& emp)
         {
              return answer_upto_current_pointe + emp->salary();
         })<<std::endl;
}


/*
    Functional Programming
        - map : apply a logic(function) on all items in data collection (one by one)
        - filter : extracting itmes that staisfy a condtion from the data collection
        - reduce : collection/summarizing/gathering/converting multiple items into a single item based on a binary operation
 
        e.g. 10,20,30,40,50
            - reduce 5 number into 1 number by summation aggregration
            - reduce 5 number into 1 number by product aggregration
 
    ["Satyam" | 80000 | "Trainee" | 10]
    ["Ayush" | 88000 | "IT" | 10]
    ["Himanshu" | 80000 | "HR" | 10]
    ["Ksritij" | 80000 | "CEO" | 10]
 
 
    AUCV - answer upto current value
 
    init/AUCV
    0.0f        80000           88000       80000           80000  
    |           |               |           |               |
    |           |               |           |               |
    -------------               |           |               |
        |                       |           |               |
        |                       |           |               |
        80000 [AUCV]            |           |               |
        |                       |           |               |
        |                       |           |               |
        -------------------------           |               |
                    |                       |               |
                    |                       |               |
                    168000                  80000           |
                    |                       |               |
                    -------------------------               |
                                |                           |
                                248000                      |
                                |                           |
                                -----------------------------
                                                |
                                                |
                                                328000
 
 
 
*/

/*
    functional programming
        -map : applying a logic (function) on all items in data collection (one by one)
        - filter : extracting items that satisfy a condition from data collection
        - reduce - collecting/ summarizing/ gathering/ converting multiple items into a single item based on a binary operation

        e,g: 10,20,30,60,76
            -reduce 5 items into 1 number by summation aggregation
            - reduce 5 numbers into 1 by product aggregation

*/