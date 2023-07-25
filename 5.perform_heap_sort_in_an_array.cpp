#include <bits/stdc++.h>
using namespace std;


// Function to heapify a subtree rooted at 'rootIndex' in the array 'arrSize'
void heapify(int arr[], int arrSize, int rootIndex)
{
    int largest = rootIndex;       // Assume the root as the largest element
    int left = 2 * rootIndex + 1;  // Index of the left child
    int right = 2 * rootIndex + 2; // Index of the right child

    // If the left child is larger than the root
    if (left < arrSize && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the current largest
    if (right < arrSize && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the root
    if (largest != rootIndex)
    {
        // Swap the root with the largest element
        swap(arr[rootIndex], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, arrSize, largest);
    }
}
// Main function to perform heap sort
void heapSort(int arr[], int arrSize)
{
    // Build a max-heap
    for (int i = arrSize / 2 - 1; i >= 0; i--)
        heapify(arr, arrSize, i);

    // Extract elements from the heap one by one
    for (int i = arrSize - 1; i > 0; i--)
    {
        // Move the current root (the maximum element) to the end
        swap(arr[0], arr[i]);

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // implement heapsort
    heapSort(arr, n);
    // sorted array -

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}