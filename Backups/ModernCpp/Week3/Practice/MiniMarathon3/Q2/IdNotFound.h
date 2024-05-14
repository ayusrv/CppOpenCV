#ifndef IdNotFound_H
#define IdNotFound_H

#include<stdexcept>
#include<cstring>

class IdNotFound : public std::exception
{
private:
    char* _msg;
public:
    IdNotFound(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    IdNotFound() = delete;
    IdNotFound(const IdNotFound&) = delete;
    IdNotFound(IdNotFound&&) = default;
    IdNotFound& operator = (const IdNotFound&) = delete;
    IdNotFound&& operator = (IdNotFound&&) = delete;
    // ~IdNotFound() = default;
    ~IdNotFound() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // IdNotFound_H
