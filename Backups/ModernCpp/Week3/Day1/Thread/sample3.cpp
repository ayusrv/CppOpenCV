/*
    withdraw : withdraw takes 10 units of money from amount.
    deposit : adds 10 usints of the money from amount

    Run withdraw and deposit both for 100 times each on an initial amount 1000
    what will be the final amount after 200 transactions are completed?

*/

#include <iostream>
#include <thread>
#include <mutex>
std::mutex mx;

int amount=1000;

void withdraw(){
    for(int i=0; i<100 ;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        mx.lock();
        amount -=10;
        mx.unlock();
    }
}

void deposit(){
    for(int i=0; i<100 ;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        mx.lock();
        amount +=10;
        mx.unlock();        
    }
}

int main(){
    std::thread t1(&withdraw);
    std::thread t2(&deposit);
    t1.join();
    t2.join();

    std::cout<<"Final amount is: "<<amount<<std::endl;
}


//This will print the diffrent answers whenever we run this to make this correct use mutext lock to get the correct answer

/*
    How to run for  loop on terminal
    for((int i=0;i<50;i++)); do ./app; done
*/