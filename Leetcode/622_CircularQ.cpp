class MyCircularQueue {
    int* queue;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        queue = new int[k];
        front = rear = -1;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;

        return true;
    }

    int Front() {
        return isEmpty() ? -1 : queue[front];
    }

    int Rear() {
        return isEmpty() ? -1 : queue[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
