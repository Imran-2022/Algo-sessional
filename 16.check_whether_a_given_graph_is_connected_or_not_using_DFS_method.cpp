#include <bits/stdc++.h>
using namespace std;

// the graph called connected if and only if it possible to traverse from one node to end . that's it. otherwise not .

void DFS(const vector<vector<int>> &graph, int startNode, vector<bool> &visited)
{
    stack<int> S;
    S.push(startNode);
    visited[startNode] = true;
    while (!S.empty())
    {
        int currentNode = S.top();
        S.pop();
        visited[currentNode] = true;
        for (int adjacentGraph : graph[currentNode])
        {
            if (!visited[adjacentGraph])
            {
                S.push(adjacentGraph);
            }
        }
    }
}

bool isConnectedGraph(const vector<vector<int>> &graph)
{
    int size = graph.size();
    vector<bool> visited(size, false);

    DFS(graph, 0, visited);

    for (bool x : visited)
    {
        if (!x)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int number_of_nodes = 6;
    vector<vector<int>> graph(number_of_nodes);

    // Adding edges to the graph

    graph[0] = {1, 2};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    if (isConnectedGraph(graph))
        cout << "This graph is connected";
    else
        cout << "this graph is not connected";

    return 0;
}