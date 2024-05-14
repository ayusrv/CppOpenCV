#include <iostream>
#include <functional>

int main()
{
    int a2 = 9, b2 = 10;
    int a = 10;
    int b = 30;
    std::function<int(int, int)> fun = [=](int a, int b) mutable
    {
        return a * b;
    };
    std::cout << fun(a, b) << std::endl;
    std::cout << a2 << " " << b << std::endl;

    auto binded = std::bind(fun,std::placeholders::_1,10);
    std::cout<<binded(10,20)<<'\n';
}