#include <iostream>
#include <string>

int main() {
    // Input string
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    // User input for values to delete
    char valueToDelete;
    std::cout << "Enter the specific value to delete from the string: ";
    std::cin >> valueToDelete;

    // Delete specified values from the string
    size_t pos = inputString.find(valueToDelete);
    while (pos != std::string::npos) {
        inputString.erase(pos, 1);  // Erase 1 character at position pos
        pos = inputString.find(valueToDelete, pos);
    }

    // Print the modified string
    std::cout << "Modified string after deleting '" << valueToDelete << "': " << inputString << std::endl;

    return 0;
}
