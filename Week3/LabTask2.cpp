#include <iostream>
using namespace std;

void sort(int arr[], int n) {
    if (n == 1) return;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    sort(arr, n - 1);
}

int Max(int arr[], int n) {
    if (n == 1) return arr[0];
    int maxNum = Max(arr, n - 1);
    return maxNum > arr[n - 1] ? maxNum : arr[n - 1];
}

int Min(int arr[], int n) {
    if (n == 1) return arr[0];
    int minNum = Min(arr, n - 1);
    return minNum ;
}

int main() {
    int arr[10];
    cout << "Enter an array of 10 numbers" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Enter the element at array index " << i << " : ";
        cin >> arr[i];
    }

    sort(arr, 10);

    cout << "\nThe sorted array in ascending order is: [";
    for (int i = 0; i < 10; i++) {
        cout << " " << arr[i];
    }
    cout << " ]";

    int max = Max(arr, 10);
    cout << "\nThe maximum number in the array is: " << max << endl;

    int min = Min(arr, 10);
    cout << "The minimum number in the array is : " << min << endl;

    return 0;
}
