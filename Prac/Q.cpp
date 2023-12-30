#include<iostream>
using namespace std;

const int max_Size = 5;

class SimpleQueue{
    private:
        int front, rear;
        int queue[max_Size];

    public: 
        SimpleQueue(): front(-1), rear(-1){}
    
    // Function to insert element in queue
    void enqueue(int value){
        if(front ==-1 && rear == max_Size-1){
            cout<<"Queue is full: Can't Insert "<<value<<endl;
            return;
        }
        else if (front == -1){
            front = rear = 0;
        }
        else{
            rear++;
        }

        queue[rear] = value;
        cout<<value<<" Enqueued in simple queue"<<endl;
    }

    //function to delete a value from queue
    void dequeue(){
        if(front == -1){
            cout<<"Queue is empty cant dequeue"<<endl;
            return;
        }
        else if (front == rear ){
            cout<<queue[front]<<" Dequeued from simple queue :"<<endl;
            front = rear = -1;
        }
        else{
            cout<<queue[front]<<" Dequeued from simple queue :"<<endl;
            front ++;
        }
    }
};

int main(){
    SimpleQueue sq;
    sq.enqueue(1);
    sq.enqueue(2);
    sq.enqueue(3);
    sq.enqueue(4);
    sq.enqueue(5);
    sq.enqueue(6); // This will print "Queue is full: Can't Insert 6"

    sq.dequeue();
    sq.dequeue();
    return 0;
}