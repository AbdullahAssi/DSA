#include <iostream>

int main() {
    int x = 5;
    int y = 10;

    std::cout << "Before swapping: x = " << x << ", y = " << y << std::endl;

    // Swap values using pointers
    int* Ptr = &x; // Save the address of x in a pointer
    x = y;
    y = *Ptr;      // Assign the value pointed to by tempPtr to y

    std::cout << "After swapping: x = " << x << ", y = " << y << std::endl;

    return 0;
}
