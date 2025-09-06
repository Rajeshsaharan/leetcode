/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    *returnSize = n+1;
    int * result = malloc((*returnSize) * sizeof(int));
    int lookup_int =1,lookup_index = 1, count = 0;
    result[0] = 0;
    int i =1;
    while(i < *returnSize){
        if(i == lookup_int){
            count =1;
            result[i] = count;
            lookup_int = lookup_int * 2;
            lookup_index = i;
        }else{
            count = result[i -lookup_index] + 1;
            result[i] = count;
        }
    i++;
    }
    return result;
}