#include <iostream>
#include <string>
using namespace std;

void merge(string arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i].length() <= R[j].length()) 
        {
            arr[k] = L[i];
            i++;
        } else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(string arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int sets;
    cout << "Enter the Number of Sets : ";
    cin >> sets;
    int q = 1;

    while (sets--) {
        int n;
        cout << "Enter the number of strings in set [" << q << "] : ";
        cin >> n;
        q++;

        string strings[n];

        for (int i = 0; i < n; i++) 
        {
            cout << "Enter String " << i+1 << " : ";
            cin >> strings[i];
        }

        mergeSort(strings, 0, n - 1);

        for (int i = 0; i < n; i++) 
        {
            cout << strings[i] << " ";
        }
        cout << endl << endl;
    }

    return 0;
}