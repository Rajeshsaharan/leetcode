int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    int j = 0;
    while (i < numsSize) {
        if ((nums[i] & nums[i] - 1) != 0 || nums[i] == 1) {
            j = i;
            break;
        }
        i++;
    }
    while (i < numsSize) {
        if (nums[i] % 2 == 0) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }

        i++;
    }
    *returnSize = 0;
    int * result;
    result = malloc(sizeof(*result) * numsSize);
    printf("returnSize %d", *returnSize);
    while(*returnSize < numsSize){
        result[*returnSize] = nums[*returnSize];
        printf("returnSize %d", *returnSize);
        (*returnSize)++;
    }
    return result;
}