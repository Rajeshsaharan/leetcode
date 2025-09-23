
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int * result = malloc(sizeof(int) * (*returnSize));
    int i = 0;
    int j = numsSize -1;
    int k = numsSize -1;
    while(i <= j){
        int first = nums[i] * nums[i];
        int second = nums[j] * nums[j];
        if(second > first){
            result[k--] = second;
            j--;
        }else{
            result[k--] = first;
            i++;
        }

    }
    return result;
}