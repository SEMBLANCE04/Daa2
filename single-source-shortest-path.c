#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5  // Number of vertices

// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];      // Stores shortest distances from source
    bool visited[V];  // True if vertex is included in shortest path tree

    // Step 1: Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    // Step 2: Process the vertices
    for (int count = 0; count < V - 1; count++) {
        int u =
            minDistance(dist, visited);
        visited[u] = true;

        // Update distance values of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the final distances
    printf("Vertex \t Distance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[5][5] = {{0, 15, 0, 25, 80},
                       {15, 0, 35, 0, 0},
                       {0, 35, 0, 10, 40},
                       {25, 0, 10, 0, 55},
                       {80, 0, 40, 55, 0}};

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
