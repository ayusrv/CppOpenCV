#include <iostream>
#include <thread>
#include <functional>

void fun(int x){
    while (x-->0)
    {
        std::cout<<x<<std::endl;
    }
}

class Base{
    public:
        void operator()(int x){
            while(x-->0)
                std::cout<<x<<std::endl;
        }

        void run(int x){
            while(x-->0)
                std::cout<<x<<std::endl;
        }

        static void run2(int x){
            while(x-->0)
                std::cout<<x<<std::endl;
        }


};

int main(){
    std::cout<<"Functoin Pointer: "<<std::endl;
    std::thread t1(fun, 5); //Function pointer
    t1.join();

    auto fun2 = [](int x){
        while(x-->0){
            std::cout<<x<<std::endl;
        }
    };

    std::cout<<"Lambda Function: "<<std::endl;
    std::thread t2(fun2,5); //lambda functions
    t2.join();

    std::cout<<"Functors: "<<std::endl;
    std::thread t3((Base()), 5); //Functors
    t3.join();

    std::cout<<"Non static members: "<<std::endl;
    Base b;
    std::thread t4(&Base::run, &b, 5); //Non static members
    t4.join();

    std::cout<<"Static members: "<<std::endl;
    std::thread t5(&Base::run2, 5); //Static members
    t5.join();
}