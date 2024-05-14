//page 276

#include<iostream>
using namespace std;

class base{
    public:
    void display(){
        cout<<"Base Display\n";
    }
    virtual void show(){
        cout<<"Base Show\n";
    }
};

class derived:public base{
    public:
    void display(){
        cout<<"Derived Display\n";
    }
    void show(){
        cout<<"Derived Show\n";
    }
};

int main(){
    base b;
    derived d;
    base *bptr;
    bptr = &b;
    bptr->display();    //Calls base version
    bptr->show();   //Calls base version
    bptr=&d;
    bptr->display();    //Calls base version
    bptr->show();   //Calls derived version
    return 0;
}