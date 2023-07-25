#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the Rod Cutting problem using dynamic programming
int rodCutting(int len, const vector<int>& prices)
{
    int n = prices.size();
    vector<int> maxValues(len + 1, 0);

    // Solve the problem bottom-up by considering each length from 1 to given length
    for (int i = 1; i <= len; i++)
    {
        // For each length, calculate the maximum value by considering all possible cuts
        for (int j = 1; j <= i && j <= n; j++)
        {
            maxValues[i] = max(maxValues[i], prices[j - 1] + maxValues[i - j]);
        }
    }

    // Return the maximum value obtainable for the given length
    return maxValues[len];
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);
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
