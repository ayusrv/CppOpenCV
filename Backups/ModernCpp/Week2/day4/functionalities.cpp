#include "functionalities.h"

void Adaptor(FType fn, Container &data)
{
    if(data.empty()){
        throw std::runtime_error("Data is empty");
    }
    fn(data);
}


FType lfn1 = [](Container &data) {std::cout<<data.front()<<std::endl;};

FType lfn2 = [](Container &data) {std::cout<<data.back()<<std::endl;};

FType lfn3 = [](Container &data) {std::cout<<data.size()<<std::endl;};