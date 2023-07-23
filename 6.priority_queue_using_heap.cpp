#include <iostream>
#include <queue>
using namespace std;

/**
 * A priority queue is an abstract data type that is similar to a queue but with each element having a priority assigned to it. The elements with higher priority are dequeued first. In C++, the std::priority_queue class template is used to implement a priority queue using a heap.

The std::priority_queue class provides various member functions, including push(), pop(), top(), and empty(), to perform operations on the priority queue.

In the example usage in the main function, a priority queue named pq is created using the priority_queue<int> syntax. Elements 30, 10, 50, 20, and 40 are inserted into the priority queue using the push() function.

The top() function is used to access the top (highest priority) element in the priority queue, which in this case is 50. It is printed using cout.

Next, a loop is used to remove elements from the priority queue using the pop() function. The elements are printed using cout in the order of their priority (highest to lowest). The output will be 50 40 30 20 10.

Finally, the program exits by returning 0.

This implementation demonstrates the usage of a priority queue as a max-heap. By default, std::priority_queue uses a max-heap, where the element with the highest priority (largest value) is always at the top.
*/
int main() {
    // Creating a priority queue
    priority_queue<int> pq;

    // Inserting elements into the priority queue
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);

    // Printing the top element of the priority queue
    cout << "Top element: " << pq.top() << endl;

    // Removing elements from the priority queue
    cout << "Elements in priority queue: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}