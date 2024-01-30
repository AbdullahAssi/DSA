#include <iostream>
#include <string>

const int MAX_SIZE = 100;

class Stack {
private:
    int top;
    std::string routineName[MAX_SIZE];
    float routineExecutionTime[MAX_SIZE];
    int routinePriority[MAX_SIZE];

public:
    Stack();
    void push(std::string name, float time, int priority);
    void pop();
    bool isEmpty();
    bool isFull();
    std::string getRoutineName(int index) const;
    float getRoutineExecutionTime(int index) const;
    int getRoutinePriority(int index) const;
    int getTop() const;
};

class Queue {
private:
    int front, rear;
    std::string routineName[MAX_SIZE];
    float routineExecutionTime[MAX_SIZE];
    int routinePriority[MAX_SIZE];

public:
    Queue();
    void enqueue(std::string name, float time, int priority);
    void dequeue();
    bool isEmpty();
    bool isFull();
    std::string getRoutineName(int index) const;
    float getRoutineExecutionTime(int index) const;
    int getRoutinePriority(int index) const;
    int getFront() const;  // New accessor function for front
};

Stack::Stack() : top(-1) {}

void Stack::push(std::string name, float time, int priority) {
    if (!isFull()) {
        top++;
        if (top < MAX_SIZE) {
            routineName[top] = name;
            routineExecutionTime[top] = time;
            routinePriority[top] = priority;
        }
    } else {
        std::cout << "Stack Overflow\n";
    }
}

void Stack::pop() {
    if (!isEmpty()) {
        top--;
    } else {
        std::cout << "Stack Underflow\n";
    }
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == MAX_SIZE - 1;
}

std::string Stack::getRoutineName(int index) const {
    return routineName[index];
}

float Stack::getRoutineExecutionTime(int index) const {
    return routineExecutionTime[index];
}

int Stack::getRoutinePriority(int index) const {
    return routinePriority[index];
}

int Stack::getTop() const {
    return top;
}

Queue::Queue() : front(-1), rear(-1) {}

void Queue::enqueue(std::string name, float time, int priority) {
    if (!isFull()) {
        if (front == -1) {
            front = 0;
        }
        rear++;
        if (rear < MAX_SIZE) {
            routineName[rear] = name;
            routineExecutionTime[rear] = time;
            routinePriority[rear] = priority;
        }
    } else {
        std::cout << "Queue Full\n";
    }
}

void Queue::dequeue() {
    if (!isEmpty()) {
        front++;
        if (front > rear || front >= MAX_SIZE) {
            front = rear = -1;
        }
    } else {
        std::cout << "Queue Empty\n";
    }
}

bool Queue::isEmpty() {
    return front == -1;
}

bool Queue::isFull() {
    return rear == MAX_SIZE - 1;
}

std::string Queue::getRoutineName(int index) const {
    return routineName[index];
}

float Queue::getRoutineExecutionTime(int index) const {
    return routineExecutionTime[index];
}

int Queue::getRoutinePriority(int index) const {
    return routinePriority[index];
}

int Queue::getFront() const {
    return front;
}

int main() {
    Stack routineStack;
    Queue routineQueue;

    // Populate the stack with routines (for demonstration purposes)
    routineStack.push("Routine1", 5.0, 3);
    routineStack.push("Routine2", 2.5, 1);
    routineStack.push("Routine3", 4.0, 2);
    routineStack.push("Routine4", 3.0, 2);

    // Dequeue 3 routines from the stack and enqueue in the queue based on priority
    for (int i = 0; i < 3; ++i) {
        if (!routineStack.isEmpty()) {
            routineQueue.enqueue(
                routineStack.getRoutineName(routineStack.getTop()),
                routineStack.getRoutineExecutionTime(routineStack.getTop()),
                routineStack.getRoutinePriority(routineStack.getTop())
            );
            routineStack.pop();
        }
    }

    // Display the routines in the queue
    std::cout << "Routines in Queue:\n";
    while (!routineQueue.isEmpty()) {
        std::cout << "Name: " << routineQueue.getRoutineName(routineQueue.getFront()) << ", "
                  << "Execution Time: " << routineQueue.getRoutineExecutionTime(routineQueue.getFront()) << ", "
                  << "Priority: " << routineQueue.getRoutinePriority(routineQueue.getFront()) << "\n";
        routineQueue.dequeue();
    }

    return 0;
}

