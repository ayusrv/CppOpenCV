/*
    std::Threads:
        1) std::threads : They can be used for parallel/concurent tasks. THey need to be joined or detached. They do not catch the return values (this can be used for the void function)

        2) std::condition_variable : In situations where one thread has to wait for an event to happenbecause of some other thread before completing it'sown activity due to other operations such thread may do some work before the event hence are launched simultaniusly

        3) Conatiner of threads: To manage multiple instances of thread efficiently. (map to function, joins, etc)

        4) std::mutex vs std::lock_gaurds vs std::unique_gaurds: std::mutex can be locked and unlocked manually only, std::lock_gaurds -> mutex who completed masters/ scope based or RAII principle. This is so automatic that you can't control where to unlock. Unique_lock - scope based as well as manual unlock

        //synchronization primitive
        
        5) Real life
            Mercedes : Navigation / Music 
            ---> you unlock the doors you start the accessories/ electronic
            ---> MAP
            ---> MUSIC
            MAP thread ko star krne k liye input for the MAP can load surroind data, favourites, emergency alerts [destination] 
*/

//I want to launch a thread that performs taskA and taskB. taskA doesnot depend on input paeameter and taskB wants a parameter we need to launch that wants a parameter evem before without the input parameter

//To do this we have two models std::promise and std::future