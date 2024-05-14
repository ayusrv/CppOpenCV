#include <iostream>
#include <memory>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <future>

//Shared pointer
class Singleton
{
private:
    std::mutex mt;
    std::condition_variable cv;
    bool flag= false;
    static std::shared_ptr<Singleton> _object;
    int **arr;
    Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton &operator=(Singleton &&) = delete;

public:
    ~Singleton()
    {
        for (int i = 0; i < 3; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    static std::shared_ptr<Singleton> getInstance()
    {
        if (_object)
        {
            return _object;
        }
        else
        {
            _object.reset(new Singleton());
            return _object;
        }
    }

    void memoryAllocator()
    {
        std::cout << "ENter the values: ";
        arr = new int *[3];
        for (int i = 0; i < 3; i++)
        {
            arr[i] = new int[3];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cin >> arr[i][j];
            }
        }
        std::cout << "\n";
        flag = true;
        cv.notify_all();
    }

    void memoryDisplay()
    {
        std::unique_lock<std::mutex> ul(mt);
        cv.wait(ul, [&](){return flag;});
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

std::shared_ptr<Singleton> Singleton::_object{nullptr};

//UNique Pointer
class UniqueSingleton{
    private:
    std::mutex mt;
    std::condition_variable cv;
    bool flag= false;
    static UniqueSingleton _object;
    int **arr;
    UniqueSingleton() = default;
    UniqueSingleton(const UniqueSingleton &) = delete;
    UniqueSingleton(UniqueSingleton &&) = delete;
    UniqueSingleton &operator=(const UniqueSingleton &) = delete;
    UniqueSingleton &operator=(UniqueSingleton &&) = delete;

public:
    ~UniqueSingleton()
    {
        for (int i = 0; i < 3; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    static UniqueSingleton& getInstance()
    {
        return _object;
    }

    void memoryAllocator()
    {
        std::cout << "ENter the values: ";
        arr = new int *[3];
        for (int i = 0; i < 3; i++)
        {
            arr[i] = new int[3];
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cin >> arr[i][j];
            }
        }
        std::cout << "\n";
        flag = true;
        cv.notify_all();
    }

    void memoryDisplay()
    {
        std::unique_lock<std::mutex> ul(mt);
        cv.wait(ul, [&](){return flag;});
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

UniqueSingleton UniqueSingleton::_object;

int main()
{
    std::shared_ptr<Singleton> ptr = Singleton::getInstance();
    // ptr->memoryAllocator();
    // ptr->memoryDisplay();

    // std::thread t1(&Singleton::memoryAllocator, ptr);
    // t1.join();
    // std::thread t2(&Singleton::memoryDisplay, ptr);
    // t2.join();
    
    std::future<void> f1 = std::async(&Singleton::memoryAllocator, ptr);
    std::future<void> f2 = std::async(&Singleton::memoryDisplay, ptr);
    f1.wait();
    f2.wait();

    std::unique_ptr<UniqueSingleton> ptr2(&UniqueSingleton::getInstance());
    std::future<void> f3 = std::async(&UniqueSingleton::memoryAllocator, ptr2.get());
    std::future<void> f4 = std::async(&UniqueSingleton::memoryDisplay, ptr2.get());
    f1.wait();
    f2.wait();

    ptr2.release();
    
}