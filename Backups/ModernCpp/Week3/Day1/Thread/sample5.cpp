#include <iostream>
#include <mutex>
#include <thread>
#include <functional>

/*
    One object of this calss wll be responsible for connection mechanism to the bank
*/

class BankingOperations;
using OperationPointer = std::shared_ptr<BankingOperations>;

class BankingOperations
{

private:
    int _amount{0};
    std::mutex mt;
    static OperationPointer _solo_hero_object;
    BankingOperations(int amount) : _amount{amount} {}
public:
    BankingOperations() = delete;
    BankingOperations(const BankingOperations &) = delete;
    BankingOperations &operator=(const BankingOperations &) = delete;
    BankingOperations(BankingOperations &&) = delete;
    BankingOperations &operator=(BankingOperations &&) = delete;
    ~BankingOperations() = default;

    void withdraw()
    {
        for (int i = 0; i < 100; i++)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            std::lock_guard<std::mutex> lk(mt); // Isme unlock nahi krna padta hai apne aap ho jaata hai     destructor mai jaake. Isko RAII bolte hai Resource Accusation Is Initialization
            _amount -= 10;
        }
    }

    void deposit()
    {
        for (int i = 0; i < 100; i++)
        {
            std::lock_guard<std::mutex> lk(mt);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            _amount += 10;
        }
    }

    static OperationPointer getFirstInstance(int amount){
        if(_solo_hero_object){
            return _solo_hero_object;
        }
        else{
            _solo_hero_object.reset(new BankingOperations(amount));
            return _solo_hero_object;
        }
    }

    int amount() const { return _amount; }
};

OperationPointer BankingOperations::_solo_hero_object {nullptr};

int main()
{
    OperationPointer b1 = BankingOperations::getFirstInstance(1000); // Value initialization using {}
    // std::shared_ptr<BankingOperations> b2 = BankingOperations::getFirstInstance(100); // Value initialization using {}

    std::thread arr[2] = {
        std::thread(&BankingOperations::withdraw, b1),
        std::thread(&BankingOperations::deposit, b1)
    };

    // auto f1 = std::bind(&BankingOperations::withdraw, b1);
    // auto f2 = std::bind(&BankingOperations::deposit, b1);

    // std::array<std::thread, 2> arr{
    //     std::thread(f1),
    //     std::thread(f2)
    // };

    try
    {
        for (std::thread &t : arr)
        {
            // Before joinig the thread please check wherther it is joinable or not
            // JOining the thread more then once it will give undefined behaviour
            if (t.joinable()) // Checks current thread ko phele join kiya hai ki nahi agar true mtlb kr do join nahi to nahi kro
                t.join();
            else
            {
                throw std::runtime_error("Thread cannot be joinable");
            }
        }
    }
    catch (std::runtime_error &e){
        std::cout<<e.what()<<std::endl;
    }
    std::cout << "Final amount is: " << b1->amount() << std::endl;
}