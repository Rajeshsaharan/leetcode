int dp[100001];
bool helper(int * nums, int index, int numsSize){
    if(index == numsSize-1) return true;
    if(index >= numsSize) return false;
    if(dp[index] != -1) return dp[index];
    int i = 1;
    while(i <= nums[index]){
        bool flag =  helper(nums, index+ i, numsSize);
        dp[index] = flag;
        if(flag) return true;
        i++;
    }
    return dp[index] = false;
    
}
bool canJump(int* nums, int numsSize) {
    memset(dp, -1, sizeof(dp));
    //firstly do with recursion 
     return helper(nums, 0, numsSize);
}