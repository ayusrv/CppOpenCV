#include<iostream>
using namespace std;
class neg{
    int a,b;
    public:
    neg(){}
    neg(int a, int b){
        this->a=a;
        this->b=b;
    }
    void display();
    void operator-(neg &n);
};

void neg::operator-(neg &n){
    n.a=n.a+10;
    n.b=n.b+15;
}

void neg::display(){
    cout<<"A -> "<<a<<" B -> "<<b<<endl;
}
int main(){
    neg n(20,30);
    n.display();
    n.operator-(n);
    n.display();

}