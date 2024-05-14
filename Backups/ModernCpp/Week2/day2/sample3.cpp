/*
    Objective: Design an adaptor to accept
    a vector of integers
    a predicate(a function that return true or false based on a single input)
    use the predicate {takes one arguments and return true or false} to print data from vector

*/

//std::vector<int> {10,12,13,15,14} 
//find odd in first case
//find even
//divisible by 3
//divisible by 7
//divisible by 6
//divisible by 5
//prime numbers

#include <iostream>
#include <vector>
#include <functional>
void Adaptor(std::function<bool(int)> predicate,const std::vector<int>&data){
    for(int val : data){
        if(predicate(val)) {std::cout<<val<<std::endl;}
    }
}

int main(){
    Adaptor(
        [](int number){return number%5==0;},
        std::vector<int> {10,20,30}
    );
    Adaptor(
        [](int number){return number%5==0 && number%3==0;},
        std::vector<int> {10,20,30}
    );
}