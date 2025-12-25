bool judgeCircle(char* moves) {
    int arr[4] = {0}; //for U -> 0 for D -> 1 and for L - 1 and R - > 2;
    int i = 0;
    while(moves[i] != '\0'){
        if(moves[i] == 'U') arr[0]++;
        if(moves[i] == 'D') arr[1]++;
        if(moves[i] == 'L') arr[2]++;
        if(moves[i] == 'R') arr[3]++;
        i++;
    }
    return arr[0] == arr[1] && arr[2] == arr[3];
}