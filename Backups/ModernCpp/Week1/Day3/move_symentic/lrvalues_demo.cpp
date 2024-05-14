#include<iostream>
#include<vector>

/*
    4 tokens
    int //data type
    n1 //identifier name given by the programmer
    = //assignment operator 
    10 //ravlue(integer literal)
*/

/*
    any form of data that is not preserved in 
    a fixed location in a memory will disappear
    at the end of the expression(full expression)
    where it originated
*/

/*
    once you gave name to the memory location it becomes lvalue
    int a = 10;
    here you are assigning a with 10 so a becomes lvalue
*/

//OS, DATABASES, CN, COA, Distributed Computing

int main(){
    //this is a temp value or rvalue-> somethig which doesnot have permanent storage in RAM
    10; //10; 
    "Ayush";
    std::vector<int> {1,2,3,4};

    //lvalue -> memory + nameGivenToValue
    int a= 90;
    int b;
}

/*

    Scenario 1: Design the function to accept lvalue
                and rvalue both, Allow copy of lvalue ad
                assignmnet of rvalue

        Example:
            Magic(std::vector<int> {1,2,3}); //assigned to val
        Example:
            std::vector<int> v1 {1,2,3,4,5};
            Magic(v1); //v1's 24 bytes (pointers) copy to val
            //copy constructor. We are constructing val by using v1

    Scenario 2: lvalue to be accepted by reference.
                No rvalues (temporaries, no ownership transfer)
                No copy of data. Data should become accessible in Magic
                Magic(std::vector<int>& val); //Now take vector by lvalue reference

        Example: 
            std::vector<int> v1{1,2,3,4,5};
            Magic(v1); //by refrence
            Magic(std::vector<int> {1,2,3,4,5}); //compile time exception

    Scenario 3: I only want a single copy of data.
                I only want rvalues so that user cannot create a 
                duplicate copy of data in the caller(function)
                Magic(std::vector<int> && val); //Now take vector by rvalue reference

        Example: 
            std::vector<int> v1{1,2,3,4,5};
            Magic(v1); //by refrence, complite time error
            Magic(std::vector<int> {1,2,3,4,5}); //oky
            Magic(std::move(v1)); //by refrence, okay

    Scenario 4: I want to design a funcyion where, lvalues are accepted
                by reference. I also want rvalues to be accepted by assignment
                void Magic(const std::vector<int>& val);

            Example: 
                Magic(v1); //by reference, OKAY
                Magic(std::vector<int> {1,2,3,4,5}); //OKAY!
                Magic(std::move(v1)); //by rvalue reference, OKAY

*/