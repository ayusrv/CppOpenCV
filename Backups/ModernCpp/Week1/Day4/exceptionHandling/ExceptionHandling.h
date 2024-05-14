#ifndef EXCEPTIONHANDLING_H
#define EXCEPTIONHANDLING_H

#include <iostream>
#include <stdexcept>
#include <cstring>
class ExceptionHandling : public std::exception
{
private:    
    char* message;   
public:
    // ExceptionHandling(/* args */) {}
    // ~ExceptionHandling() {}
    ExceptionHandling(const char* msg){
        message = new char[strlen(msg) + 1];
        strcpy(message,msg);
    }

    ~ExceptionHandling(){
        delete[] message;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return message;
    }
};  
    
#endif // EXCEPTIONHANDLING_H
