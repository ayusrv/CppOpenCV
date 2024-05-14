#include <iostream>
#include <list>
class Demo
{
private:
    int id;
    std::string name;
public:
    Demo() = default;
    
    explicit Demo (int id) : id(id){}

    void Display(){
        std::cout << "Hello,World\n";
    }

    virtual ~Demo(){
        std::cout << "Demo Destroyed\n";
    }
};


void magic(Demo obj){
    obj.Display();   
}

int main(){
    Demo* d1 = new Demo();
    Demo *d2 = new Demo(std::move(*d1));
    std::list<Demo> data { *d2 };
}