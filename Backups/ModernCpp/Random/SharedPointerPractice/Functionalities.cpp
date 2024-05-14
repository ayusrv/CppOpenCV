#include "Functionalities.h"

    void CreateObjects(Container &data)
    {
        data.push_back(std::make_shared<Section>("20BCS5673", "20KRG1", std::make_shared<Branch>("CSE", "12/12/12", 
                        std::make_shared<Student>("Ayush", "Jamshedpur", std::array<float,4> {1,2,3,4}))));

        data.push_back(std::make_shared<Section>("20BCS5668", "20BCS10", std::make_shared<Branch>("CSE", "11/11/12", 
                        std::make_shared<Student>("Jasleen", "Chattisgadh", std::array<float,4> {1,2,3,4}))));

        // data.push_back(std::make_shared<Section>("20BCS5670", "20BCS6", std::make_shared<Branch>("CSE", "12/12/12", nullptr)));

        // Student John("John", "abhd", std::array<float,4> {1,2,3,4});

        data.push_back(std::make_shared<Section>("20BCS5670", "20BCS6", std::make_shared<Branch>("CSE", "12/12/12", 
                        std::make_shared<Student>((Student("ab","hh",std::array<float,4> {1,2,3,4}))))));
        
        
    }

void PrintObjects(Container &data)
{
    for(const auto& s : data){
        if(s == nullptr || s->branch() == nullptr || s->branch()->student() == nullptr){
            std::cerr << "Error: Null pointer encountered in data container!" << std::endl;
            continue; // Move to the next iteration of the loop
        }
        std::cout << *s << std::endl;
    }
}


// Section*  -> std::shared_ptr<Section>
//new Section() -> std::make_shared<Section>()