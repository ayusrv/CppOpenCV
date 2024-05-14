#ifndef INVALIDEXCEPTION_H
#define INVALIDEXCEPTION_H

#include <stdexcept>    
#include <cstring>

class InvalidException : public std::exception
{
private:
    char* _msg;
public:
    InvalidException()=delete;                   // Default Constructor disabled
    InvalidException(const InvalidException&)=delete;              // Copy constructor disabled

    InvalidException(InvalidException&&)=default;                   // Move Constructor disabled

    InvalidException& operator=(const InvalidException&)=delete;         // Copy Assignment Operator diabled
    InvalidException& operator=(InvalidException&&)=delete;       // Move Assignment Operator disabled

    InvalidException(const char* msg) {   
        _msg=new char[strlen(msg)+1];            
        strcpy(_msg, msg);
    }

    ~InvalidException(){                  // Destructor
        delete _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // INVALIDEXCEPTION_H
