#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <stdexcept>   
#include <cstring>

class EmptyContainerException : public std::exception
{
private:
    char* _msg;
public:
    EmptyContainerException()=delete;                   // Default Constructor disabled
    EmptyContainerException(const EmptyContainerException&)=delete;              // Copy constructor disabled

    EmptyContainerException(EmptyContainerException&&)=default;                   // Move Constructor disabled

    EmptyContainerException& operator=(const EmptyContainerException&)=delete;         // Copy Assignment Operator diabled
    EmptyContainerException& operator=(EmptyContainerException&&)=delete;       // Move Assignment Operator disabled

    EmptyContainerException(const char* msg) {    
        _msg=new char[strlen(msg)+1];             
        strcpy(_msg, msg);
    }

    ~EmptyContainerException(){                  // Destructor
        delete _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H
