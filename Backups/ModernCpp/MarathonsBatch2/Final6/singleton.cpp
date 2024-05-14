#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <vector>
#include <future>
#include <memory>

class singleton
{
private:
    int _data;
    std::string _name;
    static std::unique_ptr<singleton> _solo_hero_object;
    singleton(int data, std::string name) {
        _data = data;
        _name = name;
    } 
public:
    singleton()=delete;
    singleton(const singleton &)=delete;
    singleton(singleton && )=delete;
    singleton & operator=(const singleton & )=delete;
    singleton &operator=(singleton &&)=delete;
    ~singleton()=default;
    static std::unique_ptr<singleton>& getInstance(int data, std::string name)
    {
        if(_solo_hero_object)
        {
            return _solo_hero_object;
        }else{
            _solo_hero_object.reset(new singleton(data, name));
            return _solo_hero_object;
        }
    }

    int sumOfData(std::vector<int> vec)
    {
        int sum=0;
        for(int i : vec)
        {
            sum+=i;
        }
        return sum;
    }

    int data() const { return _data; }

    std::string name() const { return _name; }

};

std::unique_ptr<singleton> singleton::_solo_hero_object {nullptr};

int main()
{
    std::unique_ptr<singleton>& obj = singleton::getInstance(10,"Ayush");
    std::cout<<obj->data()<<" "<<obj->name()<<"\n";
    obj.release();
    std::unique_ptr<singleton>& obj2 = singleton::getInstance(20,"raj");
    std::cout<<obj2->data()<<" "<<obj2->name()<<"\n";
    obj2.release();
    std::vector<int> v{1,2,3,4,5};
    std::future<int> ft = std::async(&singleton::sumOfData, obj.get(), v);
    std::cout<<ft.get()<<"\n";
}

#endif // SINGLETON_H
