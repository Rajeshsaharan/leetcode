int size;
int is_found(char* buf, char** nums, int n) {
    char* endptr;
    long int decimalValue = strtol(buf, &endptr, 2);
    int i = 0;
    while(i < n){
        char * endptr2;
        long int inner_decimal_value = strtol(nums[i], &endptr2, 2);
        if(inner_decimal_value == decimalValue) return 1;
        i++;
    }
    return 0;  
}

char * helper(char** nums, int n, char* buf, int bs) {
    if (n == 0) {
        buf[bs] = '\0';
        char* endptr;
        if (is_found(buf, nums, size) == 0)
            return buf;
        else return NULL;
    }
    buf[bs] = '0';
    char * val =  helper(nums, n - 1, buf, bs + 1);
    if(val != NULL) return val;
    buf[bs] = '1';
    return helper(nums, n - 1, buf, bs + 1);
}

char* findDifferentBinaryString(char** nums, int numsSize) {
    size = numsSize;
    char* buf = malloc(sizeof(char) * (numsSize + 1));
    int bs = 0;
    return helper(nums, numsSize, buf, bs);
}