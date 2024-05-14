#ifndef EMPTYCONATINEREXCEPTION_H
#define EMPTYCONATINEREXCEPTION_H

#include <cstring>
#include <stdexcept>

class EmptyConatinerException : public std::exception
{
private:
    char* _msg;
public:
    EmptyConatinerException()=default;
    EmptyConatinerException(const EmptyConatinerException &)=delete;
    EmptyConatinerException(EmptyConatinerException && )=delete;
    EmptyConatinerException & operator=(const EmptyConatinerException & )=delete;
    EmptyConatinerException &operator=(EmptyConatinerException &&)=delete;
    EmptyConatinerException(const char* msg)
    {
        _msg = new char(strlen(msg)+1);
        strcpy(_msg, msg);
    }
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
        return _msg;
    }
    ~EmptyConatinerException(){
        delete[] _msg;
    };
};

#endif // EMPTYCONATINEREXCEPTION_H
