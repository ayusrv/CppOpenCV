#include "mechanical.cpp"
#include "civil.cpp"
#include "computer.cpp"
#include "student.cpp"

#include<iostream>
using namespace std;

int main(){
    student *arr[3];
    for(int i=0;i<3;i++){
        int id,entranceMarks;
        string name;
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"ENter entrance marks: ";
        cin>>entranceMarks;
        student *ptr;
        if(entranceMarks >=40 && entranceMarks<60){
            ptr=new civil(id,name,entranceMarks);
        }
        else if(entranceMarks>=60 && entranceMarks<75){
            ptr = new mechanical(id, name, entranceMarks);
        }
        else{
            ptr = new computer(id,name,entranceMarks);
        }
        arr[i] = ptr;
    }
    for(int i=0;i<3;i++){
        arr[i]->getVal();
    }
    for(int i=0;i<3;i++){
        delete arr[i];
    }

//    string temp;
//    cout<<"ENter string: ";
//    char *ptr = new char[30];
//    cin>>ptr;
//    cout<<"ptr: "<<ptr;
// //    string temp =
}