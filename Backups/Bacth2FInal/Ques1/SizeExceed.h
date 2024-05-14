#ifndef SIZEEXCEED_H
#define SIZEEXCEED_H

#include <cstring>
#include <stdexcept>

class SizeExceed : public std::exception
{
private:
    char *_msg;

public:
    SizeExceed(const char* msg){
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    SizeExceed(const SizeExceed &) = delete;
    SizeExceed(SizeExceed &&) = delete;
    SizeExceed &operator=(const SizeExceed &) = delete;
    SizeExceed &operator=(SizeExceed &&) = delete;
    ~SizeExceed()
    {
        delete[] _msg;
    };

    virtual const char *
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg;
    }
};

#endif // SIZEEXCEED_H