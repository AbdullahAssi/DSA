#include <iostream>
#include <stack>
using namespace std;

class StringReverser {
private:
    stack<char> charStack;

public:
    void pushString(const string& inputString) {
        for (size_t i = 0; i < inputString.length(); i++) {
            char c = inputString[i];
            charStack.push(c);
        }
    }

    string reverseString() {
        string reversedString;
        while (!charStack.empty()) {
            reversedString += charStack.top();
            charStack.pop();
        }
        return reversedString;
    }
};

int main() {
    StringReverser reverser;
    string inputString;

    cout << "Enter a string: ";
    getline(cin, inputString);

    reverser.pushString(inputString);
    string reversedString = reverser.reverseString();

    cout << "Reversed string: " << reversedString << endl;

    return 0;
}
