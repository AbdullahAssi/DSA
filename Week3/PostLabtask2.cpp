
#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 1) {
        return 1;
    }
    return n + sum(n-1);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Sum of numbers from 1 to " << n << " is " << sum(n) << endl;
    return 0;
}
