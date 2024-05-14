#ifndef STACKEMPTYEXCEPTION_HPP
#define STACKEMPTYEXCEPTION_HPP

#include <stdexcept>
#include <cstring>

class StackEmptyException : public std::exception
{
private:
    char* _msg;
public:
    StackEmptyException() = delete;
    explicit StackEmptyException(const char* msg){
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg,msg);
    }
    ~StackEmptyException(){
        delete[] _msg;
    }

    StackEmptyException(const StackEmptyException&) = delete;
    StackEmptyException& operator=(const StackEmptyException&) = delete;
    StackEmptyException& operator = (const StackEmptyException&&) = delete;
    StackEmptyException(const StackEmptyException&&) = delete;

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg;
    }
};

#endif // STACKEMPTYEXCEPTION_HPP


/*

    Pop
    throw stackEMptyEXception("Data is empty")
    [This calls constructor of custom exception class]
    |
    |
    object of type custom exception
    [Stpred ion catch table]

    [<objectname>.what() will return _msg]

*/
