//create a shape class as abstract with one pure virtual function area
//create 2 class called square and rectangle and override the area function in those derived classes 
//and display the area take radius as data member

#include<iostream>
using namespace std;

class shape
{
public:
    virtual float area()=0;
};

class square{
    private:
    float side;
    public:

    square(int s):side(s){}
    float area(){
        return side*side;
    }
};

class rectangle{
    private:
    float length, breadth;
    public:
    rectangle(int l, int b):length(l),breadth(b){}
    float area(){
        return length*breadth;
    }
};

int main(){
    square sq(10.0);
    rectangle rec(12.0,12.0);

    cout<<"Area of square: "<<sq.area()<<endl;
    cout<<"Area of rectangle: "<<rec.area()<<endl;
}