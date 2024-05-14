#include<bits/stdc++.h>
using namespace std;

class Base{
    public:
        Base(){
            cout<<"Base Called"<<endl;
        }
};

class Parent1 :public Base{
    public:
        Parent1(){
            cout<<"Parent 1"<<endl;
        }
};

class Parent2 :public Base{
    public:
        Parent2(){
            cout<<"Parent2"<<endl;
        }
};

class Child :public Parent1, public Parent2{
    public:
        Child(){
            cout<<"Child Called"<<endl;
        }
};

int main(){
    Child c;
}