/*  
    Objective:
    Design a consumer for: 
        - MAKING ALLOCATIONS ON THE heap for 10 integers.
        - Save square of first 10 integers on the head storage created.
        - calculating sum of first N natural numbers, where N is accepted asynchronously in the function and return the value

    Producer thread for: 
        - launching a consumer acceptiong N and passing to consumer
*/

#include <future>
#include <iostream>
#include <vector>
#include <functional>

int Consumer(std::future<int>& ft){
    int *ptr = (int*) malloc(4);
    auto f1 = [](int number){return number*number;};
    for(int i=1;i<=10;i++){
        ptr[i-1] = f1(i);
    }
    for(int i=1;i<=10;i++){
        std::cout<<ptr[i-1]<<" ";
    }
    int n = ft.get();
    auto f2 = [](int n){return (n*(n+1)/2);};
    return f2(n);
}

std::function<std::vector<int>(std::future<std::vector<int>>&)> Consumer2 = [](std::future<std::vector<int>>& ft){
    std::vector<int> vec;
    
    return vec;
};

int main()
{
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    std::future<int> result = std::async(&Consumer, std::ref(ft));
    int num = 0;
    std::cout<<"ENter the number: ";
    std::cin>>num;
    pr.set_value(num);
    std::cout<<"\nThe answer is: "<<result.get()<<"\n"; //.GET() -> Wait + result so result.wait nahi lagana agar .get kiye to
    // ek future k liye ek hi baar get aayeaga ek or baar lagayoge to error aa jayeaga
}