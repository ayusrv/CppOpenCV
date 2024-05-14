//Page 273

#include<iostream>
using namespace std;

class BC{
    public:
    int b;
    void show(){
        cout<<"B-> "<<b<<"\n";
    }
};

class DC:public BC{
    public:
    int d;
    void show(){
        cout<<"B-> "<<b<<"\n";
        cout<<"D-> "<<d<<"\n";
    }
};

int main(){
    BC *bcptr;  //BASE POINTER
    BC base;
    bcptr=&base; //BASE ADDRESS
    bcptr->b=100; //Address BC via base pointer
    cout<<"BCPTR Points to base object \n";
    bcptr->show();
    //Derived class
    DC derived;
    bcptr = &derived;
    bcptr->b=200;

    //bcptr->d=100  won't work
    cout<<"bcptr now points to derived object \n";
    bcptr->show();  //bcptr now points to derived object

    //Accessing d using a pointer of type derived class of DC
    DC *dcptr;
    dcptr=&derived;
    dcptr->d=300;
    cout<<"DCPTR is derived type pointer\n";
    dcptr->show();
    cout<<"Using ((DC*)bcptr)\n";
    ((DC*)bcptr)->d = 400;
    ((DC*)bcptr)->show();
}