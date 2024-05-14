#include <iostream>
#include <functional>

void modify(int& x) {
    x *= 2;
}

int main() {
    int value = 10;

    // Pass by reference using std::ref
    std::reference_wrapper<int> ref = std::ref(value);
    modify(ref); // Modify the value indirectly through the reference wrapper

    std::cout << "Value after modification: " << value << std::endl;

    return 0;
}
