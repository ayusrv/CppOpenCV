#ifndef NoOddFound_H
#define NoOddFound_H

#include<stdexcept>
#include<cstring>

class NoOddFound : public std::exception
{
private:
    char* _msg;
public:
    NoOddFound(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    NoOddFound() = delete;
    NoOddFound(const NoOddFound&) = delete;
    NoOddFound(NoOddFound&&) = default;
    NoOddFound& operator = (const NoOddFound&) = delete;
    NoOddFound&& operator = (NoOddFound&&) = delete;
    // ~NoOddFound() = default;
    ~NoOddFound() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // NoOddFound_H
