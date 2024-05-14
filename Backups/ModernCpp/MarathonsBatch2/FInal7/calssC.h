#ifndef CALSSC_H
#define CALSSC_H

#include "calssA.h"

class classC : public ClassA
{
private:
    std::string _name;
public:
    classC()=default;
    classC(const classC &)=delete;
    classC(classC && )=delete;
    classC & operator=(const classC & )=delete;
    classC &operator=(classC &&)=delete;
    ~classC()=default;
    classC(int id, std::string name) : ClassA(id), _name{name} {}

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }
};

#endif // CALSSC_H
