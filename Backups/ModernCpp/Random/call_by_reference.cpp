/*
    int &a : reference
    &a : no data type to the left oa a : address(pointer)
*/
#include <iostream>

void Magic(int &data){
    std::cout<<"data in Magic before modification is: "<<data <<"\n";
    std::cout<<"Address of data inside Magic is : "<<&data<<"\n";
    data = 111;
    std::cout<<"data in Magic after modification is: "<<data <<"\n";
}

void Magic(int *data){
    std::cout<<"Derefrencing data gives b4 modification: "<<*data<<"\n";
    std::cout<<"data in Magic before modification is: "<<data <<"\n";
    std::cout<<"Address of data inside Magic is : "<<&data<<"\n";
    *data = 222;
    std::cout<<"data in Magic after modification is: "<<data <<"\n";
    std::cout<<"Derefrencing data gives b4 modification: "<<*data<<"\n";
}


int main(){

    int value = 100;
    std::cout<<"Value in Magic before modification is: "<<value <<"\n";
    std::cout<<"Address of value inside Main is : "<<&value<<"\n";
    Magic(value);
    std::cout<<"Value in Magic after modification is: "<<value <<"\n";

    std::cout<<"\n\n\n";
    std::cout<<"Value in Magic before modification is: "<<value <<"\n";
    std::cout<<"Address of value inside Main is : "<<&value<<"\n";
    Magic(&value);
    std::cout<<"Value in Magic after modification is: "<<value <<"\n";
}