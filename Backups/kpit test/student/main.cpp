#include "enrollment.cpp"
#include "student.cpp"
#include "course.cpp"

#include<bits/stdc++.h>
using namespace std;

class enrollmentExcp : public exception{
    public:
        const char* what(){
            return "No Course Code found!!!";
        }
};

int main(){
    int size=1;
    enrollment *e[size];
    for(int i=0;i<size;i++){
        enrollment *ptr = new enrollment;
        ptr->accept();
        e[i] = ptr;
    }
    for(int i=0;i<size;i++){
        cout<<*e[i];
    }
    string searchCourseCode;
    cout<<"Enter course code to search: ";
    cin>>searchCourseCode;
    int flag = -1;
    for(int i=0;i<size;i++){
        if(e[i]->c.getCourseCode()==searchCourseCode){
            flag=i;
        }
    }
    try{
        if(flag==-1){
            enrollmentExcp ee;
            throw ee;
        }
        cout<<*e[flag];
    }
    catch(enrollmentExcp ee){
        cout<<ee.what();
    }
}