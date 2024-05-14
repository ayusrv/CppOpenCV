#include <iostream>
#include <functional>

void sum(int a, int b){
    std::cout<<a+b<<std::endl;
}

void dif(int a, int b){
    std::cout<<a-b<<std::endl;
}

void operations(std::function<void(int, int)> fn, int a, int b){
    fn(a,b);
}

int main(){
    auto bind_sum = std::bind(&sum, 100, std::placeholders::_2);
    bind_sum(10,10,10);
    operations(bind_sum,30,50);
    operations(dif,30,50);
}