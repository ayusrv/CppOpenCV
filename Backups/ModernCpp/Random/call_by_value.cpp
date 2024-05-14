#include <iostream>

/*
    int &a : reference
    &a : no data type to the left oa a : address(pointer)
*/

void Magic(int value){
    std::cout<<"Value in Magic before modification is: "<<value <<"\n";
    std::cout<<"Address of value inside Magic is : "<<&value<<"\n";
    value = 111;
    std::cout<<"Value in Magic after modification is: "<<value <<"\n";
}

int main(){
    int value = 100;
    std::cout<<"Value in Magic before modification is: "<<value <<"\n";
    std::cout<<"Address of value inside Main is : "<<&value<<"\n";
    Magic(value);
    std::cout<<"Value in Magic after modification is: "<<value <<"\n";
}