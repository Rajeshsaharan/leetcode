int dp[100001];

int helper(int *nums, int index, int numsSize) {
    if (index == numsSize - 1)
        return 0;

    if (index >= numsSize)
        return INT_MAX - 1;

    if (dp[index] != -1)
        return dp[index];

    int minJumps = INT_MAX - 1;

    for (int i = 1; i <= nums[index]; i++) {
        minJumps = fmin(minJumps,
                        helper(nums, index + i, numsSize));
    }

    dp[index] = minJumps + 1;
    return dp[index];
}

int jump(int* nums, int numsSize) {
    memset(dp, -1, sizeof(dp));
    return helper(nums, 0, numsSize);
}
