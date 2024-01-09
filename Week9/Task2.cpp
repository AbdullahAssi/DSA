#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node from the end of the linked list
void deleteNode(Node** head) {
    if (*head == nullptr) {
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        *head = nullptr;
    }
    delete temp;
}

// Function to display the linked list in reverse order
void displayReverse(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Function to search for an element in the linked list
bool searchElement(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node* head = nullptr;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(&head, data);
    }

    cout << "Doubly linked list: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Doubly linked list in reverse order: ";
    displayReverse(head);

    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    if (searchElement(head, key)) {
        cout << "Element found in the linked list." << endl;
    } else {
        cout << "Element not found in the linked list." << endl;
    }


    deleteNode(&head);
    cout << "Doubly linked list after deleting the last node: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
