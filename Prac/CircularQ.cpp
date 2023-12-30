#include<iostream>
using namespace std;

const int max_size = 5;

class CircularQueue {
private:
    int front, rear;
    int queue[max_size];

public:
    CircularQueue() : front(-1), rear(-1) {}

    // Function to insert element in queue
    void enqueue(int value) {
        if ((front == 0 && rear == max_size - 1) || (rear == (front - 1) % (max_size - 1))) {
            cout << "Queue is full: Can't Insert " << value << endl;
            return;
        } else if (front == -1) {
            front = rear = 0;
        } else if (rear == max_size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }

        queue[rear] = value;
        cout << value << " Enqueued in circular queue" << endl;
    }

    //function to delete a value from queue
    void dequeue(){
        if(front == -1){
            cout<<"Queue is empty cant dequeue"<<endl;
            return;
        }
        else if(front == rear ) {
            cout<<queue[front]<<" Dequeued from circular queue :";
            front = rear = -1;
        }
        else{
            cout<<queue[front]<<" Dequeued from circular queue : "<<endl;
            front = (front+1)% max_size;
        }

    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6); // This will print "Queue is full: Can't Insert 6"

    cq.dequeue();
    cq.dequeue();
    return 0;
}
