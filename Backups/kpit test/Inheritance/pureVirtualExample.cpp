#include<iostream>
using namespace std;

class emp{
    public:
    virtual float incometax()=0;
};

class engineer:public emp{
    public:
    int empno,sal;
    engineer(int empno, int sal):empno(empno),sal(sal){}
    float incometax() override{
        return (sal*10)/100.0;
    }
};

class manager:public emp{
    public:
    int empno, sal;
    manager(int empno, int sal):empno(empno),sal(sal){}
    float incometax() override{
        return (sal*15)/100.0;
    }
};

class accountant:public emp{
    public:
    int empno,sal;
    accountant(int empno, int sal):empno(empno),sal(sal){}
    float incometax() override{
        return (sal*5)/100.0;
    }
};

int main(){
    emp *em;
    engineer eng(1,30000);
    em=&eng;
    cout<<em->incometax()<<endl;
    manager mn(2,40000);
    em=&mn;
    cout<<em->incometax()<<endl;
    accountant ac(3,35000);
    em=&ac;
    cout<<em->incometax()<<endl;
}