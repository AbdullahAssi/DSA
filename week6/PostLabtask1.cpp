#include <iostream>
using namespace std;

bool compare_strings_by_length(const string& str1, const string& str2) {
    return str1.length() < str2.length();
}

void print_string(const string& str) {
    cout << "Your entered string is: " << str << endl;
}

int main() {
    string str1;
    cout << "Enter a string: ";
    getline(cin, str1);

    string str2;
    cout << "Enter another string: ";
    getline(cin, str2);

    if (compare_strings_by_length(str1, str2)) {
        cout << "The first string is shorter than the second string." << endl;
    } else {
        cout << "The first string is longer than or equal to the second string." << endl;
    }

    print_string(str1);
    print_string(str2);

    return 0;
}
