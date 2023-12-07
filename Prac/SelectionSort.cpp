#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int myArray[] = {64, 25, 12, 22, 11};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    selectionSort(myArray, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " ";
    }

    return 0;
}