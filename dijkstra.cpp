#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to implement Dijkstra's single source shortest path algorithm for a graph represented using an adjacency matrix
std::vector<int> dijkstra(const vector<vector<int>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX); // The output array. dist[i] will hold the shortest distance from src to i
    vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i is included in the shortest path tree
    vector<int> pred(V, -1); // Array to store predecessors

    dist[src] = 0; // Distance of source vertex from itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, V);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not in sptSet, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pred[v] = u; // Update predecessor
            }
        }
    }

    // Print the constructed distance array and shortest paths
    cout << "Vertex\tDistance from Source\tShortest Path" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t\t\t";
        // Print shortest path
        int curr = i;
        while (curr != src) {
            cout << curr << " <- ";
            curr = pred[curr];
        }
        cout << src << endl;
    }
    
    return dist;
}



int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 10, 20, 0, 0, 0},
        {10, 0, 0, 50, 10, 0},
        {20, 0, 0, 20, 33, 0},
        {0, 50, 20, 0, 20, 2},
        {0, 10, 33, 20, 0, 1},
        {0, 0, 0, 2, 1, 0}
    };

    int source = 0; // Source vertex
    dijkstra(graph, source);

    return 0;
}
