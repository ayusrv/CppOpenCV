#ifndef WrongEnumException_H
#define WrongEnumException_H

#include<stdexcept>
#include<cstring>

class WrongEnumException : public std::exception
{
private:
    char* _msg;
public:
    WrongEnumException(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    WrongEnumException() = delete;
    WrongEnumException(const WrongEnumException&) = delete;
    WrongEnumException(WrongEnumException&&) = default;
    WrongEnumException& operator = (const WrongEnumException&) = delete;
    WrongEnumException&& operator = (WrongEnumException&&) = delete;
    // ~WrongEnumException() = default;
    ~WrongEnumException() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // WrongEnumException_H
