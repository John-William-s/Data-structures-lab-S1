#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int adj[20][20], n, vertex, visited[20], mst[20][20], cost = 0;

// defining edge structure
struct Edge {
    int u;
    int v;
    int cost;
};

void prims(int start);

void main() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    // Initialize visited and mst arrays
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            mst[i][j] = 0;
        }
    }

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    // Reading the starting vertex
    printf("\nEnter the starting vertex: ");
    scanf("%d", &vertex);

    // Check for valid starting vertex
    if (vertex < 0 || vertex >= n) {
        printf("\nInvalid starting vertex!\n");
        return;
    }

    prims(vertex);

    // Display MST edges and cost
    printf("\nMST Edges and Costs:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mst[i][j] != 0) {
                printf("%d - %d -> Cost = %d\n", i, j, mst[i][j]);
            }
        }
    }
    printf("\nMinimum cost = %d\n", cost);
}

void prims(int start) {
    int visitedVertexCount = 0;

    // Allocate memory for the minEdge
    struct Edge *minEdge = (struct Edge *)malloc(sizeof(struct Edge));

    // Initialize the edge
    minEdge->cost = INT_MAX;
    minEdge->u = -1;
    minEdge->v = -1;

    // Mark the starting vertex as visited
    visited[start] = 1;
    visitedVertexCount++;

    while (visitedVertexCount < n) {
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) { // Consider only visited vertices
                for (int j = 0; j < n; j++) {
                    // Find the minimum edge (i, j) such that i is visited and j is not visited
                    if (adj[i][j] != 0 && visited[j] == 0 && adj[i][j] < minEdge->cost) {
                        minEdge->u = i;
                        minEdge->v = j;
                        minEdge->cost = adj[i][j];
                    }
                }
            }
        }

        // Mark the vertex as visited and update the MST
        visited[minEdge->v] = 1;
        cost += minEdge->cost;
        visitedVertexCount++;
        mst[minEdge->u][minEdge->v] = minEdge->cost;

        // Reset the minEdge for the next iteration
        minEdge->u = -1;
        minEdge->v = -1;
        minEdge->cost = INT_MAX;
    }

    // Free the dynamically allocated memory
    free(minEdge);
}
