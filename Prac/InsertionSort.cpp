#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;  
        int current = arr[i];
        while (arr[j] > current && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

int main() {
    int myArray[] = { 64, 25, 12, 22, 11 };
    int size = sizeof(myArray) / sizeof(myArray[0]);

    insertionSort(myArray, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }

    return 0;
}