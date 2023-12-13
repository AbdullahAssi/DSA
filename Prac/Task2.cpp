#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    int matrix[n][m];

    // Inputting the elements of the matrix
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    // Displaying the entire matrix
    cout << "The 2D array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Displaying the diagonal values of the matrix
    cout << "The diagonal values of the 2D array:" << endl;
    for (int i = 0; i < min(n, m); i++) {
        cout << matrix[i][i] << " ";
    }
    cout << endl;

    return 0;
}