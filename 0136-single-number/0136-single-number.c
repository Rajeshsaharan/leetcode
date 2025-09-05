int singleNumber(int* nums, int numsSize) {
    int i =0, result = 0;
    while(i < numsSize) result ^= nums[i++];
    return result;
}