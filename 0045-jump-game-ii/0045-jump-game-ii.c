int dp[100001];
int helper(int * nums, int index, int numsSize){
    if(index == numsSize-1 ) return 0;
    if(index >= numsSize) return 0;
    if(dp[index] != -1) return dp[index];
    int i = 1;
    int min = INT_MAX -1;
    while(i <= nums[index]){
        min = fmin(min, helper(nums, index + i, numsSize));
        i++;
    }
    dp[index] = min +1;
    return dp[index];
}


int jump(int* nums, int numsSize) {
    memset(dp, -1, sizeof(dp));
    return helper(nums, 0, numsSize);
}