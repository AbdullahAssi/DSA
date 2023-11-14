#include <iostream>
using namespace std;

void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -- ;
        }
        arr[j + 1] = key;
    }
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    

    int size;
    cout<<"Enter size of array: ";
    cin>>size;

    float arr[size];

    cout<<"Enter elements of array in float: "<<endl;
    for(int i=0; i<size; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }

    
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    cout<<"Sorted Array: ";
    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}