#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int **mat, int n, int idx,
         int *total, int *total_edge, int *visited)
{
    visited[idx] = true;
    (*total)++;

    for (int k = 0; k < n; k++) {
        if (mat[idx][k] == 1) {
            (*total_edge)++;
            if (!visited[k]) {
                dfs(mat, n, k, total, total_edge, visited);
            }
        }
    }
}

int countCompleteComponents(int n, int **edges,
                            int edgesSize, int *edgesColSize)
{
    // build adjacency matrix
    int **mat = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        mat[i] = calloc(n, sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    int visited[51] = {0};
    int complete = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int total = 0;
            int total_edge = 0;
            dfs(mat, n, i, &total, &total_edge, visited);
            total_edge /= 2; 
            if (total_edge == total * (total - 1) / 2) {
                complete++;
            }
        }
    }

    return complete;
}
