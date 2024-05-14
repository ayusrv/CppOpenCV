#include <iostream>
#include <memory>
#include <functional>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>

class ConditionVariable
{
private:
    int _amount {0};
    static ConditionVariable* _solo_hero_object;
    bool flag= false;
    std::mutex mu;
    std::condition_variable cv;
    ConditionVariable()=default;
    ConditionVariable(int amount) {_amount = amount;}
public:
    ConditionVariable(const ConditionVariable &)=delete;
    ConditionVariable(ConditionVariable && )=delete;
    ConditionVariable & operator=(const ConditionVariable & )=delete;
    ConditionVariable &operator=(ConditionVariable &&)=delete;
    ~ConditionVariable()=default;

    static ConditionVariable* getInstance(int val){
        if(_solo_hero_object){
            return _solo_hero_object;
        }else{
            _solo_hero_object = new ConditionVariable(val);
            return _solo_hero_object;
        }
    }

    void operation(){
        int* ptr = (int*)malloc(4);
        std::unique_lock<std::mutex> ul(mu);
        cv.wait(ul, [&](){return flag;});
        *ptr = _amount*_amount;
        std::cout<<"Amount : "<<*ptr<<std::endl;
        free(ptr);
    }

    void input(){
        std::lock_guard<std::mutex> lg(mu);
        std::cin>>_amount;
    }

    void notify(){
        cv.notify_one();
    }

    int amount() const { return _amount; }
    void setAmount(int amount) { _amount = amount; }

    void setFlag(bool flag_) { flag = flag_; }
};

std::function<void(int)> print_v = [](int n){
        std::cout<<n<<", ";
    };

ConditionVariable* ConditionVariable::_solo_hero_object {nullptr};

int main(){
    ConditionVariable* c = ConditionVariable::getInstance(10);
    std::thread t1(&ConditionVariable::operation, c);
    c->input();
    c->setFlag(true);
    c->notify();
    t1.join();


    std::vector<int> v{1,2,3,4,5};
    

    for(int i : v){
        print_v(i);
    }


    return 0;    
}