int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int dp[neededTimeSize];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    int i = 1;
    int sum =0;
    while(colors[i] != '\0'){
        if(colors[i] == colors[i-1]){
            sum  += fmin(neededTime[i], neededTime[i-1]);
            neededTime[i] = fmax(neededTime[i], neededTime[i-1]);
        }
        i++;
    }
   
    return sum;
}