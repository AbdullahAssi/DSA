//circular linked list

#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the middle of the linked list
void insertAtMiddle(Node** head, int data) {
    if (*head == nullptr) {
        *head = createNode(data);
        (*head)->next = *head;
    } else {
        Node* newNode = createNode(data);
        Node* slow = *head;
        Node* fast = (*head)->next;

        while (fast != *head && fast->next != *head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        newNode->next = slow->next;
        slow->next = newNode;
    }
}

// Function to delete a node from the middle of the linked list
void deleteFromMiddle(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* slow = *head;
    Node* fast = (*head)->next;
    Node* prev = nullptr;

    while (fast != *head && fast->next != *head) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev == nullptr) {
        *head = (*head)->next;
    } else {
        prev->next = slow->next;
    }

    delete slow;
}

// Function to search for an element in the linked list
bool searchElement(Node* head, int key) {
    Node* current = head;  // Start at the head of the list
    while (current != nullptr) {  // While there are still nodes to check...
        if (current->data == key) {  // If the current node's data matches the key...
            return true;  // ...then we've found the key
        }
        current = current->next;  // Move on to the next node
    }
    return false;  // If we've checked all nodes and haven't found the key, it's not in the list
}

// Function to display the circular linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the data for each node: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertAtMiddle(&head, data);
    }

    cout << "Circular Linked List: ";
    displayList(head);

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    if (searchElement(head, key)) {
        cout << "Element found in the linked list." << endl;
    } else {
        cout << "Element not found in the linked list." << endl;
    }
    

    deleteFromMiddle(&head);

    cout<<"Node Deleted from the middle: "<<endl;
    cout << "Circular Linked List after deletion: ";
    displayList(head);

    return 0;
}
