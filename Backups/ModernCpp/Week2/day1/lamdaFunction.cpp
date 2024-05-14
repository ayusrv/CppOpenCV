#include <iostream>
#include <functional> //Support fro functional programming!

void cube(int number){
    std::cout<<"cube of number is: "<<number*number*number<<"\n";
}

//Higher order function 
// a higher order function either accepts or return  (or both) another function
void Operation(const std::vector<int>&data,std::function<void(int)> fn){
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

    Operation(arr, 
    //lamda concept [] ye syntax hai lambda function banne ka
    //[] -> capture clause, use to create lambda closure
    //Temporary function hai rvalue k tarah ekbaar kaam khatm ye gayab 
    //ye abhi rvalue hai 
        [](int number) -> void{
            std::cout<<"Square of : "
                <<number <<" is: "<<number*number<<"\n";
        }
    );

    // same hai dono bs aab ye lvalue ho gya hai
    //Not efficieny
    auto f1 = [](int number) -> void{
            std::cout<<"Cube of : "
                <<number <<" is: "<<number*number*number<<"\n";
        };
    Operation(std::vector<int> {10,20,30,40,50}, f1);
}

/*
    Lamda function -> sometime the logic I want t execute is one time so its just use and throw
                   -> Limit the scope of the function
                   -> Sometime very samll body of the function

*/