#include <iostream>
using namespace std;

class Area {
private:
    int l;
    int b;

public:
    void setDim(int length, int breadth) {
        l = length;
        b = breadth;
    }

    int getArea() {
        return 0.5*l * b;
    }
};

int main() {
    cout << "Task No 2" << endl;

    int length, breadth;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter breadth: ";
    cin >> breadth;

    Area obj1;
    obj1.setDim(length, breadth);
    cout << "Area is: " << obj1.getArea() << endl;

    return 0;
}