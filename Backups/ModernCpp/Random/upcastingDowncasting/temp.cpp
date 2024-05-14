#include <bits/stdc++.h>
using namespace std;
class Shape
{
public:
    void area()
    {
        cout << "Shape area" << endl;
    }
    virtual ~Shape()
    {
    }
};
class Square : public Shape
{
public:
    int _side;
    void area()
    {
        std::cout << "Sqaure area" << std::endl;
    }
    Square(int side) : _side{side} {}
    void print()
    {
        cout << "Side is : " << this->_side;
    }

    ~Square()
    {
    }
};
class Triangle : public Shape
{
public:
    int _height, _base;
    void area()
    {
        std::cout << "Triangle area;" << std::endl;
    }
    Triangle(int height, int base) : _height{height}, _base{base} {}
    void print()
    {
        cout << "Height is : " << this->_height << " base is : " << this->_base << endl;
    }
    ~Triangle() {}
};

int main()
{
    Shape* sptr=new Shape();

    Triangle *tptr=dynamic_cast<Triangle *>(sptr);

    Square * ssptr=dynamic_cast<Square*>(sptr);

    tptr->area();
}