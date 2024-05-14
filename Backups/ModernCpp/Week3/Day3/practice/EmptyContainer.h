#ifndef EmptyContainer_H
#define EmptyContainer_H

#include<stdexcept>
#include<cstring>

class EmptyContainer : public std::exception
{
private:
    char* _msg;
public:
    EmptyContainer(const char* msg) {
        
        _msg = new char[strlen(msg)+1];
        strcpy(_msg,msg);

    }

    EmptyContainer() = delete;
    EmptyContainer(const EmptyContainer&) = delete;
    EmptyContainer(EmptyContainer&&) = default;
    EmptyContainer& operator = (const EmptyContainer&) = delete;
    EmptyContainer&& operator = (EmptyContainer&&) = delete;
    // ~EmptyContainer() = default;
    ~EmptyContainer() {
        delete[] _msg;
    }

    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override{
        return _msg;
    }
};

#endif // EmptyContainer_H
