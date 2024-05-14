#include "functionalities.h"

int main(){
    Container data;
    DataConatiner data2 {10,20,30,40};
    CreateObject(data);
    PrintObject(data, data2);
    auto sum_bind = std::bind(&sum1, std::placeholders::_2, std::placeholders::_1);
    sum_bind(20,3);
    std::vector<Standardize> v1{sum, mul, sub};
    
    CreateObjects2(v1,data2);
}