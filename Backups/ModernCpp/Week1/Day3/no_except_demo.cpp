#include <iostream>

class Dummy{
    private:

    public:
        Dummy() noexcept {}
        void Display() noexcept {std::cout<<"Hello\n"; throw 1;}
};