// Graph Representation in C++ using both Adjacency Matrix and Adjacency List

#include <iostream>
#include <vector>
using namespace std;

// Adjacency Matrix Representation
void adjacencyMatrixExample(int V, vector<pair<int, int>> &edges) {
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // for undirected graph
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Adjacency List Representation
void adjacencyListExample(int V, vector<pair<int, int>> &edges) {
    vector<vector<int>> adjList(V);

    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // for undirected graph
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
}

int main() {
    int V = 4; // number of vertices
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}
    };

    adjacencyMatrixExample(V, edges);
    adjacencyListExample(V, edges);

    return 0;
}
