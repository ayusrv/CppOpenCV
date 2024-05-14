#include<iostream>
using namespace std;
class mini{
    int a;
    int b;
    public:
    mini(){
        a=10;
        b=10;
    }
    void sset(int a, int b){
        cout<<"Pord is: "<<a*b;
    }
};
int main(){
    mini m;
    m.sset(20,20);
}