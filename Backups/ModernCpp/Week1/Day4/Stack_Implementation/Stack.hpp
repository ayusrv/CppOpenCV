#ifndef STACK_HPP
#define STACK_HPP

#include <list>
#include "StackEmptyException.hpp"
template <typename T>

class Stack{
    private: 
        std::list<T> _data {};
    
    public:

        Stack(){}
        Stack(const Stack&) = delete;
        Stack& operator = (const Stack&) = default;
        Stack& operator = (Stack&&) = default;
        Stack(Stack&&) = default;
        ~Stack() = default;
        void Pop();

        /*
            Push function excepts one item "val" of type T 
            returns void
        */
        void Push(T val);
        bool IsEmpty();
        T Peek();
        size_t Size();
};

#endif // STACK_HPP

/*

                int
    <------------0----------->
    unsigned int
    <0------------------------>
    unsigned long / size_t
        64
      2^ 

*/

template <typename T>
inline void Stack<T>::Pop() //Template class hai issliye class ka name<T> likhte hai
{
    
    if(_data.empty()){
        throw StackEmptyException("Stack is Empty");
    }
    _data.pop_back();
}

template <typename T>
inline void Stack<T>::Push(T val) {_data.push_back(val);}

template <typename T>
inline bool Stack<T>::IsEmpty() {return _data.empty();}

template <typename T>
inline T Stack<T>::Peek()
{
    if(_data.empty()){
        throw StackEmptyException("Stack is Empty");
    }
    return _data.back();
}

template <typename T>
inline size_t Stack<T>::Size() {return _data.size();}



/*

    throw StackEmptyException("Stack is Empty"); //statement
    |
    |
    throw <expression> //2 parts are throw and expression
    |
    |
    throw Constructor call i.e function call
    throw [     _msg = "Data is empty"    ]
           <--------No Name--------------->
           |
           |
    throw rvalue of type STackEmptyException
    [catch table]
*/