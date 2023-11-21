#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ",";
        }
    }
}

int main() {
    int  size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    for(int i = 0; i < size; i++) {
        cout << "Enter the element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: [ ";
    printArray(arr, n);
    cout << " ] " << endl;
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: [ ";
    printArray(arr, n);
    cout << " ] " << endl;

    return 0;
}
