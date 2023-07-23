#include<bits/stdc++.h>
using namespace std;

/*
The Matrix Chain Multiplication problem involves finding the optimal way to multiply a series of matrices to minimize the total number of scalar multiplications. The problem is solved using dynamic programming.

In the code, the matrixChainMultiplication function takes a vector of matrix dimensions as input and returns the minimum cost (number of scalar multiplications) for multiplying the matrices.

The function initializes a 2D vector dp of size n by n (where n is the number of matrices) to store the minimum costs for different subproblems. Each element in dp is initially set to 0.

The solution is computed bottom-up. The function considers different subproblems of increasing lengths and calculates the minimum cost for each subproblem. It iterates over the lengths (len) starting from 2, and for each length, it iterates over the starting indices (i) and calculates the corresponding ending index (j). The minimum cost for multiplying matrices from index i to j is calculated by trying all possible splits at index k and finding the minimum among them. The formula dp[i][j] = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j] is used to calculate the cost.

Finally, the function returns dp[1][n - 1], which represents the minimum cost for multiplying all the matrices.

In the example usage in the main function, a vector dimensions is provided that represents the dimensions of the matrices to be multiplied. The matrixChainMultiplication function is called with the dimensions, and the minimum cost is printed using cout.
*/

// Function to calculate the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve the Matrix Chain Multiplication problem using dynamic programming
int matrixChainMultiplication(const vector<int>& dimensions) {
    int n = dimensions.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Solve the problem bottom-up by considering different subproblems
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // Return the minimum cost for multiplying the matrices
    return dp[1][n - 1];
}

// Example usage
int main() {
    vector<int> dimensions = {10, 30, 5, 60};

    int minCost = matrixChainMultiplication(dimensions);
    cout << "Minimum cost for matrix chain multiplication: " << minCost << endl;

    return 0;
}
