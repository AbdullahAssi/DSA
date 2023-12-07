#include <iostream>
using namespace std;

int queue[100], front = -1, rear = -1, n = 100;

void insert() {
    int value;
    if (rear == n - 1) {
        cout << "Queue Overflow" << endl;
    }
    else {
        if (front == -1) {
            front = 0;
        }
        cout << "Enter Element: ";
        cin >> value;
        rear++;
        queue[rear] = value;
        cout << "Element " << value << " inserted successfully." << endl;
    }
}

void deleteElement() {
    if (front == -1|| front>rear) {
        cout << "Queue is empty. Cannot delete." << endl;
    }
    else {
        int value = queue[front];
        cout << "Deleted Element: " << value << endl;
        front++;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Elements are: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insert();
            break;

        case 2:
            deleteElement();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}