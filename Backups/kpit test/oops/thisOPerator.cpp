#include<iostream>
using namespace std;
class thiskey{
    int x;
    int y;
    public:
    void setx(int a){
        this->x=a;
        cout<<"\nAddress of X is: "<<this;
    }
    void sety(int b){
        this->y=b;
        cout<<"\nAddress of Y is: "<<this;
    }

    ~thiskey(){
        cout<<"\nDestructor has been called";
    }
};

int main(){
    // thiskey ts;
    // ts.setx(10);
    // ts.sety(20);
    // thiskey* ts2 = new thiskey;
    // ts2->setx(10);
    // ts2->sety(20);

    // delete ts2;
    // thiskey ts1;
    // ts1.setx(10);

    int arr[5]={1,2,3,4,5};
    char ch[5]="HELL";
    cout<<*arr<<endl;
    cout<<&ch<<endl;
}