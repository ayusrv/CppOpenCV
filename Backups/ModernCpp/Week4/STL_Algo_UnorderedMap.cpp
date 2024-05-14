/*
    Hashtable 
    key is integer (employee id)
    value is employee object on satack

*/

#include <iostream>
#include <unordered_map>
#include "Employee.h"
#include <memory>

void CreateObjectsRawPointer(std::unordered_map<int,Employee*>& mapData)
{
    mapData.emplace(101, new Employee("Ayush", 20000, "ASE", 1));
    mapData.emplace(102, new Employee("Aman", 30000, "SDE", 4));
}

void DisplayRawPointer(const std::unordered_map<int,Employee*> mapData)
{
    for(auto [key, value] : mapData)
    {
        std::cout<<key<<"\t"<<*value<<"\n";
    }
}

void CreateObjects(std::unordered_map<int,Employee> mapData)
{
    mapData.emplace(101, Employee("Ayush", 20000, "ASE", 1));
    mapData.emplace(102, Employee("Aman", 30000, "SDE", 4));
}

void Display(const std::unordered_map<int,Employee>& mapData)
{
    for(auto [key, value] : mapData)
    {
        std::cout<<key<<"\t"<<value<<"\n";
    }
}

void CreateObjectsSmpt(std::unordered_map<int, std::shared_ptr<Employee>>& mapData)
{
    mapData.emplace(12, std::make_shared<Employee>("12",12,"12",12));
    mapData.emplace(13, std::make_shared<Employee>("12",12,"12",12));
    mapData.emplace(14, std::make_shared<Employee>("12",12,"12",12));
}

void DisplayObjectsSmpt(std::unordered_map<int, std::shared_ptr<Employee>>& mapData)
{
    for(auto[key, value] : mapData)
    {
        std::cout<<key<<" "<<*value<<std::endl;
    }
}

int main()
{
    std::unordered_map<int, Employee> mapData;
    CreateObjects(mapData);
    Display(mapData);

    std::unordered_map<int, Employee*> mapData2;
    CreateObjectsRawPointer(mapData2);
    DisplayRawPointer(mapData2);

    std::unordered_map<int, std::shared_ptr<Employee>> mapData3;
    CreateObjectsSmpt(mapData3);
    DisplayObjectsSmpt(mapData3);
}