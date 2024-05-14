#ifndef EnumNotFound_H
#define EnumNotFound_H

#include<stdexcept>
#include<cstring>

class EnumNotFound : public std::exception
{
private:
    char* _msg;
public:
    EnumNotFound(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    EnumNotFound() = delete;
    EnumNotFound(const EnumNotFound&) = delete;
    EnumNotFound(EnumNotFound&&) = default;
    EnumNotFound& operator = (const EnumNotFound&) = delete;
    EnumNotFound&& operator = (EnumNotFound&&) = delete;
    // ~EnumNotFound() = default;
    ~EnumNotFound() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // EnumNotFound_H
