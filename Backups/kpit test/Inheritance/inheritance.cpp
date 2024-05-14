#include<iostream>
using namespace std;

class basec{
    int x;
    int y;
    public:
    basec(int x, int y):x(x),y(y){}
    void setval(int x, int y){
        this->x=x;
        this->y=y;
    }
    void display(){
        cout<<"X-> "<<x<<", Y-> "<<y;
    }
};

class derivedc:public basec{
    int a;
    public:
    derivedc(int a):basec(10,20),a(a){}
    void display(){
        basec::display(); //to call the display function of base class
        cout<<", A-> "<<a;
    }
};

class derivedPrivate:private basec{
    int a;
    public:
    derivedPrivate(int a):basec(10,20),a(a){}
    void display(){
        basec::display(); //to call the display function of base class
        cout<<", A-> "<<a<<endl;
    }
};

class emp{
    int x;
    int y;
    protected:
    emp(int x, int y):x(x),y(y){}
    void display(){
        cout<<"X -> "<<x<<" Y ->"<<y;
    }
};

class comp: public emp{
    int a;
    protected:
    comp(int a):emp(10,20),a(a){}
    void display(){
        emp::display();
        cout<<" A -> "<<a<<endl;
    }
};

int main(){
    derivedc obj(23);
    derivedPrivate obj2(23);
    obj.setval(10,20);
    obj.display();
    cout<<"\n";
    // obj2.setval(20,30); //This cann be accessed because the derived class made the public member of the base class as a private member
    obj2.display();

    comp c(20);
    c.display();
}