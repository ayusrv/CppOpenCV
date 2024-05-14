#include<iostream>
using namespace std;

class b1{
    public:
    int b11=0;
    void display(){
        cout<<"Value of B1: "<<b11;
    }
};

class b2{
    public:
    int b22=0;
    void display(){
        cout<<"Value of B2: "<<b22;
    }
};

class b3:public b1, public b2{

};

int main(){
    b3 b;
    b.b1::b11=10;
    b.b2::b22=20;
    // b.display();
    b.b1::display();
    b.b2::display();
}