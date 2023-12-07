#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    // Construct an empty list
    list<int> mylist;

    // Determine whether or not empty
    if (mylist.empty()) {
        cout << "The list is empty." << endl;
    } else {
        cout << "The list is not empty." << endl;
    }

    // Insert an element into the list
    mylist.push_back(42);

    // Traverse (iterate through) the list to Output
    cout << "List elements: ";
    for (const auto& element : mylist) {
        cout << element << " ";
    }
    cout << endl;

    // Modify an element in the list
    mylist.front() = 99;

    // Output modified list
    cout << "Modified list: ";
    for (const auto& element : mylist) {
        cout << element << " ";
    }
    cout << endl;

    // Search for a specific value
    int searchValue = 99;
    auto it = find_if(mylist.begin(), mylist.end(), [searchValue](int val) { return val == searchValue; });
    if (it != mylist.end()) {
        cout << "Found " << searchValue << " in the list." << endl;
    } else {
        cout << searchValue << " not found in the list." << endl;
    }

    // Delete an element from the list
    mylist.pop_back();

    // Copy or save the list
    list<int> copyList = mylist;

    // Rearrange or perform additional operations as needed

    return 0;
}
