#include<iostream>
using namespace std;

class m{
    protected:
    int m;
    public:
    void get_m(int);
};

class n{
    protected:
    int n;
    public:
    void get_n(int);
};

class P:public m, public n{
    public:
    void display(void);
};

void m::get_m(int x){
    m=x;
}

void n::get_n(int y){
    n=y;
}

void P::display(){
    cout<<"M-> "<<m<<endl;
    cout<<"N-> "<<n<<endl;
    cout<<"M*N-> "<<m*n<<endl;
}

int main(){
    P p;
    p.get_m(10);
    p.get_n(20);
    p.display();
    return 0;
}