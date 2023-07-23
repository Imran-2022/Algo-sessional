#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS traversal and print all reachable nodes

void BFS(const vector<vector<int>> &graph, int start_form_node)
{
    int numNodes = graph.size();

    // keep track of visited node.

    vector<bool> visited(numNodes, false);

    // q to store nodes for BFS traversal.

    queue<int> Q;

    // Enqueue the starting node

    Q.push(start_form_node);
    visited[start_form_node] = true;

    while (!Q.empty())
    {
        int current_Node = Q.front();
        Q.pop();
        cout << current_Node << " ";

        // Enqueue all adjacent nodes that are not visited..

        for (int adjacentNode : graph[current_Node])
        {
            if (!visited[adjacentNode])
            {
                Q.push(adjacentNode);
                visited[adjacentNode] = true;
            }
        }
    }
}

int main()
{
    int number_of_nodes = 6;
    vector<vector<int>> graph(number_of_nodes);

    // add edges to the directed Graph..

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(4);
    graph[3].push_back(5);
    graph[4].push_back(5);

    int start_form_node;
    cin >> start_form_node;

    cout << "Nodes reachable form node " << start_form_node << " : ";

    BFS(graph, start_form_node);

    return 0;
}