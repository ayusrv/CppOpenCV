#include <iostream>
#include <thread>
#include <array>
#include "Functionalities.h"

int main(){
    OperationPointer data;

    TakeInput(data);

    try{
        std::thread t[6];
        
        std::thread t1(FindMax, std::ref(data));
        t1.join();


        int s=0;
        std::cout<<"Enter n for sum: "<<std::endl;
        std::cin>>s;
        std::thread t2(&SumOfFirstN, std::ref(data), s);
        t2.join();

        int m=0;
        std::cout<<"Enter n for value: "<<std::endl;
        std::cin>>m;
        std::thread t3(&FindNthValue, std::ref(data), m);
        t3.join();

        std::thread t4(&FindOddNUmber, std::ref(data));
        std::thread t5(&FindFactorial, std::ref(data));
        std::thread t6(&checkPrime, std::ref(data));

        t4.join();
        t5.join();
        t6.join();
    }
    catch(EmptyContainerException& ex){
        std::cout<<ex.what()<<std::endl;
    }
    catch(InvalidException& ex){
        std::cout<<ex.what()<<std::endl;
    }
}