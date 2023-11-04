
#include <iostream>
#include <string>

using namespace std;

void reverseString(string str) {
    if (str.length() == 0) {
        return;
    }
    else {
        reverseString(str.substr(1));
        cout << str[0];
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Reversed string: ";
    reverseString(str);
    return 0;
}
