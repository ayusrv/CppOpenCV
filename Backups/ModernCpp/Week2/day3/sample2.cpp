#include <iostream>
#include <functional>

class Action
{
private:
    int _id {10};
public:
    Action() = default;
    ~Action() = default;
    void Operation(int number){std::cout<<_id*number;}

};

int main(){
    Action a;
    auto binded_operation = std::bind(&Action::Operation, &a, 40); //& lagana important hai 
    //NOn static member function k aage & lagana mandatory hota hai 

    binded_operation(); //a.operation(40);

    

}

/*
    SWAP PARAMETERS
    FIXING PARAMETERS
    DISGARDING PARAMETER
    BINDING LAMBDA
    BIND FUNCTION, MEMEBER FUNCTION
*/