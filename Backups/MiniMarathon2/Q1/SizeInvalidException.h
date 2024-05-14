#ifndef SizeInvalidException_H
#define SizeInvalidException_H

#include<stdexcept>
#include<cstring>

class SizeInvalidException : public std::exception
{
private:
    char* _msg;
public:
    SizeInvalidException(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    SizeInvalidException() = delete;
    SizeInvalidException(const SizeInvalidException&) = delete;
    SizeInvalidException(SizeInvalidException&&) = default;
    SizeInvalidException& operator = (const SizeInvalidException&) = delete;
    SizeInvalidException&& operator = (SizeInvalidException&&) = delete;
    // ~SizeInvalidException() = default;
    ~SizeInvalidException() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // SizeInvalidException_H
