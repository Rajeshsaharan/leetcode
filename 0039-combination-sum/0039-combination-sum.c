
int ** result;
void helper(int * candiadates, int candidatesSize, int target, int sum, int index, int * buffer, int bs, int * returnSize, int ** returnColumnSizes
){
    if(sum == target){
        result[*returnSize] = malloc(sizeof(int) * bs);
        int i = 0;
        while(i < bs){
            result[*returnSize][i] = buffer[i];
            i++;
        }
        (*returnColumnSizes)[*returnSize] = bs;
        (*returnSize)++;
        return;
    }
    if(sum > target) return;
    int i = index;
    while(i < candidatesSize){
        sum += candiadates[i];
        buffer[bs] = candiadates[i];
        helper(candiadates, candidatesSize, target, sum ,i , buffer, bs+1, returnSize, returnColumnSizes);
        sum -= candiadates[i];
        i++;
    }
}



int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    result = malloc(sizeof(*result)  * 10000);
    (*returnColumnSizes) = malloc(sizeof(*returnColumnSizes) * 10000);
    *returnSize = 0;
    int sum = 0, index = 0, bs = 0;
    int * buffer = malloc(sizeof(int) * 10000);
    helper(candidates, candidatesSize, target, sum, index, buffer , bs, returnSize, returnColumnSizes);
    return result;
    
}