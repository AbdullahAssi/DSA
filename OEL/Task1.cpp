
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
    // Building max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);

    // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

// Printing an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) {
            cout << " , ";
        }
    }
}

int main() {
    int size;
    cout<<"Enter size of array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter elements of array in integer."<<endl;
    for(int i=0; i<size; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }

    //calculate size of array
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Original Array: [";
    printArray(arr, n);
    cout<<"]"<<endl;

    // Calling function heapSort()
    heapSort(arr, n);

    cout <<"Sorted array: [";
    printArray(arr, n);
    cout<<"]";
}