#ifndef SizeNotMatched_H
#define SizeNotMatched_H

#include<stdexcept>
#include<cstring>

class SizeNotMatched : public std::exception
{
private:
    char* _msg;
public:
    SizeNotMatched(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    SizeNotMatched() = delete;
    SizeNotMatched(const SizeNotMatched&) = delete;
    SizeNotMatched(SizeNotMatched&&) = default;
    SizeNotMatched& operator = (const SizeNotMatched&) = delete;
    SizeNotMatched&& operator = (SizeNotMatched&&) = delete;
    // ~SizeNotMatched() = default;
    ~SizeNotMatched() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // SizeNotMatched_H
