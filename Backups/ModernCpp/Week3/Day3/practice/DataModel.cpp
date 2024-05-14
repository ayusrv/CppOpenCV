#include "DataModel.h"
DataModel::DataModel(VType instances, std::vector<float> prices)
            : _instances{std::move(instances)}, _prices{prices} {}

std::ostream &operator<<(std::ostream &os, const DataModel &rhs)
{
    os<<"Instances ";
    std::visit([&](auto&& val){
        os<<*val<<std::endl;
    }, rhs._instances);

    os<<"Prices: ";
    for(auto f : rhs._prices)
    {
        os << f <<" ";
    }
    os<<std::endl;
    return os;
}

void DataModel::operator()(){
    if(prices().empty()){
        throw EmptyContainer("Data is empty");
    }else{
        float avg=0.0f; 
        for(float f : prices())
        {
            avg+=f;
        }
        std::cout<<"Average of the prices is: "<<avg/prices().size()<<std::endl;
    }
}
