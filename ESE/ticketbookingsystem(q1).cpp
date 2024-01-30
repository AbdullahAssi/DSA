#include<iostream>
#include<vector>
using namespace std;

class TicketBookingSystem {
    int *queue;
    int front, rear, capacity, bookedTickets;
    vector<int> waitingList;

public:
    TicketBookingSystem(int c) {
        front = rear = -1;
        capacity = c;
        bookedTickets = 0;
        queue = new int[capacity];
    }

   bool isFull() {
        return (rear + 1) % capacity == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int item) {
        if (isFull()) {
            waitingList.push_back(item);
            cout << "Queue is full. Added customer to waiting list.\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        bookedTickets++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Customer " << queue[front] << " has cancelled.\n";
        if (front == rear) front = rear = -1;
        else front = (front + 1) % capacity;
        bookedTickets--;

        if (!waitingList.empty()) {
            enqueue(waitingList[0]);
            waitingList.erase(waitingList.begin());
        }
    }
    
        void increaseCapacity(int increase) {
        capacity += increase;
        int *newQueue = new int[capacity];
        for (int i = 0; i <= rear; i++) newQueue[i] = queue[i];
        delete[] queue;
        queue = newQueue;

        while (!isFull() && !waitingList.empty()) {
            enqueue(waitingList[0]);
            waitingList.erase(waitingList.begin());
        }
    }

    int getBookedTickets() {
        return bookedTickets;
    }

    int getWaitingListSize() {
        return waitingList.size();
    }

    int getAvailableTickets() {
        return capacity - bookedTickets;
    }

    void getCustomerIds() {
        if (isEmpty()) {
            cout << "No customers have booked tickets.\n";
            return;
        }
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << "\n";
    }
};

int main() {
    TicketBookingSystem tbs(10);
    int choice, item;
    
    cout<<"\nTicket booking System\n\n";

    while (true) {
         cout << "\n1. Book Tickets\n2. Cancel Booking\n3. Increase Capacity\n4. Check Booked Tickets\n5. Check Waiting List\n6. Check Available Tickets\n7. Check Customer IDs\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

		
        switch (choice) {
            case 1:
                cout << "Enter the customer ID: ";
                cin >> item;
                tbs.enqueue(item);
                break;
            case 2:
                tbs.dequeue();
                break;
            case 3:
                cout << "Enter the increase in capacity: ";
                cin >> item;
                tbs.increaseCapacity(item);
                break;
            case 4:
                cout << "Booked Tickets: " << tbs.getBookedTickets() << "\n";
                break;
            case 5:
                cout << "Waiting List Size: " << tbs.getWaitingListSize() << "\n";
                break;
            case 6:
                cout << "Available Tickets: " << tbs.getAvailableTickets() << "\n";
                break;
            case 7:
                cout << "Customer IDs: ";
                tbs.getCustomerIds();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}


