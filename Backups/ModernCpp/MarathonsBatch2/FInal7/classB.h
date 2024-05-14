#ifndef CLASSB_H
#define CLASSB_H

#include "calssA.h"

class classB : public ClassA
{
private:
    std::string _name;
public:
    classB()=default;
    classB(const classB &)=delete;
    classB(classB && )=delete;
    classB & operator=(const classB & )=delete;
    classB &operator=(classB &&)=delete;
    ~classB()=default;
    classB(int id, std::string name) : ClassA(id), _name{name} {}

    void vechicle(){
        std::cout<<"Class B called\n";
    }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }
};

#endif // CLASSB_H
