#include<bits/stdc++.h>
using namespace std;

// Function to merge two subarrays
void merge(int arr[], int left[], int leftSize, int right[], int rightSize)
{
    int i = 0; // Index for the left subarray
    int j = 0; // Index for the right subarray
    int k = 0; // Index for the merged array

    // Compare elements from both subarrays and place them in the merged array
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    // Copy any remaining elements of the left subarray
    while (i < leftSize)
    {
        arr[k++] = left[i++];
    }

    // Copy any remaining elements of the right subarray
    while (j < rightSize)
    {
        arr[k++] = right[j++];
    }
}

// Merge Sort function
void mergeSort(int arr[], int size)
{
    if (size <= 1)
    {
        return; // Base case: already sorted
    }

    int mid = size / 2;    // Midpoint to divide the array
    int left[mid];         // Left subarray
    int right[size - mid]; // Right subarray

    // Populate the left and right subarrays
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];
    }

    // Recursively sort the left and right subarrays
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted subarrays
    merge(arr, left, mid, right, size - mid);
}

// Main function
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Un-Sorted array:- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    mergeSort(arr, n);

    cout << "Sorted array:- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}