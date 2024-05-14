#include<iostream>
using namespace std;
class sample{
    int a;
    int b;
    public:
    friend float mean(sample s);
    void setVal(int a, int b){
        this->a=a;
        this->b=b;
    }
};

class ABC;
class XYZ{
    int x;
    public:
    void seta(int a){this->x=a;}
    friend void max(XYZ,ABC);
};

class ABC{
    int a;
    public:
    void seta(int a){this->a=a;}
    friend void max(XYZ,ABC);
};

void max(XYZ x, ABC a){
    int maxVal = 0;
    if(x.x>a.a) {
        maxVal=x.x;
        cout<<"The max value is X\n";
    }
    else maxVal = a.a;
    cout<<"The maximum is: "<<maxVal;
}


float mean(sample s){
    return (s.a+s.b)/2.0;
}

int main(){
    sample s;
    s.setVal(10,20);
    cout<<mean(s);

    ABC a;
    a.seta(10);
    XYZ x;
    x.seta(20);
    max(x,a);
}