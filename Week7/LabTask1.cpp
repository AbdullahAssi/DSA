#include <iostream>
using namespace std;
#include <queue>

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    queue<float> myQueue;

    for (int i = 0; i < N; i++) {
        float element;
        cout << "Enter " << N+1 << " elements:\n";
        cin >> element;
        myQueue.push(element);
    }

    int dequeueCount = min(N, 5);
    cout << "Dequeue operations:\n";
    for (int i = 0; i < dequeueCount; i++) {
        float frontElement = myQueue.front();
        myQueue.pop();
        cout << frontElement << " ";
    }
    cout << endl;
    return 0;
}
