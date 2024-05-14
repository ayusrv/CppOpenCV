#include "Employee.h"

/*
    The middlemen/ intermediate function will have to designed to accept 0 or more arguments (potential infinite)

    2) lvalue binding to rvalue situation is ANNOYING
*/


template <typename T, typename... Args>
T Relay(Args... args)
{
    return T(std::forward<Args>(args)...);
}

void Demo(int&& n1){
    std::cout<<n1<<std::endl;
}

void Magic(int&& n1) //10 gets assigned to n1 and now n1 is lvalue
{
    //forwading n1 to any funtion will now forward n1 as rvalue rather than lvalue
    // Demo(n1); //an rvalue reference cannot be bound to an lvalue
    Demo(Relay<int>(n1));
    std::cout<<n1;
}

class EMp{
    int _id;
    std::string _name;
public:
    EMp(int i, std::string name) : _id{i}, _name{name}{}

    int id() const { return _id; }

    std::string name() const { return _name; }
};

int main(){
    // Magic(10);
    EMp e(Relay<EMp>(10,"Ayush"));
    std::cout<<e.id()<<" "<<e.name()<<std::endl;

}