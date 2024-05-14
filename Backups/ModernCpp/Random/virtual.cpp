#include<iostream>

class A{
    int a;
    public:
    A(){std::cout<<"A's C\n";}
    void display(){
        std::cout<<"Display in A\n";
    }
    ~A(){std::cout<<"A's D\n";}
};

class B : public A{
    int b;
    public:
    B(){std::cout<<"B's C\n";}
    void display(){
        std::cout<<"Display in B\n"; 
    }
    ~B(){
        std::cout<<"B's D\n";
    }
};

int main(){
    B obj;
    obj.display();

}