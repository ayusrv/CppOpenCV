#include <iostream>
#include <queue>
#include <functional>
#include <memory>
class EkAurClass
{
private:
    /* data */
    int _price;
    std::string _name;

public:
    EkAurClass() = default;
    EkAurClass(const EkAurClass &) = delete;
    EkAurClass(EkAurClass &&) = delete;
    EkAurClass &operator=(const EkAurClass &) = delete;
    EkAurClass &operator=(EkAurClass &&) = delete;
    ~EkAurClass() = default;

    friend std::ostream &operator<<(std::ostream &os, const EkAurClass &rhs)
    {
        os << "price: " << rhs._price
           << " _name: " << rhs._name;
        return os;
    }

    EkAurClass(int price, std::string name) : _price{price}, _name{name} {}

    int price() const { return _price; }
};

auto lambdaFun = [](const std::shared_ptr<EkAurClass> e1, const std::shared_ptr<EkAurClass> e2)
{
    return e1->price() < e2->price();
};

bool chekcPrice(const std::shared_ptr<EkAurClass> e1, const std::shared_ptr<EkAurClass> e2)
{
    return e1->price() < e2->price();
}

struct comp
{
    bool pricee(const std::shared_ptr<EkAurClass> e1, const std::shared_ptr<EkAurClass> e2)
    {
        return e1->price() < e2->price();
    }
};

auto Comparator = [](const EkAurClass *e1, const EkAurClass *e2) -> bool
{
    return e1->price() < e2->price();
};

bool Less_Comparison(const EkAurClass *e1, const EkAurClass *e2)
{
    return e1->price() < e2->price();
}

struct comp
{
    bool operator()(EkAurClass *c1, EkAurClass *c2)
    {
        return c1->price() > c2->price();
    }
};

int main()
{
    std::vector<EkAurClass *> vec;

    vec.push_back(new EkAurClass(100, "Himanshu"));
    vec.push_back(new EkAurClass(5347, "Kshitij"));
    vec.push_back(new EkAurClass(54, "Navidha"));
    vec.push_back(new EkAurClass(8534, "Ayush"));

    std::vector<std::shared_ptr<EkAurClass>> data;
    data.push_back(std::make_shared<EkAurClass>(100, "Himanshu"));
    data.push_back(std::make_shared<EkAurClass>(5347, "Kshitij"));
    data.push_back(std::make_shared<EkAurClass>(54, "Navidha"));
    data.push_back(std::make_shared<EkAurClass>(8534, "Ayush"));

    std::priority_queue<std::shared_ptr<EkAurClass>, std::vector<std::shared_ptr<EkAurClass>>, decltype(lambdaFun)> pqq(data.begin(), data.end(), lambdaFun);
    
    std::priority_queue<std::shared_ptr<EkAurClass>, std::vector<std::shared_ptr<EkAurClass>>, bool(std::shared_ptr<EkAurClass>, std::shared_ptr<EkAurClass>)> prio2(data.begin(), data.end(), chekcPrice); 

    while(!pqq.empty())
    {
        std::cout<<*pqq.top()<<"\n";
        pqq.pop();
    }

    std::priority_queue<EkAurClass *, std::vector<EkAurClass *>, decltype(Comparator)> pq(vec.begin(), vec.end(), Comparator);

    while (!pq.empty())
    {
        std::cout << *pq.top() << std::endl;
        pq.pop();
    }
    struct comp a;
    std::priority_queue<EkAurClass *, std::vector<EkAurClass *>, comp> pq2(vec.begin(), vec.end());

    while (!pq2.empty())
    {
        std::cout << *pq2.top() << std::endl;
        pq2.pop();
    }

    std::priority_queue<EkAurClass *, std::vector<EkAurClass *>, std::function<bool(const EkAurClass *, const EkAurClass *)>> pq3(vec.begin(), vec.end(), Less_Comparison);

    while (!pq3.empty())
    {
        std::cout << *pq3.top() << std::endl;
        pq3.pop();
    }

    return 0;
}