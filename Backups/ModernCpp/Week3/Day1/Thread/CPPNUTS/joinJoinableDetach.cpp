#include<iostream>
#include <thread>

void fun(int num){
    while(num-->0){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<"Join ends"<<std::endl;
}

void fun2(int num){

    while(num-->0){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<"Detach ends"<<std::endl;
}

int main(){
    std::cout<<"Join starts"<<std::endl;
    std::thread t1(fun,5);
    t1.join();
    if(t1.joinable()) // Checking if the thread is joinable or not, if it is already joined it will give any error and this will not join the thread again
        t1.join();


    std::cout<<"Detach starts"<<std::endl;
    std::thread t2(fun2,5);
    t2.detach(); //This will not wait for the finish of the t2 thread in main. This will call detach the t2 thread from the main and then both the thread will become independent this is not printing the detach finished
    return 0;
}