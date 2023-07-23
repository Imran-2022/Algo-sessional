#include <iostream>
using namespace std;

/*
This implementation follows a similar approach as the previous one but does not use the STL. Instead, it manually defines a max function to compare two integers and return the maximum value.

The rodCutting function takes the length of the rod and an array of prices as input and returns the maximum value obtainable for that length.

The function initializes an array maxValues of size length + 1 to store the maximum values for each length. Each element in maxValues is initially set to 0.

The solution is computed bottom-up, similar to the previous implementation. For each length i, the function considers all possible cuts from 1 to i and calculates the maximum value by selecting the cut that yields the highest value. The maximum value is stored in maxValues[i].

Finally, the function returns maxValues[length], which represents the maximum value obtainable for the given length.

In the example usage in the main function, a rod of length 8 is considered. The prices for each length are provided in the prices array. The rodCutting function is called with the length and prices, and the maximum value obtainable is printed using cout.
*/


// Function to calculate the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the Rod Cutting problem using dynamic programming
int rodCutting(int length, int prices[])
{
    int maxValues[length + 1];

    // Initialize the array with zeros
    for (int i = 0; i <= length; i++)
    {
        maxValues[i] = 0;
    }

    // Solve the problem bottom-up by considering each length from 1 to given length
    for (int i = 1; i <= length; i++)
    {
        // For each length, calculate the maximum value by considering all possible cuts
        for (int j = 1; j <= i; j++)
        {
            maxValues[i] = max(maxValues[i], prices[j] + maxValues[i - j]);
        }
    }

    // Return the maximum value obtainable for the given length
    return maxValues[length];
}

// Example usage
int main()
{

    //   int length = 8;
    // int prices[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};

    int n;
    cin >> n;
    int prices[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    int len;
    cin >> len;

    int maxValue = rodCutting(len, prices);
    cout << "Maximum value obtainable for length " << len << ": " << maxValue << endl;

    return 0;
}
