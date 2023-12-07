#include <iostream>
using namespace std;

bool linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return true; // Element found
        }
    }
    return false; // Element not found
}

int main() {
    const int size = 5;
    int arr[size] = {10, 5, 8, 2, 7};
    int target;

    cout << "Enter the element to search: ";
    cin >> target;

    if (linearSearch(arr, size, target)) {
        cout << "Element found in the array." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}