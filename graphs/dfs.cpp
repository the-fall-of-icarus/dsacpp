#include <iostream>
#include <vector>
using namespace std;

/*
    Perform DFS traversal on an undirected graph.
    The graph is represented using an adjacency list.
*/

void dfsTraversal(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;            // Mark current node as visited
    cout << node << " ";             // Print the node (or add to result vector)

    // Recursively visit all unvisited neighbors
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfsTraversal(neighbor, adjList, visited);
        }
    }
}

int main() {
    int n = 5;  // Number of nodes (0 to 4)

    // Define edges
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {3, 4}
    };

    // Step 1: Build adjacency list
    vector<vector<int>> adjList(n);
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Since the graph is undirected
    }

    // Step 2: Create visited array
    vector<bool> visited(n, false);

    // Step 3: Start DFS from node 0
    cout << "DFS Traversal: ";
    dfsTraversal(0, adjList, visited);
    cout << endl;

    return 0;
}
