#include<iostream>
using namespace std;

class shop{
    int id;
    float price;
    public:
        void setData(int a, float b){
            id=a;
            price=b;
        }
        void getData(void){
            cout<<"ID is: "<<id<<endl;
            cout<<"Price is: "<<price<<endl;
        }
};

int main(){
    int size=3;
    shop *ptr = new shop[size];
    shop *ptrTemp = ptr;
    int p;
    float q;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the price and Item of "<<i+1<<" ";
        cin>>p>>q;
        ptr->setData(p,q);
        ptr++;
    }
    for (int i = 0; i < size; i++)
    {   
        ptrTemp->getData();
        ptrTemp++;
    }
}