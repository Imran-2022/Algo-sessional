#include <bits/stdc++.h>
using namespace std;

/**
 * In this program, the swap function is used to swap two elements in the array. The partition function selects the last element as the pivot and rearranges the array in such a way that all elements smaller than the pivot are moved to its left and all elements greater than the pivot are moved to its right.

The quickSort function recursively calls itself to sort the sub-arrays before and after the pivot element. This continues until the sub-arrays have only one element, resulting in a sorted array.

The printArray function is used to print the elements of the array.

The program takes user input for the number of elements in the array and the elements themselves. Then, it calls the quickSort function to sort the array and finally prints the sorted array.
*/


// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to find the correct position of the pivot element

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two halves
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the two halves
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    //  unsorted array :

    cout << "unsorted array : ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // quick sort

    quickSort(arr, 0, n - 1);

    // sorted array :

    cout << "sorted array : ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}