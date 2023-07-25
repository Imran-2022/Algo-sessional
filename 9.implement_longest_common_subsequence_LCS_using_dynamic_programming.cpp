#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int, string> longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    // Create a 2D DP table to store LCS lengths
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table using bottom-up approach
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to construct the LCS text
    int length = dp[m][n];
    string lcsText;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcsText = text1[i - 1] + lcsText;
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    return make_pair(length, lcsText);
}

int main() {
    string text1, text2;
    cin>>text1>>text2;

    pair<int, string> result = longestCommonSubsequence(text1, text2);
    int lcsLength = result.first;
    string lcsText = result.second;

    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;
    cout << "Longest Common Subsequence: " << lcsText << endl;

    return 0;
}
