#include "functionalities.h"

int main(){
    Container data {1,2,3,4,5};
    try{
        Adaptor(lfn1, data);
        Adaptor(lfn2, data);
        Adaptor(lfn3, data);

        //You can make your own function
        Adaptor([](Container &data){std::cout<<data[0] + data[1]<<std::endl;},data);
    }
    catch(std::runtime_error& ex){
        std::cout<<ex.what();
    }

    int a=10;
    int b=20;
    auto f1 = [&]() mutable {
        a=15;
        b=30;
        std::cout<<a<<" "<<b<<std::endl;
    };
    f1();
    std::cout<<a<<" "<<b<<std::endl;
}