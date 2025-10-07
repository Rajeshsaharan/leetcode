

void helper(int * nums, int numsSize, int * returnSize, int ** returnColumnSizes, int index, int * subset, int subsetSize, int ** result){
    if(index >= numsSize){
        result[*returnSize] = malloc(sizeof(int) * subsetSize);
        int i =0;
        while(i < subsetSize){
            result[*returnSize][i] = subset[i];
            i++;
        }
        (*returnColumnSizes)[(*returnSize)++] = subsetSize;
        return;
    }

    subset[subsetSize] = nums[index];
    helper(nums, numsSize, returnSize, returnColumnSizes, index+1, subset, subsetSize+1,result);
    helper(nums, numsSize, returnSize, returnColumnSizes, index+1, subset, subsetSize, result);
}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 1 << numsSize;
    int ** result;
    result = malloc(sizeof(*result) *capacity);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(**returnColumnSizes) * capacity);
    int * subset = malloc(sizeof(int) * numsSize);
    helper(nums, numsSize, returnSize, returnColumnSizes, 0, subset, 0, result);
    free(subset);
    return result;

}