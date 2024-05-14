#include<bits/stdc++.h>
#include <ostream>
using namespace std;

class A{
    int x;
    float y;
public:
    friend std::ostream &operator<<(std::ostream &os, const A &rhs);
    friend std::istream & operator>>(std::istream& in, A &p);};

std::ostream &operator<<(std::ostream &os, const A &rhs) {
    os << "x: " << rhs.x
       << " y: " << rhs.y;
    return os;
}

std::istream &operator>>(std::istream &in, A &rhs)
{
    // TODO: insert return statement here
    in>>rhs.x;
    in>>rhs.y;
    return in;
}

class B : public A{
    int a;
    int b;
    public:
        friend std::ostream &operator<<(std::ostream &os, const B &b);
        friend std::istream & operator>>(std::istream& in, B &b);
};

std::ostream &operator<<(std::ostream &os, const B &rhs) {
    os << "x: " << rhs.a
       << " y: " << rhs.b;
    return os;
}

std::istream &operator>>(std::istream &in, B &rhs)
{
    // TODO: insert return statement here
    in>>rhs.a;
    in>>rhs.b;
    
    return in;
}