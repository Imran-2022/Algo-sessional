#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < n && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < n && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int top() const {
        if (!isEmpty()) {
            return heap[0];
        }
        throw runtime_error("Priority queue is empty.");
    }

    void pop() {
        if (!isEmpty()) {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        } else {
            throw runtime_error("Priority queue is empty.");
        }
    }
};

int main() {
    MaxHeap pq;

    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(1);
    pq.push(2);

    while (!pq.isEmpty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
