#include<iostream>
using namespace std;

void fun(int x){
    try{
        if(x==-1){
            throw x;
        }else if(x==0){
            throw 'x';
        }else if(x==1){
            throw 1.0;
        }
        cout<<"End of try block\n";
    }
    catch(char c){
        cout<<"Character Thrown\n";
    }
    catch(int c){
        cout<<"Caught an Integer\n";
    }
    catch(double d){
        cout<<"Caught an double\n";
    }
    cout<<"End of try catch block\n";
}

int main(){
    int x;
    cin>>x;
    fun(x);
    cout<<"End of main function\n";
}