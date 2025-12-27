void dfs(int ** grid, int gridSize, int * gridColSize, int i, int j){
    if(i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i]) return;
    if(grid[i][j] == -1 || grid[i][j] == 0) return;
    grid[i][j] = -1;
    dfs(grid, gridSize, gridColSize, i+1, j);
    dfs(grid, gridSize, gridColSize, i-1, j);
    dfs(grid, gridSize, gridColSize, i, j+1);
    dfs(grid, gridSize, gridColSize, i, j-1);
}



int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    int count = 0;
    //count for the boundary i == 0 and i == gridSize -1 and j == 0 and gridColSize[i] -1 == j that are 
    int i = 0;
    while(i < gridSize){
        int j =  0;
        while(j < gridColSize[i]){
            if(i == 0 || j == 0 || i == gridSize -1 || j == gridColSize[i]-1){
                dfs(grid, gridSize, gridColSize, i, j);
            }
            j++;
        }
        i++;
    }
    i = 0;
    while(i < gridSize){
        int j = 0;
        while(j < gridColSize[i]){
            if(grid[i][j] != -1 && grid[i][j] != 0) count++;
            j++;
        }
        i++;
    }
    return count;
}