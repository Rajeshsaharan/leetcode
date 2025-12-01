int total_xor;
void helper(int *nums, int numsSize, int current_xor, int index) {
    total_xor += current_xor;
    for(int i = index; i < numsSize; i++) {
        helper(nums, numsSize, current_xor ^ nums[i], i + 1);
 
    }
}

int subsetXORSum(int* nums, int numsSize) {
    total_xor = 0;
    helper(nums, numsSize, 0, 0);
    return total_xor;
}
