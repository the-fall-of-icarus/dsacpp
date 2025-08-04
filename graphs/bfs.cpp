#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
    BFS Traversal of a Graph
    ------------------------
    Given an undirected graph and a starting node, perform a Breadth-First Search (BFS)
    traversal and print the nodes in the order they are visited.

    BFS explores the graph level by level using a queue.

    Example:
    Input:
        n = 5
        edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}}

    Output (starting from node 0):
        BFS Traversal: 0 1 2 3 4
*/

void bfsTraversal(int start, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;

    // Push the starting node and mark it as visited
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Print the current node
        cout << node << " ";

        // Traverse all unvisited neighbors and add them to the queue
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 5;  // Number of nodes (0 to 4)
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {3, 4}
    };

    // Step 1: Build the adjacency list
    vector<vector<int>> adjList(n);
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Because it's an undirected graph
    }

    // Step 2: Prepare visited array
    vector<bool> visited(n, false);

    // Step 3: Perform BFS starting from node 0
    cout << "BFS Traversal: ";
    bfsTraversal(0, adjList, visited);
    cout << endl;

    return 0;
}
