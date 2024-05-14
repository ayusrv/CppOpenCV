#include <iostream>

class classA{
    public:
        virtual void Display(){
            std::cout<<"A display"<<std::endl;
        }
        void awala(){
            std::cout<<"a wala"<<std::endl;
        }
};

class classB : public classA{
    public:
        void Display(){
            std::cout<<"B Display"<<std::endl;
        }
};





int main(){
    // classA *a = new classA(); 
    // classB* b1 = static_cast<classB*>(a); //ye v object hi banara hai basically tum a ka naam badal k b1 kr diye ho
    // classB b2 = static_cast<classB&>(*a); //ye B ka naya object banara hai 
    // if((void*)&b2==nullptr || b1==nullptr){
    //     std::cout<<"NULL"<<std::endl;
    // }
    //b1->Display();
    //b2.Display();
    //b2.awala();
    classB b;
        b.classA::Display();
    }