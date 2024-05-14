#include <iostream>
#include <functional>
#include <thread>
#include <mutex>

std::mutex mt;
class Car
{
private:
    // std::mutex mt;
    int _wheels;
    std::string _id;
    int _seater;

    static Car *_object;

    Car(int wheels, std::string id, int seater)
    {
        _wheels = wheels;
        _id = id;
        _seater = seater;
    }

    Car() = delete;
    Car(const Car &) = delete;
    Car(const Car &&) = delete;

public:
    static Car *getInstace(int wheels, std::string id, int seater)
    {
        std::lock_guard<std::mutex> lg(mt);
        if (_object)
        {
            return _object;
        }
        else
        {
            _object = new Car(wheels, id, seater);
            return _object;
        }
    }

    int wheels() const { return _wheels; }
    void setWheels(int wheels) { _wheels = wheels; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    int seater() const { return _seater; }
    void setSeater(int seater) { _seater = seater; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs)
    {
        os << "_wheels: " << rhs._wheels
           << " _id: " << rhs._id
           << " _seater: " << rhs._seater;
        return os;
    }
};

Car *Car::_object{nullptr};

void fun1()
{
    Car *obj1 = Car::getInstace(1, "101", 1);

    std::cout << *obj1 << std::endl;
}
void fun2()
{
    Car *obj2 = Car::getInstace(2, "202", 2);
    std::cout << *obj2 << std::endl;
}

int main()
{
    // Car* c = new Car(4, "123", 4);
    // Car *c = Car::getInstace(4, "123", 4);
    // std::cout << c->wheels() << " " << c->id() << " " << c->seater() << std::endl;
    // Car *c2 = Car::getInstace(6, "1263", 8);
    // std::cout << c2->wheels() << " " << c2->id() << " " << c2->seater() << std::endl;
    std::thread f1 = std::thread(&fun1);
    std::thread f2 = std::thread(&fun2);
    f1.join();
    f2.join();

    Car *c = Car::getInstace(4, "123", 4);
    std::cout << *c << "\n";
}

/*
        ADDED
            private -> static ClassName* _object -> (ye batayega ki object phele se created hai ki nahi hai)
            public -> static ClassName* getInstance(saara parameterized constructor ka values ko pass krna hai yaha pe) -> ye check krega phele se agar object bana hua hai to naya nahi bnaayega or direct return kr dega object ko nahi bana hua hai to kyuki ye private memeber ko call kr skta hai class ka member function, ye parameterized constructor ko call kr dega ClassName ka or data ko assign kr ke object ko return kr dega
            assign kr do _object ko nullptr se class k bahar
            ClassName* ClassName::_object{nullptr};

        CHANGED
            make all the constructors in the private section instead of public
            instead of making the ClassName* c = new ClassName call the getInstance because constructors are private so new thing will be ClassName* c = ClassName::getInstance(saara values ko pass kr do);

*/