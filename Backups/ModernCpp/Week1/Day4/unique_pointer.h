#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

template <typename T>
class unique_pointer
{
private:
    T* _mptr;

public:
    unique_pointer(T* ptr) : _mptr{ptr} {
        ptr = nullptr; //user pointer ko null kr do jisse 2 copy na bn jaaye user wala ko ider copy kiye or user wala ko delete kr diye
    }

    unique_pointer(const T*&) = delete;
    unique_pointer(const T*&&) = delete;
    unique_pointer operator = (const T*&) = default;
    unique_pointer& operator = (T*&&) = default;

    void Release() {delete _mptr; _mptr=nullptr;}
    ~unique_pointer() {delete _mptr; _mptr=nullptr;}
    
};

#endif // UNIQUE_POINTER_H
