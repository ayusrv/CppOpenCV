#include<iostream>
using namespace std;

class base{
    public:
    virtual void show(){
        cout<<"THis is a base class\n";
    }
};

class derived1:public base{
    public:
    void show(){
        cout<<"This is derived 1\n";
    }
};

class derived2:public base{
    public:
    void show(){
        cout<<"This is a derived 2\n";
    }
};

int main(){
    base *p,b;
    p=&b;
    p->show();
    derived1 d1;
    derived2 d2,*d;
    p=&d1;
    p->show();
    p=&d2;
    p->show();
    // d=&d2;
    // d->show();
}