#ifndef CLASSA_H
#define CLASSA_H

#include <iostream>
#include <functional>

class classA
{
private:
    int _n1{0};
    int _n2{0};

public:
    classA() = default;
    classA(int n1, int n2) : _n1{n1}, _n2{n2} {}
    ~classA() {}
    void sum(int n1, int n2)
    {
        std::cout << "Sum is: " << n1 + n2 << std::endl;
    }

    void multiply(int n1, int n2)
    {
        std::cout << "Multiply is: " << n1 * n2 << std::endl;
    }

    void substract(int n1, int n2)
    {
        std::cout << "Substraction is: " << n1 - n2 << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &os, const classA &rhs)
    {
        os << "_n1: " << rhs._n1
           << " _n2: " << rhs._n2;
        return os;
    }
};

#endif // CLASSA_H
