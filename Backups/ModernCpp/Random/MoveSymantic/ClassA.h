#ifndef CLASSA_H
#define CLASSA_H

#include <iostream>
#include<cstring>
class ClassA
{
private:
    int _id;
    std::string _name;
    char * _msg;
public:
    ClassA() {}
    ClassA (ClassA&& a){
        ClassA(a._id,a._name,a._msg);
    }
    ClassA(const ClassA &)=delete;
    ClassA &operator=(const ClassA &)=delete;
    ClassA & operator=(ClassA &&)=delete;
    ~ClassA() {
        delete []_msg;
    }
    ClassA(int id, std::string name,const char* msg);

    int id() const { return _id; }

    void setId(int id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    char * msg() const { return _msg; }

    friend std::ostream &operator<<(std::ostream &os, const ClassA &rhs);
};

#endif // CLASSA_H
