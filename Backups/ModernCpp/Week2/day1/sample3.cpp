#include <iostream>
#include <functional> //Support fro functional programming!


void square(int number){
    std::cout<<"Square of number is: "<<number*number<<"\n";
}

void cube(int number){
    std::cout<<"cube of number is: "<<number*number*number<<"\n";
}

//Higher order function 
// a higher order function either accepts or return  (or both) another function
void Operation(const std::vector<int>&data, std::function<void(int)> fn){
    for(int val : data){
        fn(val);
    }
}

int main(){
    //fn pointer
    // void square(int);
    // void (*ptr)(int) = square; //Function pointer

    //void cuber(int);
    // void (*ptr2)(int) = cube; //Function pointer

    std::vector<int> arr {10,20,30,40,50};
    Operation(arr, square);
    Operation(std::vector<int> {10,20,30,40,50}, cube);
}

/*
    Higher order functions!
    Anonymous function 
    functional progra,,ing paradigm
    immutable data
    currying
    First-class functions

*/