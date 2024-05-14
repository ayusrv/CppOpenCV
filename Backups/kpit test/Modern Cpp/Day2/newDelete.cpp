#include<bits/stdc++.h>
using namespace std;
class base{
    public: 
        base(){
            cout<<"constructor"<<endl;
        }
        void geet(){
            cout<<"GETT";
        }
        ~base(){
            cout<<"Destructor"<<endl;
        }
};

int main(){
    base *b = new base[10];

    base *c = b;
    delete[] b;
    // c=b;
    cout<<c<<endl;
    c->geet();
}