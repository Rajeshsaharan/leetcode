
int directions[4][2];
int count;
int target_count;

void helper(int ** grid, int gridSize, int * gridColSize, int i , int j, int current_count){
    if (i < 0 || j < 0 || i >= gridSize || j >= gridColSize[i]) return;
    if (grid[i][j] == -1) return;
    if (grid[i][j] == 2) {
        if (current_count == target_count) count++;
        return;
    }

    int temp = grid[i][j];
    grid[i][j] = -1;

    int k = 0;
    while (k < 4) {
        helper(grid, gridSize, gridColSize,
               i + directions[k][0],
               j + directions[k][1],
               current_count + 1);
        k++;
    }

    grid[i][j] = temp;
}

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
    int temp_dirs[4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};
    memcpy(directions, temp_dirs, sizeof(temp_dirs));

    count = 0;
    target_count = 0;

    int start_i = -1, start_j = -1;
    int i = 0;
    while (i < gridSize) {
        int j = 0;
        while (j < gridColSize[i]) {
            if (grid[i][j] != -1) {     
                target_count++;
            }
            if (grid[i][j] == 1) {       
                start_i = i;
                start_j = j;
            }
            j++;
        }
        i++;
    }
    helper(grid, gridSize, gridColSize, start_i, start_j, 1);
    return count;
}
