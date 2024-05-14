#include<iostream>
using namespace std;
class static_demo{
    private:
    static int a;
    int b;
    public:
    void set(int i, int j){
        this->a=i;
        this->b=j;
    }
    void show();
};
int static_demo::a;
void static_demo::show(){
    cout<<"This is static A: "<<a<<"\n";
    cout<<"This is non static B: "<<b<<"\n";
}
int main(){
    static_demo st,x;
    st.set(1,1);
    x.set(2,2);
    st.show();
    x.show();
}