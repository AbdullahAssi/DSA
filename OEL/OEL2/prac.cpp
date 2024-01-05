#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    private:
        vector<int> heap;

    void heapifyUp(int index){
        int parent = (index -1)/2;
        while(index > 0 && heap[index] > heap[parent]){
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index -1)/2;
        }
    }

    void heapifyDown(int index){
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;
        int largest = index;

        if(leftChild < heap.size() && heap[leftChild] > heap[largest]){
            largest = leftChild;
        }

        if(rightChild < heap.size() && heap[rightChild] > heap[largest]){
            largest = rightChild;
        }

        if(largest != index){
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    public:
        void insert(int value){
            heap.push_back(value);
            heapifyUp(heap.size()-1);
        }

        int removeMax(){
            if(heap.empty()){
                throw out_of_range("Heap is empty");
            }
            int max = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
    
        }

        void printHeap(){
            for(int value : heap){
                cout << value << " ";
            }
            cout << endl;
        }
};

int main (){
    MaxHeap heap;
    heap.insert(42);
    heap.insert(29);
    heap.insert(18);
    heap.insert(14);
    heap.insert(7);

    heap.printHeap();

}
