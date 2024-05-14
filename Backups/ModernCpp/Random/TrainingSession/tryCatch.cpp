#include<iostream>
#include<stdexcept>
 
int main(){
 
int a,b,c;
validInput:
try{
    // exception generated is obejct of runtime_error class so we throw it
    int a;
    std::cout<<"Provide input";
    std::cin>>a;
    if(a!=1 and a!=2) throw std::runtime_error("Please Provide a Valid Input");
    std::cout<<a;
   
}catch(std::runtime_error &e){
    // exception class has a virtual function what and here in runtime error
    //class we will override it
    std::cout<<e.what()<<"\n";
    goto validInput;
}
 
return 0;
}