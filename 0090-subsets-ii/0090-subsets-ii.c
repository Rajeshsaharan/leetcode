int compare_asc(const void * a, const void * b){
    return *(int *)a- *(int* )b;
}



bool compare_array(int* arr1, int arr1_size, int* arr2, int arr2_size) {
    if (arr1_size != arr2_size)
        return false;
    for (int i = 0; i < arr1_size; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

int** result;
int* subset;

void helper(int* nums, int numsSize, int index, int* subset, int subsetSize,
            int* returnSize, int** returnColumnSizes) {
    int* copy = (int*)malloc(subsetSize * sizeof(int));
    for (int i = 0; i < subsetSize; i++)
        copy[i] = subset[subsetSize - i - 1];
    int duplicate = 0;
    for (int i = 0; i < *returnSize; i++) {
        if (compare_array(result[i], (*returnColumnSizes)[i], subset, subsetSize) ||
            compare_array(result[i], (*returnColumnSizes)[i], copy, subsetSize)) {
            duplicate = 1;
            break;
        }
    }
    free(copy);
    if (!duplicate) {
        result[*returnSize] = (int*)malloc(subsetSize * sizeof(int));
        memcpy(result[*returnSize], subset, subsetSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = subsetSize;
        (*returnSize)++;
    }
    for (int j = index; j < numsSize; j++) {
        subset[subsetSize] = nums[j];
        helper(nums, numsSize, j + 1, subset, subsetSize + 1, returnSize, returnColumnSizes);
    }
}




int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(*nums), compare_asc);
    int capacity = 1 << numsSize; // 2^n subsets max
    result = malloc(sizeof(*result) * capacity);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(**returnColumnSizes) * capacity);
    subset = malloc(sizeof(int) * numsSize);
    helper(nums, numsSize, 0, subset, 0, returnSize, returnColumnSizes);
    return result;
}