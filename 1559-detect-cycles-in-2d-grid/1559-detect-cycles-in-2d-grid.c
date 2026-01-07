
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int **visited;

bool dfs(char **grid, int gridSize, int *gridColSize,
         int i, int j, int pi, int pj) {

    visited[i][j] = 1;
    bool result = false;

    for (int k = 0; k < 4; k++) {

        int ni = i + dir[k][0];
        int nj = j + dir[k][1];

        if (ni >= 0 && nj >= 0 &&
            ni < gridSize && nj < gridColSize[ni] &&
            grid[ni][nj] == grid[i][j]) {

            if (!(ni == pi && nj == pj)) {

                if (visited[ni][nj]) {
                    result |= true;
                } else {
                    result |= dfs(grid, gridSize, gridColSize,
                                  ni, nj, i, j);
                }
            }
        }
    }
    return result;
}

bool containsCycle(char **grid, int gridSize, int *gridColSize) {

    visited = malloc(sizeof(int*) * gridSize);
    for (int i = 0; i < gridSize; i++)
        visited[i] = calloc(gridColSize[i], sizeof(int));

    bool result = false;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {

            if (!visited[i][j]) {
                result |= dfs(grid, gridSize, gridColSize,
                              i, j, -1, -1);
            }
        }
    }
    return result;
}
