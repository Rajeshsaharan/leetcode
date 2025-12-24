int directions[4][2];

void helper(char ** board, int boardSize, int *boardColSize, int i , int j){
    if(i < 0 || j <0 || i >= boardSize || j >= boardColSize[i] || board[i][j] == '0' || board[i][j] == 'S') return;
    board[i][j] = 'S';
    int k = 0;
    while(k < 4){
        int new_i = i + directions[k][0];
        int new_j = j + directions[k][1];
        helper(board, boardSize, boardColSize, new_i , new_j);
        k++;
    }
}



int numIslands(char** grid, int gridSize, int* gridColSize) {
    int temp[4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};
    memcpy(directions,temp, sizeof(temp));
    int i = 0;
    int is = 0;
    while(i < gridSize){
        int j = 0;
        while(j < gridColSize[i]){
            if(grid[i][j] == '1'){
                helper(grid, gridSize, gridColSize, i,j);
                is++;
            }
            j++;
        }
        i++;
    }
    return is;
}