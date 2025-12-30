

int dp[201][201];
int helper(int ** grid, int gridSize, int * gridColSize, int i , int j){
    if(i == gridSize -1 && j == gridColSize[i] -1) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int min = 100000;
    if(i+1 < gridSize){
        min = fmin(min, helper(grid, gridSize, gridColSize, i +1, j));
    }  
    if(j +1 < gridColSize[i]){
        min =fmin(min, helper(grid, gridSize, gridColSize, i , j+1));
    }
    return dp[i][j] = min + grid[i][j];
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    memset(dp, -1, sizeof(dp));
    return helper(grid,gridSize, gridColSize, 0, 0);
}