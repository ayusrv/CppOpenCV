#include <iostream>

int main(){
    int x=10;
    float y = 20.33;
    char a = 'a';
    signed char b = 'b';
    unsigned char c = 'c';
    unsigned char d = 'd';

    std::cout<<"x: "<<&x<<std::endl;
    std::cout<<"y: "<<&y<<std::endl;
    std::cout<<"a: "<<&a; //This will print "abcd" treat as string
    std::cout<<"b: "<<&b; //This will print "bcd" treat as string 
    std::cout<<"c: "<<&c; //cd
    std::cout<<"d: "<<&d<<std::endl; //d

    //If you want to print the address of the char then add (void*)
    
    std::cout<<"a: "<<(void*)&a<<std::endl; //Address of a
    std::cout<<"b: "<<(void*)&b<<std::endl; //Address of b
    std::cout<<"c: "<<(void*)&c<<std::endl; //address of c
    std::cout<<"d: "<<(void*)&d<<std::endl; //Address of d

    //To get the address of Main use (void*)&main and to get the size of main use &main
    std::cout<<std::endl;
    std::cout<<"Size of main: "<<&main<<std::endl; //Each function will show the size as 1
    std::cout<<"Address of main: "<<(void*)&main<<std::endl;

    int &ref = x;
    std::cout<<"Value of ref: "<<ref<<std::endl;
    std::cout<<"Address of ref: "<<&ref<<std::endl;

}