#ifndef BillAmountException_H
#define BillAmountException_H

#include<stdexcept>
#include<cstring>

class BillAmountException : public std::exception
{
private:
    char* _msg;
public:
    BillAmountException(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    BillAmountException() = delete;
    BillAmountException(const BillAmountException&) = delete;
    BillAmountException(BillAmountException&&) = default;
    BillAmountException& operator = (const BillAmountException&) = delete;
    BillAmountException&& operator = (BillAmountException&&) = delete;
    // ~BillAmountException() = default;
    ~BillAmountException() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // BillAmountException_H
