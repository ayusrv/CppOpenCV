#include<iostream>
#include<functional>
class Calculator
{
private:
    int multiply_factors = 2;
 
public:
    void performOperations(std::function<int()> fun)
    {
        std::cout << fun()<< std::endl;
    }
 
    void performOperations(int a, int b)
    {
        auto op = [&]() mutable{a = 60; return a * b * multiply_factors;};
        performOperations(op);
    }
};
 
int main()
{
 
    Calculator c;
    c.performOperations(3, 5);
 
}