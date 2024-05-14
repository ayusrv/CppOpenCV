#include<iostream>
using namespace std;
const int size=3;
class vector{
    int v[size];
    public:
    vector(); //Construct null vector
    vector(int *x); //Construct vector from array
    friend vector operator *(int a, vector b); 
    friend vector operator *(vector b, int a); 
    void display();
};

vector::vector(){
    for(int i=0;i<size;i++){
        v[i]=0;
    }
}

vector::display(){
    for(int i=0;i<size;i++){
        cout<<v[i]<<" ";
    }
}

vector::vector(int *x){
    for(int i=0;i<size;i++){
        v[i]=x[i];
    }
}

vector operator*(int a, vector b){
    vector c;
    for(int i=0;i<size;i++){
        c.v[i]=a*b[i];
    }
    return c;
}

vector operator*(vector b, int a){
    vector c;
    for(int i=0;i<size;i++){
        c.v[i]=a*b[i];
    }
    return c;
}

int main(){
    int arr[5]={1,2,3,4,5};
    vector v(arr);
    vector v1 = v*5;
    v1.display();
}