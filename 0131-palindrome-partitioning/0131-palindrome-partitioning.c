

int is_palindrome(char * arr, int l , int r){
    while(l < r){
        if(arr[l] != arr[r]) return 0;
        l++;
        r--;
    }
    return 1;
}
char ***result;
void helper(char *s, int index,int n,char ** path, int path_len, int *returnSize, int **returnColumnSizes) {
   if(index >= n){
    result[*returnSize]= malloc(sizeof(char *)* path_len);
    (*returnColumnSizes)[*returnSize] = path_len;
    int i =0;
    while(i < path_len){
        int path_i_len = strlen(path[i]);
        result[*returnSize][i] = malloc(sizeof(char) * (path_i_len + 1));
        memcpy(result[*returnSize][i], path[i], (path_i_len +1)); 
        i++;
    }
    (*returnSize)++;
    return;
   }
    int i = index;
    while(i < n){
        if(is_palindrome(s, index, i)){
        int len = i-index +1; // for length;
        path[path_len] = malloc(sizeof(char) * (len +1));
        memcpy(path[path_len] , s + index, len); // cpy the byte till len ;
        path[path_len][len] = '\0';
        helper(s, i +1, n, path, path_len +1 , returnSize, returnColumnSizes);
        }
        i++;
    }

}


char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    result = malloc(sizeof(char **) * 100000);
    *returnColumnSizes = malloc(sizeof(int) * 100000);
    *returnSize = 0;
    char ** path = malloc(sizeof(char *) * (n +1));
    int path_len = 0;
    helper(s, 0, n, path , path_len, returnSize, returnColumnSizes);
    return result;
}