#ifndef CALSSA_H
#define CALSSA_H

#include <iostream>

class ClassA
{
private:
    int _id;
public:
    ClassA()=default;
    ClassA(const ClassA &)=default;
    ClassA(ClassA && )=default;
    ClassA & operator=(const ClassA & )=delete;
    ClassA &operator=(ClassA &&)=delete;
    ~ClassA()=default;
    ClassA(int id){
        _id = id;
    }

    virtual void vechicle(){
        std::cout<<"Vehicle called: \n";
    }

    int id() const { return _id; }
    void setId(int id) { _id = id; }
};

#endif // CALSSA_H
