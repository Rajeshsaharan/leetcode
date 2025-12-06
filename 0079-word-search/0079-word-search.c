int directions[4][2];
int helper(char ** board, int boardSize, int * boardColSize,  int i , int j, int index, char * word){
    if(word[index] == '\0') return true; // all position cehckd
    if(i < 0 || j < 0 || i >= boardSize || j >= boardColSize[i] || board[i][j] == '#') return false; //checking all directions and making decision on basis on that
    if(board[i][j] != word[index]) return false;
    int temp = board[i][j];
    board[i][j] = '#';
    int k = 0;
    while(k < 4) //exploring all dir
    {   
        int temp_i = i, temp_j = j;
        i += directions[k][0];
        j += directions[k][1];
        if(helper(board, boardSize, boardColSize, i, j, index +1, word)) return true;;
        i = temp_i , j = temp_j;
        k++;
    }
    board[i][j] = temp;
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
   int temp[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
   memcpy(directions, temp, sizeof(temp));
   int i = 0;
   while(i < boardSize){
    int j = 0;
        while(j < boardColSize[i]){
            if(board[i][j] == word[0] && helper(board, boardSize, boardColSize, i, j,0, word)) return true;
            j++;
        }
        i++;
   }
   return false;
    
}