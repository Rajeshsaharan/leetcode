


int arr[2]; //global arr declare
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int store_arr_freq[101] = {0};
    int i = 0, k = 0;
    while(i < numsSize) store_arr_freq[nums[i++]]++;
    i = 0;
    while(i < numsSize){
        if(store_arr_freq[nums[i]] == 2 && k < 2){
            if(k == 0) arr[k++] = nums[i];
            else if(arr[k-1] != nums[i]) arr[k++] = nums[i];
        }
        i++;
    }
    *returnSize = k;
    return arr;

}