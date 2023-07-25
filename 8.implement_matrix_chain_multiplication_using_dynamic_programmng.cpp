#include<bits/stdc++.h>
using namespace std;

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
    vector<int> dimensions = {40, 20, 30, 10, 30};

    int minCost = matrixChainMultiplication(dimensions);
    cout << "Minimum cost for matrix chain multiplication: " << minCost << endl;

    return 0;
}
