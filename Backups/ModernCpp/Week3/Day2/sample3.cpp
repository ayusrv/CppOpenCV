/*
    Producer Consumer problem!

    2 workers in your program
        one of them may produce something the other will "consume it" {process the produced data}
*/

/*
    Two threads(workers) 
        - main thread (producer) -> take input and make value available
        - operation (thread t1 consumer) : once a signal is recieved from main to indicate input recieved calculate the square
            a) Programmer calculates how may workers are required and triggers tham at a time [thread pooling!]

            b) T 1may want to do some other work even before data input in recieved
*/

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex mt;
std::condition_variable cv;
bool flag = false;
int amount = 0;

void OperationThread(){
    int* ans = (int*) malloc(4);
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul, [&](){return flag;}); //if false release mutex immediately
    *ans = amount*amount;
    std::cout<<"Square of value: "<< amount << " is: " <<*ans<<std::endl;
    free(ans);
}

void TakeInput(){
    //apply lock on mutex. LOck will applied till end of main
    std::lock_guard<std::mutex> lg(mt);
    std::cin>>amount;
}

int main(){

    //step 1: thread initializwd a new thread is now available to be scheduled.
    std::thread t1(&OperationThread);
    
    TakeInput();
    //toggle flag to indicate production is ready
    flag = true;
    //send a signal
    cv.notify_one();
    //wait for operation before terminating the program
    t1.join();
}