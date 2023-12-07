#include <iostream>

using namespace std;

class Node {
public:
    double data;
    Node* next;

    Node(double value) : data(value), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    // Function to insert a node at the beginning
    Node* InsertNodeAtBeginning(double x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        return newNode;
    }

    // Function to insert a node at the middle
    Node* InsertNodeAtMiddle(int index, double x) {
        if (index < 0) {
            return nullptr;
        }

        Node* newNode = new Node(x);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* currNode = head;
            newNode->next = currNode->next;
            currNode->next = newNode;
        }

        return newNode;
    }

    // Function to insert a node at the end
    Node* InsertNodeAtEnd(double x) {
        Node* newNode = new Node(x);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        return newNode;
    }

    // Function to display the linked list
    void Display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to find a node by value and return its index (1-based)
    int FindNode(double x) {
        Node* currNode = head;
        int currIndex = 1;
        while (currNode && currNode->data != x) {
            currNode = currNode->next;
            currIndex++;
        }
        if (currNode) return currIndex;
        return 0;
    }
};

int main() {
    List myList;

    myList.InsertNodeAtEnd(1.1);
    myList.InsertNodeAtEnd(2.2);
    myList.InsertNodeAtEnd(3.3);

    cout << "Original Linked List: ";
    myList.Display();

    myList.InsertNodeAtBeginning(0.0);
    cout << "Linked List after insertion at the beginning: ";
    myList.Display();

    myList.InsertNodeAtMiddle(2, 1.5);
    cout << "Linked List after insertion at index 2: ";
    myList.Display();

    myList.InsertNodeAtEnd(4.4);
    cout << "Linked List after insertion at the end: ";
    myList.Display();

    // Find a node with value 2.2 and print its index
    double valueToFind = 2.2;
    int foundIndex = myList.FindNode(valueToFind);
    cout << "Index of node with value " << valueToFind << ": " << foundIndex << endl;

    return 0;
}