char* convert(char* s, int numRows) {
    if (numRows == 1) return s;
    int column = strlen(s);
    char * result = malloc((column + 1) * sizeof(char));
   // char ** arr = malloc(numRows * sizeof(char *));
    int i = 0;
   // while(i <  numRows) arr[i++] = malloc(column * sizeof(char));
    char arr[numRows][column];
    // initialize with space
    for(int r=0; r<numRows; r++)
        for(int c=0; c<column; c++)
            arr[r][c] = ' ';

    i = 0;
    int count = 0, change = 0, go_up_step = 0, k = 1;   // k properly init
    while(i < column && count < column){
        if(go_up_step && numRows > 2){
            int j  = numRows - k;   
            arr[j][i] = s[count++];
            k++;
            change++;
        }
        else{
            int j = 0;
            while(j < numRows && count < column)  {
                arr[j][i] = s[count++];
                j++;
            }
            k = 2;
        }
        if(change == 0 || change == numRows -2) {
            change = 0;
            go_up_step = !go_up_step;
        }
        i++;
    }

    i = 0;
    k = 0;
    while(i < numRows){
        int j = 0;
        while(j < column){
            if(arr[i][j] != ' '){       // fixed
                result[k++] = arr[i][j];
            }
            j++;
        }
        i++;
    }

    result[k] = '\0';   // fixed
    return result;
}
