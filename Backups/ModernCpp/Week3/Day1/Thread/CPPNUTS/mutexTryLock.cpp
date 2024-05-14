/*
    Types of mutex
        1) std::try_lock
        2) std::mutex::try_lock
        3) std::shared_lock::try_lock
        4) std::timed_mutex::try_lock
        5) std::unique_lock::try::lock
        6) std::shared_mutex::try_lock
        7) std::recursive_mutex::try_lock 
        8) std::shared_time_mutex::try_lock
        9) std::recursuve_time_mutex::try_lock
*/ 

//std::mutex mt.lock() -> this is basically blocking the lock
//std::mutex mt.try_lock() -> this is basically unlocking the lock

/*
    Try lock -> the main use is that it ca try to lock mutliple mutex at the same time
        
        1) try_lock() Tries to lock the mutex. Return immediately. on successful lock acquisition return true otherwise false.
        
        2) If try_lock() is not able to lock the mutex, then it doesn't get blocked that's why it is called non-blovking()
        
        3) If try_lock() again called by the mutex which owns the mutex, the behaviour is undefined. It is a deadlock situation with undefined behaviour. (If you want to lock the same mutex by same thread more than one time then go for the recursive_lock() )

        4) try_lock tries to lock all the lockable objects passed in it one by one in the given order.       SYNTAX-> std::try_lock(m1,m2,m3,...mn);

        5) On the success of 4th line it will return -1 otherwise it will return 0 based mutex index number which it could not lock. If it fails to lock the mutex then it will released all the mutex that has been locked before
*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mt;
int counter=0;
int thread1=0;
int thread2=0;

void increaseCounter(){
    for(int i=0;i<1000000;i++){
        if(mt.try_lock()){
            ++counter;
            mt.unlock();
        }else{
            ++thread2;
        }
    }
}

int main(){
    std::thread t1(increaseCounter);
    std::thread t2(increaseCounter);
    t1.join();
    t2.join();
    std::cout<<"Counter could increase upto: "<<counter<<std::endl;
    std::cout<<"T1 took "<<thread2<<" times to complete the iteration"<<std::endl;
    std::cout<<"T2 started after "<<counter - thread2<<" iterations already finished"<<std::endl;

    return 0;
}

//This will print the different answers each time because jub t1 lock kiya hua tha tub t2 v aa gya and then t1 apna counter badha raha tha i=0 -> 1000000 tk tub t2 v badhna chalu ho gya bs wo counter ko access nahi kr paaya to false return kr ke else mai chala gya aab agar t1 ko krne 2 sec lagra hai ye kaam or t2 jo hai wo 2 second mai i=0 se i=50000 tk chala gya hai to aab i=50000 se i<1000000 tk jayeaga jisse answer mai 20 lakh k jagha 10lakh + t1 jub khatm hua or t2 kidher payuncha tha uspe depend krega 

