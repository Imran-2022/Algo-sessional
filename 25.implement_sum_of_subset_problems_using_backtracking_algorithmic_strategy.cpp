#include <iostream>
#include <vector>

using namespace std;

void backtrack(const vector<int> &numbers, int target, vector<int> &current_subset, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(current_subset); // Add the current subset to the result
    }
    else if (target < 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            current_subset.push_back(numbers[i]);
            backtrack(vector<int>(numbers.begin() + i + 1, numbers.end()), target - numbers[i], current_subset, result);
            current_subset.pop_back();
        }
    }
}
// why const here -
// brief:

// In the given code snippet, the subset_sum function has a parameter numbers that is declared as const vector<int> &numbers. The const keyword in this context indicates that the parameter numbers is a constant reference to a vector of integers.

// Using const in the parameter declaration serves two purposes:

// Prevents Modification: The const keyword ensures that the numbers vector is not modified within the subset_sum function. It acts as a safety measure to prevent accidental modifications to the input vector. This is useful when you want to guarantee that the numbers vector remains unchanged throughout the function's execution.

// Efficiency: By passing the vector by reference (&) rather than by value, you avoid making a copy of the vector. However, it also raises the possibility of unintended modification of the input vector. To address this, using const helps maintain the intended immutability while still benefiting from the performance improvement of passing by reference.

// By combining const with a reference parameter, you achieve both the efficiency of passing by reference and the assurance that the numbers vector won't be modified within the subset_sum function.

vector<vector<int>> subset_sum(const vector<int> &numbers, int target)
{
    vector<vector<int>> result;
    vector<int> current_subset;
    backtrack(numbers, target, current_subset, result);
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    int target;
    cin>>target;

    // resource -
    // understand subset problem - abdul bari
    // https://youtu.be/kyLxTdsT8ws

    // 2D vector.

    // https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/

    vector<vector<int>> result = subset_sum(numbers, target);

    // Print the result

    // for (int i = 0; i < result.size(); i++)
    // {
    //     for (int j = 0; j < result[i].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //  in sort -
    // brief:

    // This block of code uses a nested loop to iterate over each subset in the result vector. The outer loop declares a constant reference variable subset that iterates over each element in result. Each subset represents one possible subset of numbers that sums up to the target.

    // The inner loop declares a constant reference variable num that iterates over each element in the current subset. It prints each num followed by a space using the cout statement.

    // After printing all the elements of the current subset, a new line is printed using cout << endl; to separate the subsets from each other.

    // In summary, the code calculates subsets of numbers that sum up to the target and then prints each subset on a new line, with the elements separated by spaces.

    for (const auto &subset : result)
    {
        for (const auto &num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
