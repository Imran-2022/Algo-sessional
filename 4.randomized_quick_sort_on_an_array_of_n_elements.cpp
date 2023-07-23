#include <bits/stdc++.h>
using namespace std;

/**
 * In this program, the Randomized Quick Sort algorithm is implemented using the standard partition function and a random pivot selection. The swap function is used to swap two elements in the array.

The partition function is similar to the previous example, and it partitions the array around a chosen pivot element.

The getRandomPivot function uses the C++ <random> library to generate a random pivot index between low and high (both inclusive).

The randomizedQuickSort function performs the Randomized Quick Sort algorithm. It selects a random pivot index using getRandomPivot, swaps the pivot element to the end of the array, and partitions the array around the pivot. Then, it recursively applies the Quick Sort algorithm to the subarrays before and after the pivot.

The printArray function is used to print the elements of the array.

The program takes user input for the number of elements in the array and the elements themselves. It then calls the randomizedQuickSort function to sort the array and prints the sorted array.
*/

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to select a random pivot

// In this simplified version, rand() is used to generate a random number within the range between low and high. The % operator is then used to ensure the random number is within the desired range. By adding low to the result, we obtain a random pivot index within the specified range.

int getRandomPivot(int low, int high) {
    return low + rand() % (high - low + 1);
}


// Randomized Quick Sort function
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = getRandomPivot(low, high);
        swap(arr[pivotIndex], arr[high]);

        int pivot = partition(arr, low, high);

        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    randomizedQuickSort(arr, 0, N - 1);

    cout << "Sorted array: ";
    printArray(arr, N);

    return 0;
}
