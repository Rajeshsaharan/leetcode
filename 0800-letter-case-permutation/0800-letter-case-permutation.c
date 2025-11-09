char** result;

void helper(char* s, char* buffer, int index, int buffer_size, int* returnSize,
            int size) {
    if (index >= size) {
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
    if (s[index] >= 48 && s[index] <= 57) {
        buffer[buffer_size] = s[index];
        helper(s, buffer, index + 1, buffer_size + 1, returnSize, size);
        return;
    } else if(s[index] >= 97 && s[index] <= 122){
        buffer[buffer_size] = s[index];
        helper(s, buffer, index + 1, buffer_size + 1, returnSize, size);
        buffer[buffer_size] = s[index] - 32;
        helper(s, buffer, index + 1, buffer_size + 1, returnSize, size);
    }else{
        buffer[buffer_size] = s[index] +32;
        helper(s, buffer, index+1, buffer_size +1, returnSize, size);
        buffer[buffer_size] = s[index];
        helper(s, buffer, index +1, buffer_size +1 , returnSize, size);
    }
}

char** letterCasePermutation(char* s, int* returnSize) {
    int size = strlen(s);
    result = malloc(sizeof(*result) * 5000);
    char* buffer = malloc(sizeof(*buffer) * (size + 1));
    int index = 0, buffer_size = 0;
    *returnSize = 0;
    helper(s, buffer, index, buffer_size, returnSize, size);
    return result;
}