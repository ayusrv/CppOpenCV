#include<iostream>
using namespace std;
class andop{
    int a;
    int b;
    public:
    andop(){}
    andop(int a, int b){
        this->a=a;
        this->b=b;
    }
    friend void operator&(andop &an);
    void display();
};

void operator&(andop &an){
    an.a=an.a&1;
    an.b=an.b&1;
}

void andop::display(){
    cout<<"A-> "<<a<<" B-> "<<b<<endl;
}

int main(){
    andop a(10,10);
    a.display();
    operator&(a);
    a.display();
}