#include <iostream>
using namespace std;

class Stack {
private:
    struct node {
        int data;
        node* next;
    };

    node* top;

public:
    Stack() : top(nullptr) {}

    void Push(int newelement) {
        node* newptr = new node;
        newptr->data = newelement;
        newptr->next = top;
        top = newptr;
    }

    void Pop(int& returnvalue) {
        if (IsEmpty()) {
            cout << "Underflow error" << endl;
            return;
        }

        node* tempptr = top;
        returnvalue = top->data;
        top = top->next;
        delete tempptr;
    }

    bool IsEmpty() const {
        return top == nullptr;
    }
};

int main() {
    // Example usage of the Stack class
    Stack myStack;
    myStack.Push(10);
    myStack.Push(20);

    int poppedValue;
    myStack.Pop(poppedValue);
    cout << "Popped value: " << poppedValue << endl;
    myStack.Pop(poppedValue);
    cout << "Popped value: " << poppedValue << endl;

    return 0;
}