int directions[4][2];

void helper(char ** board, int boardSize, int *boardColSize, int i , int j){
    if(i < 0 || j <0 || i >= boardSize || j >= boardColSize[i] || board[i][j] == 'X' || board[i][j] == 'S') return;
    board[i][j] = 'S';
    int k = 0;
    while(k < 4){
        int new_i = i + directions[k][0];
        int new_j = j + directions[k][1];
        helper(board, boardSize, boardColSize, new_i , new_j);
        k++;
    }
}

void solve(char** board, int boardSize, int* boardColSize) {
    int temp[4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};
    memcpy(directions,temp, sizeof(temp));
    int i = 0;
    while(i < boardSize){
        int j = 0;
        while(j  < boardColSize[i]){
            if(board[i][j] == 'O' && (i == 0 || i == boardSize -1 || j == 0 || j == boardColSize[i]-1)) helper(board, boardSize, boardColSize, i , j);
            j++;
        }
        i++;
    }
    i = 0;
    while(i < boardSize){
        int j = 0;
        while(j < boardColSize[i]) { 
            if(board[i][j] == 'O') board[i][j] = 'X';
            if(board[i][j] == 'S') board[i][j] = 'O';
            j++;
        }        
        i++;
    }
    return;
}