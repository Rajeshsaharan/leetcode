char ** result;
void helper(int o, int c, char * buffer, int buffer_size, int * returnSize){
    if(o == 0 && c == 0){
        buffer[buffer_size] = '\0';
         result[*returnSize] = malloc(sizeof(char) * (buffer_size + 1));
       int i = 0;
        while (buffer[i] != '\0') {
            result[*returnSize][i] = buffer[i];
            i++;
        }
        result[*returnSize][i] = '\0';
        (*returnSize)++;
        return;
    }
    if(o == c){
        buffer[buffer_size] = '(';
        helper(o-1, c, buffer, buffer_size +1, returnSize);
    }else{
        if(o == 0){
        buffer[buffer_size] = ')';
        helper(o, c-1, buffer, buffer_size +1, returnSize);
        }else{
            buffer[buffer_size] = '(';
            helper(o-1, c , buffer, buffer_size +1, returnSize);
            buffer[buffer_size] = ')';
            helper(o, c-1, buffer, buffer_size +1, returnSize);
        }
    }


}
char** generateParenthesis(int n, int* returnSize) {
    result = malloc(sizeof(*result) * 10000);
    char * buffer = malloc(sizeof(*buffer) * (n * 2 +1));
    int buffer_size = 0; *returnSize = 0;
    helper(n, n, buffer, buffer_size, returnSize);
    return result;
}