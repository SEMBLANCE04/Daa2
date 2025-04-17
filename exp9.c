#include <stdbool.h>
#include <stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];  // Adjacency matrix
int colors[MAX_VERTICES];               // Stores assigned colors
int numVertices, numColors;

// Function prototypes
void graphColoring(int vertex);
bool checkVertex(int vertex, int color);

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors available: ");
    scanf("%d", &numColors);

    printf("Enter the available colors (represented as numbers):\n");
    for (int i = 0; i < numColors; i++) {
        scanf("%d", &colors[i]);
    }

    printf("Coloring the graph...\n");
    graphColoring(0);

    return 0;
}

// Function to color the graph using backtracking
void graphColoring(int vertex) {
    if (vertex == numVertices) {  // If all vertices are colored
        printf("Solution found:\n");
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d --> Color %d\n", i, colors[i]);
        }
        printf("\n");
        return;
    }

    for (int colorIndex = 0; colorIndex < numColors; colorIndex++) {
        if (checkVertex(vertex,
                        colors[colorIndex])) {  // Check if color is safe
            colors[vertex] = colors[colorIndex];
            graphColoring(vertex + 1);  // Recur for next vertex
            colors[vertex] = 0;         // Backtrack
        }
    }
}

// Function to check if it's safe to color a vertex with a specific color
bool checkVertex(int vertex, int color) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;  // Adjacent vertex has the same color
        }
    }
    return true;
}
