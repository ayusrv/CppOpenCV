#ifndef NullPointerException_H
#define NullPointerException_H

#include<stdexcept>
#include<cstring>

class NullPointerException : public std::exception
{
private:
    char* _msg;
public:
    NullPointerException(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    NullPointerException() = delete;
    NullPointerException(const NullPointerException&) = delete;
    NullPointerException(NullPointerException&&) = default;
    NullPointerException& operator = (const NullPointerException&) = delete;
    NullPointerException&& operator = (NullPointerException&&) = delete;
    // ~NullPointerException() = default;
    ~NullPointerException() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // NullPointerException_H
