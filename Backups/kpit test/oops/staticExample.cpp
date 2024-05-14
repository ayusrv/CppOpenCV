#include<iostream>
using namespace std;
class cl{
    static int x;
    int b;
    public:
    void set(int a, int b){
        this->x=a;
        this->b=b;
    }
    void show();
};
int cl::x;
void cl::show(){
    cout<<"Value of X: "<<x<<endl;
    cout<<"Value of Y: "<<b<<endl;
}
int main(){
    cl c,d;
    c.set(1,1);
    d.set(2,2);
    c.show();
    d.show();
}
