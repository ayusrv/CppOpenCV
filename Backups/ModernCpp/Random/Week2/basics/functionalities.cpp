#include <iostream>
#include <memory>
#include <functional>
#include "functionalities.h"

void CreateObject(Container &data)
{
    data.push_back([](DataConatiner &v)
                   {int sum =0;for (int i:v){
        sum+=i;
    }return sum; });

    data.push_back([](DataConatiner &v)
                   {int mul=1;for (int i:v){
        mul*=i;
    }return mul; });

    data.push_back([](DataConatiner &v)
                   {int div =0;for (int i:v){
        div/=i;
    }return div; });

    data.push_back([](DataConatiner &v)
                   {int sub =0;for (int i:v){
        sub-=i;
    }return sub; });
}

void PrintObject(Container &data, DataConatiner &data2)
{
    for(FType f : data){
        std::cout<<f(data2)<<std::endl;
    }
}

void CreateObjects2(std::vector<Standardize> fun,DataConatiner &v)
{
    for(Standardize f : fun){
        f(v);
    }
}

void sum1(int a, int b){
    std::cout<<"A: "<<a<<" + "<<" B: "<<b<<" = "<<a+b<<std::endl;
}

void sum(DataConatiner &v){
    int s=0;
    for(int i : v){
        s+=i;
    }
    std::cout<<"Sum is: "<<s<<std::endl;
}

void sub(DataConatiner &v){
    int s=0;
    for(int i : v){
        s-=i;
    }
    std::cout<<"Difference is: "<<s<<std::endl;
}

void mul(DataConatiner &v){
    int s=1;
    for(int i : v){
        s*=i;
    }
    std::cout<<"Multiplication is: "<<s<<std::endl;
}