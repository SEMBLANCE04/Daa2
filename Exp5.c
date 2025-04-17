/**
 * @file Exp5.c
 * @brief Implementation of Floyd-Warshall Algorithm for All-Pairs Shortest Path in C.
 *
 * This program implements the Floyd-Warshall algorithm to find the shortest paths
 * between all pairs of vertices in a weighted graph. The algorithm uses dynamic programming
 * to iteratively improve the shortest path estimates.
 *
 * The program takes input from the user for the number of vertices and the adjacency matrix
 * of the graph. It then calculates and displays the shortest path distances between all pairs
 * of vertices.
 *
 * @author Shridharkhare
 * @date YYYY-MM-DD
 */

#include <stdio.h>
#include <stdlib.h>

#define INF 99999  /**< A large value representing infinity for unreachable paths */
#define min(a, b) (a < b ? a : b) /**< Macro to find the minimum of two values */
#define MAX 100   /**< Maximum number of vertices supported */

/**
 * @brief Displays the shortest path distance matrix.
 *
 * This function prints the distance matrix, where each cell represents the shortest
 * distance between a pair of vertices. If a path is unreachable, it displays "INF".
 *
 * @param n The number of vertices in the graph.
 * @param dist The distance matrix containing shortest path distances.
 */
void display(int n, int dist[MAX][MAX]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * @brief Implements the Floyd-Warshall algorithm.
 *
 * This function computes the shortest paths between all pairs of vertices in the graph
 * using the Floyd-Warshall algorithm. It updates the distance matrix iteratively.
 *
 * @param n The number of vertices in the graph.
 * @param graph The adjacency matrix of the graph.
 */
void floydWarshall(int n, int graph[MAX][MAX]) {
    int i, j, k;
    int dist[MAX][MAX];

    // Initialize the distance matrix with the input graph
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the distance matrix using the Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Display the final distance matrix
    display(n, dist);
}

/**
 * @brief The main function of the program.
 *
 * This function prompts the user to input the number of vertices and the adjacency matrix
 * of the graph. It then calls the Floyd-Warshall algorithm to compute and display the
 * shortest path distances between all pairs of vertices.
 *
 * @return Returns 0 upon successful execution.
 */
void main() {
    int i, j;
    int n;
    int graph[MAX][MAX];

    // Input the number of vertices
    printf("Enter the number of vertices (less than 100): ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (use 99999 for INF): ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Call the Floyd-Warshall algorithm
    floydWarshall(n, graph);
}
