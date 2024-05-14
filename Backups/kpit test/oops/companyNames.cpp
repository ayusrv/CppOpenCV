// Create a list of 3 Employees with details of EMPIID, Company Name Fields. 
//If the company name of first 2 employee are equal then the third company name should be KPIT other wise 
//concatenate the company names of first 2 employee and display the id and company name of third employee
#include<bits/stdc++.h>
using namespace std;
class employee{
    string name;
    int id;
    public:
    void setName(string name){
        this->name=name;
    }
    void setId(int id){
        this->id=id;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
};

int main(){
    employee e[3];
    for(int i=0;i<2;i++){
        int id;
        cout<<"Enter the id: ";
        cin>>id;
        cout<<"Enter the name: ";
        string name;
        cin>>name;
        e[i].setName(name);
        e[i].setId(id);
    }
    if(e[0].getName().compare(e[1].getName())==0){
        e[2].setName("KPIT");
    }else{
        e[2].setName(e[1].getName().append(e[0].getName()));
    }
    e[2].setId(2);
    cout<<"Name of 3rd company is: "<<e[2].getName();
    cout<<"\nId of 3rd company is: "<<e[2].getId();
}
//write a code for add two numbers in cpp