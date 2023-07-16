#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>> &board, int row, int col, int n)
{
    // Check if a queen can be placed in the given row and column

    // Check the row on the left side
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check the lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>> &board, int col, int n)
{
    // Base case: All queens have been placed
    if (col == n)
    {
        // Print the solution
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n))
        {
            // Place the queen in the current position
            board[i][col] = 1;

            // Recursively solve the problem for the next column
            res = solveNQueensUtil(board, col + 1, n) || res;

            // Backtrack: Remove the queen from the current position
            board[i][col] = 0;
        }
    }

    return res;
}

void solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueensUtil(board, 0, n))
    {
        cout << "No solution exists!" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << "Nuber of queens : " << n << endl;

    // n-queen problem ------------
    
    // https://youtu.be/xFv_Hl4B83A

    // Each queen should be placed in a unique row, column, or diagonal.

    solveNQueens(n);

    return 0;
}

/**
 * In this program, the isSafe function checks whether it is safe to place a queen in a particular row and column on the chessboard. The solveNQueensUtil function uses backtracking to recursively solve the N-Queens problem by trying all possible positions for each column. Finally, the solveNQueens function initializes the chessboard and calls solveNQueensUtil to solve the problem.

The program takes user input for the number of queens (n) and then prints all the possible solutions or displays a message if no solution exists.

In the 8-queens problem, the goal is to place 8 queens on an 8x8 chessboard in such a way that no two queens threaten each other. Each queen should be placed in a unique row, column, or diagonal.

For the 8-queens problem, there are 92 distinct solutions, which means there are 92 unique configurations in which you can place the 8 queens on the chessboard without any of them threatening each other.

These 92 solutions are considered safe positions because no two queens in each solution share the same row, column, or diagonal.


*/