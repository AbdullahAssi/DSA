#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int matrix[rows][cols], transpose[cols][rows];

    cout << "Enter elements of the matrix: " << endl;
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j) {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> matrix[i][j];
        }

    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }

    cout << "Transpose of Matrix: " << endl;
    for(int i = 0; i < cols; ++i)
        for(int j = 0; j < rows; ++j) {
            cout << transpose[i][j] << "  ";
            if(j == rows - 1)
                cout << endl;
        }

    return 0;
}