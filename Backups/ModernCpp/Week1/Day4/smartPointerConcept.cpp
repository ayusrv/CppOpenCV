#include <iostream>
#include <memory>

class Example1{
    private:
        int _id;
        std::string _name;

    public:
        Example1(int id, std::string name) : _id{id}, _name{name} {}
        ~Example1(){}
};


void Dummy(){
    // Example1*ex1 = ;

    // std::shared_ptr<Example1> sptr {new Example1(10,"Ayush")};
    // prefered option new and delete hum modern mai manually use nahi ktre hai
    std::shared_ptr<Example1> sptr {std::make_shared<Example1>(10,"Ayush")}; 
    int n1{0} ;
    std::cin>>n1;
    std::cout<<10/n1;


}

int main(){

}


/*

    Demo()                              heap
        ----------------------> [  10  |  Harshit  ]

    ex1    |
    [   0X100H  ]
    <--8 Bytes -->
    0X11H       0X18H

    n1
    [     0    ]
    <-4 Bytes ->
    0X45H     0X49H
*/


/*
        data : pointer ex1
        function which is guranteed to execute each
        time an object is destrotes destructor
        action before data (ex1) is destroyes : 
        head deallocation using delete ex1


*/

/*
    Types of smart pointers
        1) Unique Pointer
        2) Shared Pointer
        3) Weak Pointer (token which can convert to shared ptr)

*/