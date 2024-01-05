#include <iostream>
#include <vector>
using namespace std;
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int removeMax() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    void printHeap() {
        for (int value : heap) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    // Inserting elements into the heap
    heap.insert(10);
    cout << "Heap after inserting 10: ";
    heap.printHeap();

    heap.insert(12);
    cout << "Heap after inserting 12: ";
    heap.printHeap();
    heap.insert(1);
    cout << "Heap after inserting 1: ";
    heap.printHeap();
    heap.insert(14);
    cout << "Heap after inserting 14: ";
    heap.printHeap();
    heap.insert(6);
    cout << "Heap after inserting 6: ";
    heap.printHeap();
    heap.insert(5);
    cout << "Heap after inserting 5: ";
    heap.printHeap();
    heap.insert(8);
    cout << "Heap after inserting 8: ";
    heap.printHeap();
    heap.insert(15);
    cout << "Heap after inserting 15: ";
    heap.printHeap();
    heap.insert(3);
    cout << "Heap after inserting 3: ";
    heap.printHeap();
    heap.insert(9);
    cout << "Heap after inserting 9: ";
    heap.printHeap();

    heap.insert(7);
    cout << "Heap after inserting 7: ";
    heap.printHeap();

    heap.insert(4);
    cout << "Heap after inserting 4: ";
    heap.printHeap();
    heap.insert(11);
    cout << "Heap after inserting 11: ";
    heap.printHeap();
    heap.insert(13);
    cout << "Heap after inserting 13: ";
    heap.printHeap();
    heap.insert(2);
    cout << "Heap after inserting 2: ";
    heap.printHeap();

    // Printing the heap after inserting all elements
    cout << "Final Heap: ";
    heap.printHeap();


    // Removing maximum elements from the heap
    for (int i = 0; i < 7; i++) {
        int removedValue = heap.removeMax();
        cout << "Heap after removing " << removedValue << " (max) element: ";
        heap.printHeap();
    }


    return 0;
}
