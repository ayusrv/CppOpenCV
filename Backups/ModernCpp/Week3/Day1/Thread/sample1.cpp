/*
    processor : It is a hardware device based on SILICON (at least till today) which executed instructions given    eg: Intel i5 12gen 1230U

    Core: It is a section of the processor which is capable of executing one whole process
        [   c1   |   c2   ]
        [   c3   |   c4   ]

    Singl ethread, single process, synchronous programs!
*/


/*
    Delayes -> I/O Delays, CPU-Bound Delay
*/

#include <iostream>
#include <array>
#include <thread>

void Square(std::array<int,5>& number){
    for(int num : number)
    {
        // 1 second artificial delay
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"Square of "<<num<<" is: "<<num*num<<std::endl;
    }
}


void Cube(std::array<int,5>& number){
    for(int num : number)
    {
        // 1 second artificial delay
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<<"Cube of "<<num<<" is: "<<num*num*num<<std::endl;
    }
}

int main(){
    std::array<int,5> data{1,2,3,4,5};
    Square(data);
    std::cout<<std::endl;
    Cube(data);
}