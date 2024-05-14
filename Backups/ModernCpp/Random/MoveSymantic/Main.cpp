#include "ClassA.h"
#include<iostream>
using namespace std;


int main(){

    // ClassA a2(2,"Himanshu");
    char* c=new char[10];
    strcpy(c,"aa");

    ClassA a1(ClassA(1,"Ayush",c));

    cout<<a1.id()<<a1.name()<<a1.msg()<<endl;
}
