int ** result;

void helper(int * nums, int numsSize, int * returnSize,
            int ** returnColumnSizes, int index, int * buf, int bs) {

    if (bs >= 2) {
        result[*returnSize] = malloc(sizeof(int) * bs);
        memcpy(result[*returnSize], buf, bs * sizeof(int));
        (*returnColumnSizes)[*returnSize] = bs;
        (*returnSize)++;
    }

    if (index >= numsSize) return;


    int check_used[201] = {0}; //-100 to 100 
    int i = index;
    while (i < numsSize) {
        if (bs > 0 && nums[i] < buf[bs-1]) {
            i++;
            continue;
        }

        if(check_used[nums[i] + 100]){
            i++;
            continue;
        }
        check_used[nums[i] +100] = 1;
        buf[bs] = nums[i];
        helper(nums, numsSize, returnSize, returnColumnSizes, i + 1, buf, bs + 1);
        i++;
    }
}
int** findSubsequences(int* nums, int numsSize,
                       int* returnSize, int** returnColumnSizes) {
    result = malloc(sizeof(*result) * 1000000);
    int * buf = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 1000000);
    int bs = 0;
    helper(nums, numsSize, returnSize, returnColumnSizes, 0, buf, bs);
    return result;
}
