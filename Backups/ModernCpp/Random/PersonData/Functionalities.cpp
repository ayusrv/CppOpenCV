#include "Functionalities.h"
#include "School.h"
#include "College.h"
void CreateObject(Container &data)
{
    int size = 0;
    std::cout<<"ENter the size ";
    std::cin>>size;
    for(int i=0;i<size;i++){
        std::cout<<"Enter Person Details: "<<std::endl;
        std::string name1;
        std::cout<<"Enter Name: ";
        std::cin>>name1;
        int age;
        std::cout<<"Enter ypur gender: "<<std::endl;
        char gender;
        std::cin>>gender;
        std::cout<<"Enter Age: "<<std::endl;
        std::cin>>age;
        long aadhar;
        std::cout<<"Enter aadhar number: "<<std::endl;
        std::cin>>aadhar;
        std::cout<<"Enter 1 for School and 2 for College ";
        int choice;
        std::cin>>choice;
        if(choice==1){
            std::cout<<"Enter details of School: "<<std::endl;
            std::cout<<"Enter School name: "<<std::endl;
            std::string school_name;
            std::cin>>school_name;
            std::cout<<"Enter Your Roll: "<<std::endl;
            int roll;
            std::cin>>roll;
            std::cout<<"Enter 10th marks: "<<std::endl;
            float tenth_marks, twelth_marks;
            std::cin>>tenth_marks;
            std::cout<<"Enter Twelth Makrs: "<<std::endl;
            std::cin>>twelth_marks;
            data.push_back(new School(school_name, roll, tenth_marks, twelth_marks));
        }else{
            std::cout<<"Enter Details of Your College: "<<std::endl;
            std::string college_name, branch, uid;
            int year;
            std::cout<<"ENter your college Name: "<<std::endl;
            std::cin>>college_name;
            std::cout<<"Enter your branch: "<<std::endl;
            std::cin>>branch;
            std::cout<<"Enter your year: ";
            std::cin>>year;
            std::cout<<"Enter your UID: "<<std::endl;
            std::cin>>uid;
            data.push_back(new College(college_name, branch, year, uid));
        }
    }
}

void printData(Container &data){
    for(Person* p : data){
        if(typeid(*p) == typeid(School)){
            School *per = dynamic_cast<School*>(p);
            std::cout<<*per;
        }else{
            College *per = dynamic_cast<College*>(p);
            std::cout<<*per;
        }
    }
}

void DeleteObject(Container &data)
{
    for(Person* p: data){
        delete p;
    }
}
