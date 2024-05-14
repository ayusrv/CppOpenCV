/*
    Represent state of "something"!
*/

class TrainingSession{
    /*
        _duration (in hours) : int 
        _number_of_student : unsigned_int
        _trainer_name : string
        _topic : string
        _date : DateTime
    */
};//represent state of one training sesson

class ID{
    /*
        _country : COUNTRY ENUM 
        _year : 24
        _month : 01
        _track : LEVEL (BT, AT) ENUM
        _batchNumber : 01
        _location : Optional(Pune) 
        _track_name : Track
    */
};

class TrainingBatch{
    /*
        _id : ID
        _strength : unsigned int
        _trainer : Trainer -------------------EMPLOYEE
        _pmt_coordinator : Coordinator -------EMPLOYEE
        _schedule : Schedule
        _talents : Container<Talent> types
    */
};

/*

    Pointer ka state of something
        -> Smart Pointers
    Reference ka state representation
        -> reference_wrapper
    Thread (instructions set)
        std::async
    Semaphore ka state
        lock_gaurd
        unique_lock
    Union ka state represent krenge hum
        std::varient
    
*/