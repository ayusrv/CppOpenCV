#include <iostream>

class LamdaImplementation{
    private:

    public:
        LamdaImplementation() = default;
        ~LamdaImplementation() = default;

        //Function call () operator 
        void operator()(int number){
            std::cout<<"Square of : "<<number<<" is: "<<number*number;
        }
};

int main(){
    LamdaImplementation l1;
    l1(10); // operator () is called
}

//function wrapper cpp con  