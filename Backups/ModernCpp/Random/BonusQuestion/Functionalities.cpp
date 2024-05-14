#include "Functionalities.h"

std::function<void(Container &)> CreateObject = [](Container &data)
{
    VConatiner students;
    students.push_back(std::make_shared<OfflineStudent>("Kinshuk", 12, Gender::MALE, std::vector<int>{71, 72, 73, 74, 75}));
    students.push_back(std::make_shared<OnlineStudent>("Eishika", 11, Gender::FEMALE, std::vector<int>{81, 82, 83, 84, 85}));
    students.push_back(std::make_shared<OfflineStudent>("Preeti", 13, Gender::FEMALE, std::vector<int>{91, 92, 93, 94, 94}));
    students.push_back(std::make_shared<OnlineStudent>("Kshitij", 14, Gender::MALE, std::vector<int>{61, 62, 63, 64, 65}));
    students.push_back(std::make_shared<OfflineStudent>("Himasnhu", 10, Gender::MALE, std::vector<int>{85, 85, 86, 86, 86}));
    students.push_back(std::make_shared<OnlineStudent>("Praduman", 11, Gender::LGTV, std::vector<int>{51, 52, 53, 54, 55}));

    data.emplace("1111", std::make_shared<Teacher>("1111", "Harshit", std::vector<VType>{students[0], students[1]}, Gender::FEMALE));
    data.emplace("2222", std::make_shared<Teacher>("2222", "Shreya", std::vector<VType>{students[2], students[3]}, Gender::LGTV));
    data.emplace("3333", std::make_shared<Teacher>("3333", "Ayushi", std::vector<VType>{students[4], students[5]}, Gender::FEMALE));
};

std::function<void(Container &)> Display = [](Container &data)
{
    for (auto &[key, value] : data)
    {
        std::cout << "Key of the Teacher is: " << key << "\n";
        std::cout << "Data of Teacher is: " << *value << "\n";
    }
};

std::function<bool(VType &)> Percentage = [](VType &v)
{
    bool percentage;
    if (std::holds_alternative<OfflineStudentPointer>(v))
    {

        OfflineStudentPointer offS = std::get<OfflineStudentPointer>(v);
        std::vector<int> vec = offS->marks();
        int sum = std::accumulate(
            vec.begin(),
            vec.end(),
            0,
            [](int startVal, int mark)
            {
                return startVal + mark;
            }
        );
        if((sum/5) > 45) percentage = true;
        else percentage = false;
    }

    if (std::holds_alternative<OnlineStudentPointer>(v))
    {

        OnlineStudentPointer offS = std::get<OnlineStudentPointer>(v);
        std::vector<int> vec = offS->marks();
        int sum = std::accumulate(
            vec.begin(),
            vec.end(),
            0,
            [](int startVal, int mark)
            {
                return startVal + mark;
            }
        );
        if((sum/5) > 65) percentage = true;
        else percentage = false;
    }
    return percentage;
};

std::function<void(Container &)>
    PassFaill = [](Container &data)
{
    for (auto &[key, value] : data)
    {
        for (VType v : value->variant())
        {
            std::cout<<"Student passed or not "<<std::boolalpha<<Percentage(v)<<"\n";
        }
    }
};

std::function<TeacherPointer(Container&)> MaxMarks = [](Container& data)
{
    TeacherPointer tp;
    float marks =0.0f;
    for(auto&[key, value] : data)
    {
        int total_marks=0, count=0;
        for(VType v : value->variant())
        {
            std::visit([&](auto&& args)
            {
                for(int i : args->marks())
                {
                    total_marks+=i;
                }
            },v);
            count++;
        }
        if(marks<total_marks/(count*5)){
            tp = value;
            marks = total_marks/(count*5);
        }
    }
    return tp;
};

bool shortData(const PairVal& p1, const PairVal& p2)
{
    return p2.second->empId() < p1.second->empId();
}

std::function<void(Container&)> Priorities = [](Container& data)
{
    PriorityQueue pq2(data.begin(), data.end(), shortData);
    while(!pq2.empty())
    {
        std::cout<<pq2.top().first<<" ";
        pq2.pop();
    }
    
};