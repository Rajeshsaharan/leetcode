int arr[101];
int * result;
int k;

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int i =0, k = 0;
    memset(arr, 0,sizeof(arr));
    int * result = malloc(sizeof(*result) * 101);
    while(i < numsSize) arr[nums[i++]] = 1;
    int max = INT_MIN, min = INT_MAX;
    i = 0;
    while(i < numsSize){
        if(nums[i] < min) min = nums[i];
        if(nums[i] >= max) max = nums[i];
        i++;
    }
    while(min <= max){
        if(arr[min] ==0) result[k++] = min;
        min++;
    }
    *returnSize = k;
    return result;
}