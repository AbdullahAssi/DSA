#include <iostream>
using namespace std;

int main() {
    int years;
    long long minutes, seconds;

    cout << "Enter the number of years: ";
    cin >> years;

    minutes = static_cast<long long>(years) * 365 * 24 * 60;
    seconds = minutes * 60;

    cout << "The number of minutes is: " << minutes << endl;
    cout << "The number of seconds is: " << seconds << endl;

    return 0;
}