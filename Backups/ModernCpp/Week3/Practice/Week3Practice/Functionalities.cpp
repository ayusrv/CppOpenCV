#include "Functionalities.h"

std::function<void(Container&)> CreateObject = [](Container& data){
    data.push_back(std::make_shared<School>(std::make_shared<Student>("AYush", Gender::MALE, 20, 219382, "Harshit"), "KPIT"));

    data.push_back(std::make_shared<School>(std::make_shared<Student>("Satyam", Gender::MALE, 21, 219388, "Harshit"), "KPIT"));

    data.push_back(std::make_shared<School>(std::make_shared<Teacher>("Nidhi", Gender::FEMALE, 27, 219382, 60000), "KPIT"));

    data.push_back(std::make_shared<School>(std::make_shared<Teacher>("Nidhi", Gender::CHUTIYA, 26, 269382, 45000), "KPIT"));
};

std::function<float(Container&)> AverageAge = [](Container& data){
    float avg = 0.0f;
    for(SType s : data)
    {
        std::visit([&](auto&& args){
            avg+=args->age();
        }, s->variant());
    }
    return avg/data.size();
};

std::function<std::optional<std::vector<std::string>>(Container&)> SameTeacher = [](Container& data) -> std::optional<std::vector<std::string>>{
    std::string name = "Harshit";
    std::vector<std::string> res;
    for(SType s : data)
    {
        if(std::holds_alternative<StudentPointer>(s->variant()))
        {
            StudentPointer stud = std::get<0>(s->variant());
            if(stud->classTeacher()==name){
                res.push_back(name);
            }
        }
    }
    if(res.empty()){
        return std::nullopt;
    }
    return res;
};