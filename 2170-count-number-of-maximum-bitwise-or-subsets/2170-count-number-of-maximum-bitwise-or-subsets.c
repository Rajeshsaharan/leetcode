int bitwise_or(int * arr, int size){
    if(size == 0) return size;
    int result = arr[0];
    int i = 1;
    while(i< size) result |= arr[i++];
    return result;
}

int *subset,max , count; //declaring global instead passing by function para
void helper(int * nums, int numsSize, int index, int subsetSize){
    if(index >= numsSize){
        if(max == bitwise_or(subset, subsetSize)) count++;
        return;
    }
    subset[subsetSize] = nums[index];
    helper(nums, numsSize, index+1, subsetSize+1);
    helper(nums, numsSize, index+1, subsetSize);
}



int countMaxOrSubsets(int* nums, int numsSize) {
    max = bitwise_or(nums, numsSize);
    subset = malloc(sizeof(*subset) * numsSize); //subset can exceed only to numsSize;
    count = 0;
    helper(nums, numsSize, 0, 0);
    return count;
}

