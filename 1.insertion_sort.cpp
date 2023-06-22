/**
 * link: https://leetcode.com/problems/sort-an-array/
 * however will got timelimit exit with insertion sort 😐
 * as it's complexity O(n^2).
 * need to solve using O(nlogn) complexity max.

class Solution {
public:
   vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = nums[i];

        while (j >= 0 && nums[j] > key) {
            nums[j+1] = nums[j];
            j--;
        }

        nums[j+1] = key;
    }

    return nums;
}
};

*/

// complete solution :-

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, j;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        int tmp = v[i];
        while (j >= 0 && v[j] > tmp)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = tmp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}