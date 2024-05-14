#ifndef DEMO_H
#define DEMO_H

#include<iostream>
class Demo
{
private:
    int _id;
    std::string _name;
public:
    Demo(/* args */) {}
    ~Demo() {}
    Demo(int id, std::string name);

    friend std::ostream &operator<<(std::ostream &os, const Demo &rhs);
    
};

#endif // DEMO_H
