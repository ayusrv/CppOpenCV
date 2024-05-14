/*
    triggers app
    f1----------> f2(integers will be created)


                predicate to filter the data

*/

#include <functional>
#include <iostream>

std::function<int()> f2(int n1, int n2){
    //A lambda can capture from its enclosing function without explicit passing
    // auto lambda_fn = [](int n1, int n2){return  n1+n2;}; //do not redefine n1 n2
    // lambda_fn(10,20); //do not pass like this
    // auto lambda_fn = [&](){int val=99; return  n1+n2+10+20+val;}; //& capture all reference from surrounding this will auto take from f1
    //auto lambda_fn = [=](){return  n1+n2;}; //capture hoke copy krega by reference nahi
    //auto lambda_fn = [n1](){return  n1+n2;}; //bs n1 aayeaga n2 nahi so error dega
    auto lambda_fn=[&](){int val=99; return n1+n2+10+20+val;};
    lambda_fn();
    return lambda_fn;
}

void f1(){
    int n1=10;
    int n2 = 20;
    std::function<int()> modified_function = f2(n1,n2);
    std::cout<<modified_function()<<std::endl;
}

int main(){
    f1();
}

/*
    Main fn stack memory

    f1 stack memory 
    n1 [10] 0X76
    n2 [20] 0X80

    f2 stack memory
    n1 [10] 0X15H
    n2 [20] 0X19H
    LAMBDA_FN
    [........]



    CAPTURE CLAUSE
    void Magic(){
        int n1=10, n2=20;
        example1: all data values from surrounding are accessible inside f1
        auto f1 = [&](){ return n1+n2; }
        
        example2: selected data values captured by copy
        auto f1 = [n1](){return n1+n2;}
        only n1 is accessible, give error

        example3: seleted data values capture by reference
        auto f1 = [&n1, &n2](){return n1+n2;}
        //both are accessible

        example4: all data values cature by copy
        auto f1 = [=](){return n1+n2;}
        both accessible but data will come as copy

        example4: some by copy some by reference
        auto f1 = [n1, &n2, &n3](){return n1+n2+n3;}
        both accessible but n1 will come as copy and n2,n3 will come as reference
    }
*/

void trick(){
    int n1=100;
    auto f1 = [=]() mutable {n1=99;}; //mutuable lagana hoga local copy modify direct nahi kr skte hai 
    std::cout<<n1<<std::endl; //100 aayeaga local change krre hai kyuki

    int n2 = 100;
    auto f1 = [&](){n2=99;};
    f1();
    std::cout<<n2<<std::endl; //yaha 99 aayeaga call by reference hai 
}