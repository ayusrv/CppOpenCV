#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H
// #include<stdexcept>
#include <future>
#include<cstring>
#include <ostream>
class EmptyContainerException :public std::future_error
{
private:
    char * _msg;
    
    // friend class std::future_error;

    // Private constructor used by std::future_error

public:
    
    EmptyContainerException(std::future_errc ec, const char* msg)
        : std::future_error(ec) { 
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg); // Copy the message into _msg
    }
    EmptyContainerException() =delete;
    EmptyContainerException (const EmptyContainerException &) =delete;                  //(delete -> disabled copy constructor )
    EmptyContainerException(EmptyContainerException &&)=default;                         //brand new
    EmptyContainerException &operator=(const EmptyContainerException&)=delete;          //deleted copy assignment
    EmptyContainerException && operator=(EmptyContainerException&&)=delete;  
    ~EmptyContainerException() {
        delete [] _msg;
    }


    virtual const char * what() const noexcept override{
        return _msg;
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H
