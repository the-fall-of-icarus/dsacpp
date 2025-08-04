#include <iostream>
#include <vector>
using namespace std;

/*
    QUESTION:
    ----------
    Given an undirected graph with `n` nodes labeled from 0 to n - 1
    and a list of edges, return the number of connected components in the graph.

    A connected component is a set of nodes such that:
    - There is a path between any two nodes in the set.
    - The component is not connected to any other node outside the set.

    Example:
    Input:
        n = 5
        edges = {{0, 1}, {1, 2}, {3, 4}}
    
    Output:
        2

    Explanation:
        - One component is [0, 1, 2]
        - Another component is [3, 4]
*/

// Function to perform DFS and mark all reachable nodes from 'node' as visited
void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;

    // Visit all neighbors of the current node
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

// Main function to count the number of connected components
int countConnectedComponents(int n, vector<vector<int>>& edges) {
    // Step 1: Build the adjacency list from the edge list
    vector<vector<int>> adjList(n);  // n nodes, 0-based indexing
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        // Since the graph is undirected, add both edges
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Step 2: Initialize visited array to keep track of visited nodes
    vector<bool> visited(n, false);

    // Step 3: Count connected components
    int count = 0;
    for (int i = 0; i < n; i++) {
        // If the node has not been visited, it's a new component
        if (!visited[i]) {
            count++;
            dfs(i, adjList, visited);
        }
    }

    return count;
}

int main() {
    int n = 5;  // Number of nodes
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};  // Edge list

    int result = countConnectedComponents(n, edges);
    cout << "Number of connected components: " << result << endl;

    return 0;
}
