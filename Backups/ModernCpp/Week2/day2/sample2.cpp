/*
    Objective : Create an adapeter which takes a 
    1) callable of the following signature
        Input: int and int
        Output void
    2) integer number n1
    3) INteger number n2

    the adapter must apply/map the callable on the 2) and 3) integers


    Adapter is a higher order funcion that accepts
        a) a function wrapper for all funcions that have the following signature
        i) int, int input parameters
        ii) void as return type
*/

#include <iostream>
#include <functional>

void addition(std::function<void (int,int)> fun, int n1, int n2){
    fun(n1,n2);
}

void f1(int n1, int n2) {std::cout<<n1+n2<<std::endl;}

int multiplication(std::function<int (int,int)> fun, int n1, int n2){
    return fun(n1,n2);
}

int f2(int n1, int n2) {return n1*n2;}

int main(){
    addition(
        [](int n1, int n2){std::cout<<n1+n2<<std::endl;}, 
        10,
        10
    );
    addition(
        f1,
        10,
        10
    );
    int val;
    val = multiplication(
        [](int n1, int n2){return n1*n2;},10,10
    );
    std::cout<<val<<std::endl;
    std::cout<<
    multiplication(
        f2,
        10,
        10
    );
    std::cout<<std::endl;

}