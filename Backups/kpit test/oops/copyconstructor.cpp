#include <iostream>

class ConstructorExample {
private:
    int data;

public:
    // Default Constructor
    ConstructorExample() : data(0) {
        std::cout << "Default Constructor" << std::endl;
    }

    // Parameterized Constructor
    ConstructorExample(int value) : data(value) {
        std::cout << "Parameterized Constructor with value: " << value << std::endl;
    }

    // Copy Constructor
    ConstructorExample(const ConstructorExample& other) : data(other.data) {
        std::cout << "Copy Constructor" << std::endl;
    }

    // Destructor
    ~ConstructorExample() {
        std::cout << "Destructor" << std::endl;
    }

    void display() {
        std::cout << "Data: " << data << std::endl;
    }
};

int main() {
    // Default Constructor
    ConstructorExample obj1;

    // Parameterized Constructor
    ConstructorExample obj2(42);

    // Copy Constructor
    ConstructorExample obj3 = obj2;

    // Displaying values
    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}