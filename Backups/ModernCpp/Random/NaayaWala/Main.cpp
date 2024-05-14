#include <iostream>
#include <future>
#include <numeric>
#include <algorithm>
#include <vector>
std::mutex mt;

class Main
{
private:
    std::string _name;
    int _id;

public:
    Main(/* args */) {}
    ~Main() {}
    Main(std::string name, int id) : _name{name}, _id{id} {}

    std::string name() const { return _name; }

    int id() const { return _id; }

    void setId(int id) { _id = id; }

    void setName(const std::string &name) { _name = name; }

    friend std::ostream &operator<<(std::ostream &os, const Main &rhs)
    {
        os << "_name: " << rhs._name
           << " _id: " << rhs._id;
        return os;
    }
};

using Container = std::vector<Main *>;

void CreateObjects(Container &data)
{
    data.push_back(new Main("120", 10));
    data.push_back(new Main("130", 20));
    data.push_back(new Main("140", 30));
    data.push_back(new Main("150", 40));
}

void Display(Container &data)
{
    std::for_each(data.begin(), data.end(), [](Main *m)
                  { std::cout << *m << "\n"; });
}

float multiply(Container &data)
{
    return std::accumulate(
        data.begin(),
        data.end(),
        1.0f,
        [](float val, Main *m)
        {
            return val * m->id();
        });
}

float sum(Container &data)
{
    return std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float ide, Main *m2)
        {
            return ide + m2->id();
        });
}

Container NayaWalaContainer(Container &data)
{
    // std::lock_guard<std::mutex> lg(mt);
    Container result;

    std::transform(data.begin(), data.end(), std::inserter(result, result.begin()), [&](Main *m)
                   {
                       Main *temp = new Main();
                       temp->setName(m->name());
                       temp->setId(m->id() + sum(data));
                       return temp;
                   });
    return result;
}
float answers(std::future<int> &ft, Container &data)
{
    // std::lock_guard<std::mutex> lg(mt);
    std::future<float> mul = std::async(&multiply, std::ref(data));
    std::future<float> summ = std::async(&sum, std::ref(data));
    float mult = mul.get();
    float s = summ.get();
    std::cout << mult << " " << s << "\n";
    int val = ft.get();
    return (s + mult) / val;
}

int main()
{
    Container data;
    CreateObjects(data);
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    std::future<float> fut = std::async(&answers, std::ref(ft), std::ref(data));
    int n;
    std::cout<<"Enter the n value: ";
    while(!(std::cin>>n))
    {
        std::cout<<"Wrong value please try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    pr.set_value(n);
    float ans = fut.get();
    std::cout << ans << "\n";
    std::future<Container> res = std::async(&NayaWalaContainer, std::ref(data));
    Container result = res.get();
    for (Main *m : result)
    {
        std::cout << *m << "\n";
    }
    Display(data);
}