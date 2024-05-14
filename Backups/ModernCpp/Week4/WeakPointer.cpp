#include "Employee.h"
#include <iostream>
#include <memory>
#include <thread>

void Magic(std::shared_ptr<Employee> e)
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<e->designation()<<"\n";
}

int main()
{
    std::shared_ptr<Employee> sptr = std::make_shared<Employee>("AYush", 20000, "ASE", 3);
    std::weak_ptr<Employee> wptr = sptr;
    Magic(sptr);
    if(wptr.lock())
    {
        std::cout<<"OWNER ZINDA HAI\n";
    }
    else{
        std::cout<<"OWNER TO GYA\n";
    }
    Magic(std::move(sptr));
    if(wptr.lock())
    {
        std::cout<<"OWNER ZINDA HAI\n";
    }
    else{
        std::cout<<"OWNER TO GYA\n";
    }
}