int dfs(int ** grid, int gridSize, int * gridColSize, int i , int j ){
    if(i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i]) return 0;
    if(grid[i][j] == -1 || grid[i][j] == 0) return 0;
    grid[i][j] = -1;
    int area1 = dfs(grid, gridSize, gridColSize, i-1, j);
    int area2 = dfs(grid, gridSize, gridColSize, i+1, j);
    int area3 = dfs (grid, gridSize, gridColSize, i,j-1);
    int area4 = dfs(grid, gridSize,gridColSize,i, j+1);
    return area1 + area2 + area3 + area4 + 1;
}


int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int area = 0;
    int i = 0;
    while(i < gridSize){
        int j = 0;
        while(j < gridColSize[i]){
            if(grid[i][j] == 1){
                area  = fmax(area, dfs(grid, gridSize, gridColSize,i, j));
            } 
            j++;
        }
        i++;
    }
    return area;
}