#ifndef EXCEPTIONHANDLE_H
#define EXCEPTIONHANDLE_H

#include <iostream>
#include <cstring>
#include <stdexcept>
class ExceptionHandle : public std::exception{
    private: 
        char* _msg;
    public:
        ExceptionHandle() = delete;
        ExceptionHandle(const ExceptionHandle&) = delete;
        ExceptionHandle(ExceptionHandle&&) = default;
        ExceptionHandle& operator = (const ExceptionHandle&) = delete;
        ExceptionHandle& operator = (const ExceptionHandle&&) = delete;
        ExceptionHandle(const char* msg){
            _msg = new char[strlen(msg)+1];
            strcpy(_msg, msg);
        }
        virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
            return _msg;
        }
        ~ExceptionHandle(){
            delete[] _msg;
        }
};

#endif // EXCEPTIONHANDLE_H
