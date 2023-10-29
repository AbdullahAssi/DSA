#include <iostream>
#include <stack>
using namespace std;

class StackOperations {
    stack<int> numbersStack;

public:
    void pushValue(int value) {
        numbersStack.push(value);
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    void popValue() {
        if (!numbersStack.empty()) {
            cout << "Popped " << numbersStack.top() << " from the stack." << endl;
            numbersStack.pop();
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    bool isEmpty() {
        return numbersStack.empty();
    }

    int getSize() {
        return numbersStack.size();
    }

    void displayStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            stack<int> tempStack = numbersStack;
            cout << "Stack elements from top to bottom: ";
            while (!tempStack.empty()) {
                cout << tempStack.top() << " ";
                tempStack.pop();
            }
            cout << endl;
        }
    }
};

int main() {
    StackOperations stackOps;
    stackOps.pushValue(23);
    stackOps.pushValue(45);
    stackOps.pushValue(44);
    stackOps.popValue();
    stackOps.popValue();
    cout << "Stack size: " << stackOps.getSize() << endl;
    stackOps.displayStack();

    return 0;
}
