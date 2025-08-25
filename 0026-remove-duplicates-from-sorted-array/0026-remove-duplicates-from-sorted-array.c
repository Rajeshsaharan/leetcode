int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j = 0, count = 0;
    while (i <numsSize) {
        if (nums[i] != nums[j]){
            j = i;
            count++;
        }
        i++;
    };
    int result[++count]; //++count for size
    i = 0, j = 0;
    int k = 1;
    result[0] = nums[0];
    while(i < numsSize){
        if(nums[i] != nums[j]){
            j = i;
            result[k++] = nums[i];
        }
        i++;
    }
    i = 0;
    while(i < count){
        nums[i] = result[i];
        i++;
    }
    return count;
}