int dp[1002];
int helper(int * cost, int costSize, int index){
    if(index >= costSize) return 0;// return a large number
    if(dp[index] != -1) return dp[index];
    int min = fmin(helper(cost, costSize, index +1), helper(cost,costSize, index +2));
    return dp[index] = min + cost[index];
}


int minCostClimbingStairs(int* cost, int costSize) {
    memset(dp, -1, sizeof(dp));
    int result1 = helper(cost, costSize, 0);
    int result2= helper(cost, costSize, 1);
    return fmin(result1, result2);
}