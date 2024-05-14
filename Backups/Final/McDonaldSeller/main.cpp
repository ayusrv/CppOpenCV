#include "item.cpp"
#include<bits/stdc++.h>
using namespace std;

int main(){
    item it;
    it.sellItem();
}


#include <iostream>

class ArithmeticExample {
private:
    int value;

public:
    // Constructor
    ArithmeticExample(int val) : value(val) {}

    // Getter
    int getValue() const {
        return value;
    }

    // Overloading addition operator
    ArithmeticExample operator+(const ArithmeticExample& other) const {
        return ArithmeticExample(value + other.value);
    }

    // Overloading subtraction operator
    ArithmeticExample operator-(const ArithmeticExample& other) const {
        return ArithmeticExample(value - other.value);
    }

    // Overloading multiplication operator
    ArithmeticExample operator*(const ArithmeticExample& other) const {
        return ArithmeticExample(value * other.value);
    }

    // Overloading division operator
    ArithmeticExample operator/(const ArithmeticExample& other) const {
        if (other.value != 0) {
            return ArithmeticExample(value / other.value);
        } else {
            std::cerr << "Error: Division by zero!" << std::endl;
            return ArithmeticExample(0);
        }
    }

    // Overloading unary minus operator
    ArithmeticExample operator-() const {
        return ArithmeticExample(-value);
    }

    // Overloading increment operator (prefix)
    ArithmeticExample& operator++() {
        ++value;
        return *this;
    }

    // Overloading increment operator (postfix)
    ArithmeticExample operator++(int) {
        ArithmeticExample temp(value);
        ++value;
        return temp;
    }

    // Overloading equality operator
    bool operator==(const ArithmeticExample& other) const {
        return value == other.value;
    }

    // Overloading not equal operator
    bool operator!=(const ArithmeticExample& other) const {
        return value != other.value;
    }

    // Display function
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    ArithmeticExample a(10);
    ArithmeticExample b(5);

    // Addition
    ArithmeticExample resultAdd = a + b;
    resultAdd.display();

    // Subtraction
    ArithmeticExample resultSub = a - b;
    resultSub.display();

    // Multiplication
    ArithmeticExample resultMul = a * b;
    resultMul.display();

    // Division
    ArithmeticExample resultDiv = a / b;
    resultDiv.display();

    // Unary minus
    ArithmeticExample resultUnaryMinus = -a;
    resultUnaryMinus.display();

    // Increment (prefix)
    ++a;
    a.display();

    // Increment (postfix)
    a++;
    a.display();

    // Equality
    if (a == b) {
        std::cout << "a is equal to b" << std::endl;
    } else {
        std::cout << "a is not equal to b" << std::endl;
    }

    // Inequality
    if (a != b) {
        std::cout << "a is not equal to b" << std::endl;
    } else {
        std::cout << "a is equal to b" << std::endl;
    }

    return 0;
}
