#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int w, v;
    Item(int w, int v)
    {
        this->w = w;
        this->v = v;
    }
};

bool compareItemsByRatio(const Item& item1, const Item& item2) {
    double ratio1 = static_cast<double>(item1.v) / item1.w;
    double ratio2 = static_cast<double>(item2.v) / item2.w;
    return ratio1 > ratio2;
}

class Knapsack
{
private:
    vector<Item> items;

public:
    void addItem(int w, int v)
    {
        items.push_back(Item(w, v));
    }

    
    double fractional_knapsack(int capacity) {
        sort(items.begin(), items.end(), compareItemsByRatio);

        double total_value = 0.0;
        int current_capacity = capacity;

        for (const Item& item : items) {
            if (current_capacity >= item.w) {
                total_value += item.v;
                current_capacity -= item.w;
            } else {
                double fraction = static_cast<double>(current_capacity) / item.v;
                total_value += fraction * item.v;
                break;
            }
        }

        return total_value;
    }
};

int main()
{
    int capacity;
    cin >> capacity;
    int n;
    cin >> n;
    Knapsack knapsack;
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        knapsack.addItem(w, v);
    }
    double max_value = knapsack.fractional_knapsack(capacity);

    cout << "Maximum value : " << max_value <<endl;
    return 0;
}
