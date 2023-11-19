#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swaping arr[j] and arr[j+1]
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 1000;
    float arr[size];

    // Initializing the array with random floating-point numbers
    for (int i = 0; i < size; i++) {
        arr[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    }

    // Measuring the execution time
    auto start = high_resolution_clock::now();

    // Sorting the array using bubble sort
    bubbleSort(arr, size);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array:" << endl;
    cout<<" [ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " , ";
    }
    cout<<" ] ";
    cout << endl;

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
