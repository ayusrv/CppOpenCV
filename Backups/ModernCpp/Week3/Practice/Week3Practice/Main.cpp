#include "Functionalities.h"

int main(){
    Container data;
    CreateObject(data);
    std::cout<<AverageAge(data)<<std::endl;
    std::optional<std::vector<std::string>> res = SameTeacher(data);
    if(res.has_value())
    {
        for(std::string s : res.value())
        {
            std::cout<<"Name: "<<s<<std::endl;
        }
    }
    else{
        std::cout<<"No data available"<<std::endl;
    }
}