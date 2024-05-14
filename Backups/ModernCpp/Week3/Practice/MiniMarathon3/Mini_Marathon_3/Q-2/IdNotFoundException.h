#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <future> 
#include <cstring>

class IdNotFoundException : public std::future_error
{
private:
    char* _msg;
public:
    IdNotFoundException()=delete;                   // Default Constructor disabled
    IdNotFoundException(const IdNotFoundException&)=delete;              // Copy constructor disabled

    IdNotFoundException(IdNotFoundException&&)=default;                   // Move Constructor disabled

    IdNotFoundException& operator=(const IdNotFoundException&)=delete;         // Copy Assignment Operator diabled
    IdNotFoundException& operator=(IdNotFoundException&&)=delete;       // Move Assignment Operator disabled

    IdNotFoundException(const char* msg, std::future_errc ec)
    :std::future_error(ec) {    
        _msg=new char[strlen(msg)+1];         
        strcpy(_msg, msg);
    }

    ~IdNotFoundException(){                  // Destructor
        delete _msg;
    }
    

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // IDNOTFOUNDEXCEPTION_H
