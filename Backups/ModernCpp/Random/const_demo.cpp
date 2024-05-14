/*
    const keyword
    Rule 1: const is applied  to the token on its immediate left.
    If there is nothing to the left od const, apply const on the token to its immediate right

    Rule 2: pointer symbol * is considered a separate token
*/

class dummy{
    private: 
        int _id;
        float _salary;
    public:
        dummy(int id, float salary): _id(id), _salary(salary){}
        ~dummy()=default;
};

#include<iostream>
int main(){
    //scenario 1: const with non-pointer primitive variable
    const int n1 = 10; //n1 is a constatnt int
    int const n2 = 20; //n2 is a constant int

    int n3 = 99;
    int n4 = 188;
    //scenatio 2: pointer with primitive
    //2a
    const int* ptr = &n3; //ptr is a pointer to a const int telling rhe compiler to assime that the n3 is a const. Here n3 can change but the pointer cannot change 
    // *ptr1 = 100;   //This is not okay
    ptr = &n4; //THIS IS OKAY

    //2b
    int* const ptr2 = &n3; //ptr2 in an const pointer to an integer
    *ptr2 = 100; //This is okay
    // ptr2 = &n4; This is not okay

    //2c
    const int* const ptr3 = &n3; //ptr3 is a const pointer to a const ineteger
    // *ptr3 = 18; NOt okay
    // ptr 3 = &n4 //NOt okay

    //Scenario 3: COnst on a stack object
    const dummy d1(10,67000.0f); //Whatever data you have provided this will not change the data of the object

    //We use const on getter because it tells that it is safe and can be called

    //ONly the funtion that is marked const can be called by the constant object
}
