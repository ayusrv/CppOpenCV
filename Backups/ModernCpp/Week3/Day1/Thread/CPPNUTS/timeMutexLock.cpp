/*
    std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success otherwise false

    Mmeber Functions:
        a. Lock
        b. try_lock
        c. try_lock for   --\ These two function makes it different from mutex
        d. try_lock until --/
        e. unlock
    
    Example 
        try_lock_for(): Waits until specified timeout_duration has elapsed or the lock is aquired, whichever comes first. On successful lock aquisition returns true, otherwise returns false

        try_lock_until(): Waits until current time + specified timeout_duration has elapsed or the lock is aquired, whichever comes first. On successful lock aquisition returns true, otherwise returns false
*/

#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

std::timed_mutex m;
int myAmount=0;

void incrementFor(int i)
{
    if(m.try_lock_for(std::chrono::seconds(1)))
    {   
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<< i <<" thread got initialized "<<std::endl;
        m.unlock();
    }
    else{
        std::cout<<i <<" thread didn't initialized "<<std::endl;
    }
}

void incrementUntil(int i)
{
    auto now = std::chrono::steady_clock::now();
    if(m.try_lock_until(now + std::chrono::seconds(1)))
    {   
        ++myAmount;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<< i <<" thread got initialized "<<std::endl;
        m.unlock();
    }
    else{
        std::cout<<i <<" thread didn't initialized "<<std::endl;
    }
}

int main(){
    std::thread t1(incrementFor,1);
    std::thread t2(incrementFor, 2);
    t1.join();
    t2.join();
    std::thread t3(incrementUntil,3);
    std::thread t4(incrementUntil, 4);
    t3.join();
    t4.join();
    std::cout<<"Total threads got entered: "<<myAmount<<std::endl;
    return 0;
}