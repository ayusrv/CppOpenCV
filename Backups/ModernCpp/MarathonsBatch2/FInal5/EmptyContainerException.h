#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <cstring>
#include <future>

class EmptyContainerException : std::future_error
{
private:
    char* _msg;
public:
    EmptyContainerException()=default;
    EmptyContainerException(const EmptyContainerException &)=delete;
    EmptyContainerException(EmptyContainerException && )=delete;
    EmptyContainerException & operator=(const EmptyContainerException & )=delete;
    EmptyContainerException &operator=(EmptyContainerException &&)=delete;
    ~EmptyContainerException()=default;
    EmptyContainerException(const char* msg, std::future_errc ec) : std::future_error(ec)
    {
        _msg = new char(strlen(msg) + 1);
        strcpy(_msg, msg);
    }
    virtual const char*
    what() const noexcept override{
        return _msg;
    }
};

#endif // EMPTYCONTAINEREXCEPTION_H
