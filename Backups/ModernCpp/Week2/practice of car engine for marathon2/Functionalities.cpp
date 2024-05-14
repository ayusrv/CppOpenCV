#include "Functionalities.h"

void createobject(std::vector<std::shared_ptr<Car>> &data,std::vector<std::shared_ptr<Engine>> &data1)
{
    
    data1[0]=std::make_shared<Engine>(100,200);
    data1[1]=std::make_shared<Engine>(200,300);
    data[0]=std::make_shared<Car>(*(data1[0]),"MH11CQ7345","101",20000,"SEDAN",cartype::BIKE);
    data[1]=std::make_shared<Car>(*(data1[1]),"MH11CQ7345","102",40000,"SEDAN",cartype::BIKE);
}

void calculate_avg_horse_power(std::function<int(std::vector<std::shared_ptr<Engine>>)> f1, std::vector<std::shared_ptr<Engine>> &data)
{
    std::cout<<std::endl;
    std::cout<<"Avg horpower is "<<f1(data);
}
