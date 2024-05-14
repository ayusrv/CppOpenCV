/*
    Smart pointer: they are wrappers aroudn raw pointers to allow better memory mangement using RAII design pattern

        1)  shared_ptr;
        2)  unique_ptr;
        3)  weak pointer ; stocker pointer or token of shared_ptr
*/

/*
    <-------------20 bytes------------>
    [<---12bytes---> | <---8bytes--->]
         ptr1              ptr2
*/

#include <iostream>
#include "Employee.h"
#include <memory>
#include <thread>
#include <mutex>
#include <array>
#include <condition_variable>
std::mutex mt;
std::condition_variable cv;

bool allThreadsDone = false;

void ChangeName(std::shared_ptr<Employee> owner2)
{
    std::unique_lock<std::mutex> ul(mt);
    // std::lock_guard<std::mutex> lg(mt);
    owner2->setName("Ayush");
    std::cout<<*owner2<<std::endl;
}

void UpdateSalary(std::unique_ptr<Employee>& owner3)
{
    std::unique_lock<std::mutex> ul(mt);
    owner3->setSalary(3000.0f);
    std::cout<<*owner3<<std::endl;
}

int main(){
    std::shared_ptr<Employee> ptr1 = std::make_shared<Employee>("a",2,"A",2);
    std::unique_ptr<Employee> ptr2 = std::make_unique<Employee>("a",2,"A",2);
    std::thread t1(&ChangeName, ptr1);
    std::thread t2(&UpdateSalary, std::ref(ptr2)); //unique pointer mai reference pass krna hoga

    if(std::lock_guard<std::mutex> lg(mt); !allThreadsDone)
    {
        std::cout<<*ptr1<<std::endl;
        std::cout<<*ptr2<<std::endl;
    }

    t1.join();
    t2.join();
    allThreadsDone = true;

}