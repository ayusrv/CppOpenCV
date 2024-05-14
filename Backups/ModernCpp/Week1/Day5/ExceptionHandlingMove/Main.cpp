#include <iostream>
#include "Functionalities.h"
#include "ExceptionHandle.h"

using namespace std;

void Magic1(int && a){
    cout<<"Magic1: "<<a<<" "<<&a<<endl;
}

void Magic2(const int &a){
    cout<<"Magic2: "<<a<<" "<<&a<<endl;
}

void Magic3(int &a){
    cout<<"Magic3: "<<a<<" "<<&a<<endl;
}

void Magic4(const int&& a){
    cout<<"Magic4: "<<a<<" "<<&a<<endl;
}

void Magic5(int a){
    cout<<"Magic5: "<<a<<" "<<&a<<endl;
}

int main(){
    conatiner data;
    // CreateObject(data);
    try{
        PrintObject(data);
        DeleteObject(data);
    }
    catch(const ExceptionHandle& e){
        std::cout<<e.what()<<std::endl;
    }

    const int &ptr=10;
    std::cout<<ptr<<std::endl;
    // int a = 10;
    // cout<<a<<" "<<&a;
    // Magic1(move(a));
    // Magic2(a);
    // Magic3(a); 
    // Magic4(move(a));
    // Magic5(a);

}