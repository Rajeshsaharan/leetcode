char* longestCommonPrefix(char** strs, int strsSize) {
    int size = strlen(strs[0]);
    if (size == 0) return "";
    char * arr = malloc(size+1 * sizeof(char));
    arr[0] = '\0';
    int i =0;
    while(strs[0][i] != '\0'){
        arr[i] = strs[0][i];
        i++;
    }
    arr[i] = '\0';
    i =1;
    while(i < strsSize){
        int j = 0;
        while(strs[i][j] != '\0' && j < size ){
            if(strs[i][j] != arr[j]){
                arr[j] = '\0';
                break;
            }
            j++;
        }
        arr[j] = '\0';
    i++;
    }
    return arr;
}