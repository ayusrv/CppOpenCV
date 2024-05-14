#include <iostream>
#include <functional>
/*
Actual data type of a lambda is unknown
*/

void Magic(std::function<void (int)> fn){
    fn(10); //This will call the lambda function inside the wrapper
}

int main(){
    auto f1 = [](int number){std::cout<<number*10<<std::endl; };
    f1(10); //Like a function, overloaded() operator
    Magic(
        [](int number){std::cout<<number*10<<std::endl; }
        );

}