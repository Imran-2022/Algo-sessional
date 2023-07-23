#include <bits/stdc++.h>
using namespace std;

void DFS(const vector<vector<int>> &graph, int start_form_node)
{
    int size = graph.size();
    vector<bool> visited(size, false);
    stack<int> S;
    S.push(start_form_node);

    while (!S.empty())
    {
        int currentNode = S.top();
        S.pop();
        cout << currentNode << " ";
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

int main()
{
    int number_of_nodes = 6;
    vector<vector<int>> graph(number_of_nodes);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(5);

    int start_form_node;

    cin >> start_form_node;

    cout << "Nodes rachable form node " << start_form_node << " : ";

    DFS(graph, start_form_node);

    return 0;
}