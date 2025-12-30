int dp[100001];

bool helper(int *nums, int index, int numsSize) {
    if (index == numsSize - 1) return true;
    if (index >= numsSize) return false;

    if (dp[index] != -1)
        return dp[index];

    for (int i = 1; i <= nums[index]; i++) {
        if (helper(nums, index + i, numsSize)) {
            dp[index] = true;
            return true;
        }
    }

    dp[index] = false;
    return false;
}

bool canJump(int* nums, int numsSize) {
    memset(dp, -1, sizeof(dp));
    return helper(nums, 0, numsSize);
}
