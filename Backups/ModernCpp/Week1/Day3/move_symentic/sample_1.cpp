#include <iostream>
#include <vector>

/*
    numbers passed to magic must always be temoprary values or move values.
    capture parameter by R value
*/
void Magic(std::vector<int>&& data){
}

int main(){
    std::vector<int> value {10,20,30,40,50};
    Magic(std::move(value));
    // std::cout<<value.size()<<" "<<value[0];    //Ye chal jayeaga but glti se v nahi krna undefined behaviour dega
    //It is like going back to your ex
}



/*

    We create vector in main (scope in main)
    HEAP
    [10,20,30,40,50 |  |  |  |   ]
    ^             ^             ^
    |             |             |
    |             |             |
    |             |             |
    [ 0X100       |0X116        |0X132]
    START       SIZE           CAPACITY
    <------------MAIN------------>
    <---------24 BYTES----------->

*/

/*

    1) Progam starts because OS schedules the process
    2) Main function is executed as a thread by the OS
    3) Vector of Integers value is created in the scope of main
        a) Create heap alllocatoion happens and vector gets space on head
        b) Pointers to start, end and capacity are recorded in the vector objects "value" in main
    4) Magic(std::move(value))
        a) std::move(value) : It converts lvalue into rvalue
            (tells the compiler "value" vector can be prepared for move)
        b) Now vector value is treated as an rvalue so Magic(std::move(value)) becomes equal to
            Magic(std::vector<int> {10,20,30,40,50})  ----->bina naam wala value ko ravlue bolte hai

*/