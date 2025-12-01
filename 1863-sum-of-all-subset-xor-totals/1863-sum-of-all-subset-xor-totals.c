int total_xor;
void helper(int *nums, int numsSize, int current_xor, int index) {
    total_xor += current_xor;
    for(int i = index; i < numsSize; i++) {
        int next_xor = current_xor ^ nums[i];
        helper(nums, numsSize, next_xor, i + 1);
 
    }
}

int subsetXORSum(int* nums, int numsSize) {
    total_xor = 0;
    helper(nums, numsSize, 0, 0);
    return total_xor;
}
