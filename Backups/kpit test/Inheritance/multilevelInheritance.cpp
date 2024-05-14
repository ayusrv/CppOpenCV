#include<iostream>
using namespace std;

class emp{
    protected:
    int totalEmp;
    public:
    void sete(int emp){
        totalEmp=emp;
    }
    void display(){
        cout<<"Total Employee: "<<totalEmp<<" ";
    }
};

class derived1: public emp{
    private:
    int k;
    public:
    void setk(int a){
        emp::sete(a);
        this->k=emp::totalEmp*10;
    }
    void display(){
        emp::display();
        cout<<"K -> "<<k<<" ";
    }
};

class derived2: public derived1{
    private:
    int s;
    public:
    derived2():derived1(){}
    void setval(int a){
        derived1::setk(a);
        this->s=emp::totalEmp/10;
    }
    void display(){
        derived1::display();
        cout<<"S -> "<<s<<endl;
    }
};

int main(){
    derived2 obj;
    obj.setval(10);
    obj.display();

    return 0;
}