#include <iostream>
#include <vector>
#include <functional>

// class Calculator
// {
// private:
//     int multiply_factors = 2;

// public:
//     void performOperations(std::function<int()> fun)
//     {
//         // fun();
//         std::cout << fun() << std::endl;
//     }

//     void performOperations(int a, int b)
//     {
//         auto op = [&]()
//         {
//             a = 20;
//             return a * b;
//         };
//         performOperations(op);
//     }
// };



std::string fun(int g, std::function<std::string(int)> f)
{
    std::string s = f(g);
    std::cout << s << std::endl;
    return s;
}

// void operations(std::vector<int> &data1, std::vector<int> &data2, std::vector<std::function<void(int, int)>> fn)
// {
//     for (int i = 0; i < data1.size(); i++)
//     {
//         for (std::function<void(int, int)> f : fn)
//         {
//             f(data1[i], data2[i]);
//         }
//     }
// }

// int process(std::function<int(int, int)> operations)
// {
//     return operations(10, 10);
// }

void square(int a) {std::cout<<a*a;}
void cube(int a){std::cout<<a*a*a;}
void op(std::function<void(int)> f, int a){
    f(a);
}

int sum(std::vector<int> &data){
    int s=0;
    for(int i : data){
        s+=i;
    }
    return s;
}

int product(std::vector<int> &data){
    int prod = 1;
    for(int i : data){
        prod*=i;
    }
    return prod;
}

int operationss(std::function<int(std::vector<int> &)> fun, std::vector<int> &data){
    return fun(data);
}

int main()
{
    std::vector<int> data {1,2,3,4,5};
    std::cout<<operationss(product, data); 
    // op(cube, 20);
    













    // Calculator c;
    // c.performOperations(10, 20);
    // std::cout << "Member function takes lambda as an input " << std::endl;
    // int x = 0, y = 0;
    // c.performOperations([&]()
    //                     { return x * y; });

    std::string ss = fun(10,
        [s = "kj"](int)
        {std::cout<<s<<std::endl;return "hello"; return "kk"; });
        std::cout<<ss<<std::endl;

    // std::vector<int> data1{10, 20, 30};
    // std::vector<int> data2{60, 70, 80};
    // std::vector<std::function<void(int, int)>> fn{
    //     [&](int n1, int n2)
    //     { std::cout << "Sum is: " << n1 + n2 << std::endl; }};
    // operations(
    //     data1,
    //     data2,
    //     fn);

    // int data = 100;
    // auto val = [&]()
    // { data = 99; };
    // std::cout << data << std::endl; // This will print 100

    // // If you call the val then the lambda function is invoked now this will show x=99
    // val();
    // std::cout << data << std::endl;

    // auto lambda = []()
    // { std::cout << "Hello, Lambda!" << std::endl; };
    // lambda();
    // // decltype(lambda);  Error

    // auto lambda2 = [](int x = 5)
    // { std::cout << x << std::endl; };
    // lambda2();

    // std::cout << process([&](int a, int b)
    //                      { return a * b; });

                         
}