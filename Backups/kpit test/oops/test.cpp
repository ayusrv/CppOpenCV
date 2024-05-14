#include<bits/stdc++.h>
using namespace std;

class account{
    static int i;
    string name="BA";
    public:
    void setname(){
        name.append(to_string(i));
        i++;
    }
    string getname(){
        return name;
    }
};

int account::i=1000;

int main(){
    account a[3];
    for(int j=0;j<3;j++){
        a[j].setname();
    }
    for(int j=0;j<3;j++){
        cout<<a[j].getname()<<" ";
    }
    return 0;
}