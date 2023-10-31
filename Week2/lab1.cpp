#include <iostream>
using namespace std;

class Lab1 { 
    int size;
    int* stackArray;
    int top;
public:
    Lab1() {
        size = 3; 
        stackArray = new int[size];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void Push(int item) {
        if (!isFull()) {
            stackArray[++top] = item;
            cout << "Pushed " << item << " onto the stack." << endl;
        } else {
            cout << "Stack is full. Cannot push " << item << "." << endl;
        }
    }

    void Pop() {
        if (!isEmpty()) {
            cout << "Popped " << stackArray[top] << " from the stack." << endl;
            top--;
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    int Peek() {
        if (!isEmpty()) {
            return stackArray[top];
        } else {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1;
        }
    }
};

int main() {
    Lab1 myStack;
    myStack.Push(1);
    myStack.Push(2);
    myStack.Push(3);
    myStack.Push(4);

    int topElement = myStack.Peek();
    if (topElement != -1) {
        cout << "Peek Function Top element in the stack: " << topElement << endl;
    }

    myStack.Pop();
    myStack.Pop();
    myStack.Pop();
    myStack.Pop();

    return 0;
}
