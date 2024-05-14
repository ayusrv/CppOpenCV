#include <iostream>
#include <queue>
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>

//Priority queue = std::priorityquue<data inside container / object, std::vector<data inside container / object>, lambda function/ comparator> ;

class kuchv;

using kuchvPtr = std::shared_ptr<kuchv>;
using kuchvContainer = std::unordered_map<int, kuchvPtr>;
using priorityQueue = std::priority_queue<std::pair<int, kuchvPtr>, std::vector<std::pair<int, kuchvPtr>>, std::function<bool(const std::pair<int, kuchvPtr>& kp1, const std::pair<int, kuchvPtr>& kp2)>>;


class kuchv
{
private:
    int _roll;
    std::string _name;
public:
    kuchv()=default;
    kuchv(const kuchv &)=delete;
    kuchv(kuchv && )=delete;
    kuchv & operator=(const kuchv & )=delete;
    kuchv &operator=(kuchv &&)=delete;
    kuchv(int roll, std::string name) : _roll{roll}, _name{name} {}
    ~kuchv()=default;

    int roll() const { return _roll; }
    void setRoll(int roll) { _roll = roll; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    friend std::ostream &operator<<(std::ostream &os, const kuchv &rhs) {
        os << "_roll: " << rhs._roll
           << " _name: " << rhs._name;
        return os;
    }
};

bool functions(const kuchvPtr& kp1, const kuchvPtr& kp2)
{
    return kp1->roll() > kp2->roll();
}

void createObject(kuchvContainer& data)
{

    data.emplace(12, std::make_shared<kuchv>(12, "Ayush"));
    data.emplace(13, std::make_shared<kuchv>(13, "Purvak"));
    data.emplace(11, std::make_shared<kuchv>(11, "Devansh"));

    // data.push_back(std::make_shared<kuchv>(12, "Ayush"));
    // data.push_back(std::make_shared<kuchv>(13, "Purvak"));
    // data.push_back(std::make_shared<kuchv>(11, "Devansh"));
}

int main()
{
    kuchvContainer data;
    createObject(data);
    priorityQueue pq(data.begin(), data.end(), [](const std::pair<int, kuchvPtr>& kp1, const std::pair<int, kuchvPtr>& kp2){
        return kp1.second->roll() > kp2.second->roll();
    });

    while(!pq.empty())
    {
        std::cout<<*pq.top().second<<"\n";
        pq.pop();
    }
}