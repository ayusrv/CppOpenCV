#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <condition_variable>

//Promise for setting the value in producer thread and future for getting the value in consumer

std::mutex mt;
std::condition_variable cv;
bool flag = false;
long end;

void findOdd(std::promise<long>&& oddSum, long start, long end){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    long odd = 0;
    for(int i = start ;i<=end;i++)
    {
        if(i%2!=0) odd+=i;
    }
    oddSum.set_value(odd);
}

void findEven(long start){
     long evenSUm=0;
     std::unique_lock<std::mutex> ul(mt);
     cv.wait(ul, [&](){return flag;});
     for(int i=start;i<=end;i++){
        if(i%2==0) evenSUm+=i;
     }
     std::cout<<"Even sum: "<<evenSUm<<std::endl;

}

void takeInput(){
    std::lock_guard<std::mutex> lg(mt);
    std::cout<<"ENter the input: ";
    std::cin>>end;
}   

int main(){
    long start = 0;
    long ed = 12;
    std::promise<long> oddSum;
    std::future<long> oddS = oddSum.get_future();
    std::thread t1(&findOdd, std::move(oddSum), start, ed);
    std::cout<<"Waiting for the result"<<std::endl;
    std::cout<<"ODD SUM: "<<oddS.get()<<std::endl;
    t1.join();
    std::thread t2(&findEven, 0);
    takeInput();
    flag = true;
    cv.notify_one();
    std::cout<<"Main ends"<<std::endl;
    t2.join();
    return 0;
}