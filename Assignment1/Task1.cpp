#include <iostream>
using namespace std;

int main() {
    double amount, taxPercent, salesTax;

    cout << "Enter the amount: ";
    cin >> amount;

    cout << "Enter the tax percent: ";
    cin >> taxPercent;

    salesTax = amount * (taxPercent / 100);

    cout << "The sales tax is: " << salesTax << endl;

    return 0;
}