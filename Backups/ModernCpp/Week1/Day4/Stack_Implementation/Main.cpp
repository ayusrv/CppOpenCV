#include "Stack.hpp"
#include <iostream>
int main()
{
    Stack<int> s;
    try
    {
        s.Push(10);
        s.Push(20);
        std::cout << s.IsEmpty() << std::endl;
        std::cout << s.Size() << std::endl;
        s.Pop();
        s.Pop();
        std::cout << s.Size() << std::endl;
        s.Pop();
    }
    catch (StackEmptyException &e)
    {
        std::cout << e.what() << std::endl;
    }
}