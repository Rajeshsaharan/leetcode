int ** result;
int  * subset;

void helper(int * nums, int numsSize, int * returnSize, int ** returnColumnSizes, int index, int subsetSize){
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
    helper(nums, numsSize, returnSize, returnColumnSizes, index+1,subsetSize+1);
    helper(nums, numsSize, returnSize, returnColumnSizes, index+1, subsetSize);
}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 1 << numsSize;
    result = malloc(sizeof(*result) *capacity);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(**returnColumnSizes) * capacity);
    subset = malloc(sizeof(int) * numsSize);
    helper(nums, numsSize, returnSize, returnColumnSizes, 0,  0);
    free(subset);
    return result;

}