/*  
    In sample 1 you were running the program in single to make this in multiple thread

    Program Starts
                                                        --------------------------->Cube Ends
                                                        |                             |
                                                        |                             |
                                                        |                             |
    --------------->Square()                            ^----------->Cube starts       ------program ends    
                    |                                   |
                    |                                   |
                    |                                   |
                    ------------------------------------>Square ends

*/

/*
    In sample 2 diagram

                        -----------------Square starts------------------
                        /                                                \       
                      /                                                   \  
                    /                                                      \
    ------------>starts                                                     Ends
                    \                                                     /
                     \                                                  /
                      \                                               /
                      -------------------Cube Starts -----------------  
*/



//g++ sample2.cpp -lpthread -o sample2 && time ./sample2 Command to run
//If no join -> runtime exception
#include <iostream>
#include <array>
#include <thread>
#include <mutex>

std::mutex mt; // Mutex is a binary semaphore

void Square(std::array<int,5>& number){
    for(int num : number)
    {
        // 1 second artificial delay
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mt.lock();
        std::cout<<"Square of "<<num<<" is: "<<num*num<<std::endl;
        mt.unlock();
    }
}


void Cube(std::array<int,5>& number){
    for(int num : number)
    {
        // 1 second artificial delay
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mt.lock();
        std::cout<<"Cube of "<<num<<" is: "<<num*num*num<<std::endl;
        mt.unlock();
    }
}

int main(){

    //Main thread starts and creats an array in local stack memory
    std::array<int,5> data{1,2,3,4,5};

    //We launch a new Thread(mini program)
    // T1 object is a handle for me to interact with the thread in some one. This t1 is attached to square mini program.
    // We have also passed "data" by referece which is required by the square function 
    std::thread t1(&Square, std::ref(data));

    //This t2 is attached to cube mini program.
    // We have also passed "data" by referece which is required by the cube function 
    std::thread t2(&Cube, std::ref(data));

    //Signal as a result
    //Join -> wait for a thread
    //merging all the threads
    t1.join(); //Main will not proceed to the next line until t1 is finished
    t2.join(); //Main will not proceed to the next line unlit t2 is finished

    //T1 and T2 phele hi start ho gya hai bs hum niche uska join ka wait krre hai

    std::cout<<"GoodBye\n";
}

//Thread is a mini program. Stat thread means starting a new mini program
//Once you create a thread since you start new program you technically loose control over your program
//You make thread for faster output and better execution but can't control 

/*
    While writing the join the scnerious are
        1) T1.join() t1 crashes signal is sent
        2) t1 does finish even before t2 starts
        3) t2 does finish even before t1 join started
*/