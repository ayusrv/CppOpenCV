#ifndef TyrePressureExceeds_H
#define TyrePressureExceeds_H

#include<stdexcept>
#include<cstring>

class TyrePressureExceeds : public std::exception
{
private:
    char* _msg;
public:
    TyrePressureExceeds(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    TyrePressureExceeds() = delete;
    TyrePressureExceeds(const TyrePressureExceeds&) = delete;
    TyrePressureExceeds(TyrePressureExceeds&&) = default;
    TyrePressureExceeds& operator = (const TyrePressureExceeds&) = delete;
    TyrePressureExceeds&& operator = (TyrePressureExceeds&&) = delete;
    // ~TyrePressureExceeds() = default;
    ~TyrePressureExceeds() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // TyrePressureExceeds_H
