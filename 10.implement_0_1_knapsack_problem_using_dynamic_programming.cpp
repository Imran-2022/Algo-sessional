#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    int w, v;
    Item(int w, int v) {
        this->w = w;
        this->v = v;
    }
};

class Knapsack {
private:
    vector<Item> items;
    vector<vector<int>> dp; // Dynamic programming table

public:
    void addItem(int w, int v) {
        items.push_back(Item(w, v));
    }

    int knapsack_01(int capacity) {
        int n = items.size();
        dp.resize(n + 1, vector<int>(capacity + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int w = 1; w <= capacity; ++w) {
                if (items[i - 1].w <= w) {
                    dp[i][w] = max(items[i - 1].v + dp[i - 1][w - items[i - 1].w], dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[n][capacity];
    }
};

int main() {
    int capacity;
    cin >> capacity;
    int n;
    cin >> n;
    Knapsack knapsack;
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        knapsack.addItem(w, v);
    }
    int max_value = knapsack.knapsack_01(capacity);

    cout << "Maximum value: " << max_value << endl;
    return 0;
}
