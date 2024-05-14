/*
    Design an adapter function that accepts a container of function wrapper and a container of data values
        Map each function on each item in the data container and print the output
        All functions must accepts only a integer and return void
*/

#include <iostream>
#include <functional>
#include <vector>

using Function_Conatiner = std::function<void(int)>;

void square(int num){
    std::cout<<num*num;
}

void cube(int num){
    std::cout<<num*num*num;
}

void operations2(std::function<void(int)> fn, int n1){
    fn(n1);
}

void operation(const std::vector<int> &data, std::vector<Function_Conatiner> fn){
    for(Function_Conatiner i : fn){
        for(int j : data){
            i(j);
        }
        std::cout<<std::endl;
    }
}

int main(){
    std::vector<Function_Conatiner> function{
        [](int number){std::cout<<"Number*10 is: "<<number*10<<std::endl;},
        [](int number){std::cout<<"Number*20 is: "<<number*20<<std::endl;}
    };

    std::vector<int> v{1,2,3,4,5};
    operation(v, function);
    std::cout<<std::endl;
    operations2(square,2);
    operations2(cube, 12);
    std::cout<<std::endl;

    std::function<void (int)> fn;
    std::cout<<"Enter 1 for Square and 2 for Cube: ";
    int num;
    std::cin>>num;
    if(num==1){
        fn=square;
    }else{
        fn=cube;
    }
    fn(4);
}