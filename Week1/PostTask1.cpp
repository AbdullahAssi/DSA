#include <iostream>
using namespace std;

int main() {
    int num, positive = 0, negative = 0, even = 0, odd = 0, zero = 0;

    for (int i = 0; i < 20; i++) {
        cout << "Enter an Integer " << i + 1 << " : ";
        cin >> num;

        if (num < 0) {
            negative++;
        } else if (num > 0) {
            positive++;
        } else {
            zero++;
        }

        if (num % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    cout << "Positive Numbers Entered: " << positive << endl;
    cout << "Negative Numbers Entered: " << negative << endl;
    cout << "Zero Entered: " << zero << endl;
    cout << "Even Numbers Entered: " << even << endl;
    cout << "Odd Numbers Entered: " << odd << endl;

    return 0;
}
