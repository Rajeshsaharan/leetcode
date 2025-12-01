char ** result;
int is_valid(char * str, int start, int end){
    if(start > end) return 0;
    if(str[start] == '0' && start != end) return 0;
    int num = 0;
    for (int i = start; i <= end; i++)
        num = num * 10 + (str[i] - '0');

    return num <= 255;
}

void helper(char *s , int index,int dots, int * returnSize, char * currentIp, int pos){
    if(dots == 4 && index == strlen(s)){
        currentIp[pos] = '\0';
        result[*returnSize] = malloc(sizeof(char) * (pos+1));
        int i = 0;
        while(currentIp[i] != '\0'){
            result[*returnSize][i] = currentIp[i];
            i++;
        }
        result[*returnSize][i] = '\0';
        (*returnSize)++;
        return;

    }

    if(dots >= 4) return;
    int i = 0;
    while(i < index + 3 && i < strlen(s)){
        if(is_valid(s, index, i)){
            int temp_pos = pos; //some approach that can help to understand recursion better 
            int k = index;
            while(k <= i){
                currentIp[pos++] = s[k];
                k++;
            }
            if(dots < 3){
                currentIp[pos++] = '.';
            }
        helper(s, i+1, dots +1, returnSize, currentIp, pos);
        pos = temp_pos; // this one also
        currentIp[pos] = '\0'; // recursion steps added later
        }
        i++;
    }
}


char** restoreIpAddresses(char* s, int* returnSize) {
    result = malloc(sizeof(*result) * 10000);
    char * currentIp = malloc(sizeof(*currentIp) * 20) ;// all possible .... + 16 char 
    *returnSize = 0;
    helper(s, 0,0, returnSize,currentIp, 0);
    return result;

}