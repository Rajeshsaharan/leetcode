int maxProfit(int* prices, int pricesSize) {
    int buy = prices[0], profit = 0, i = 1;
    while (i < pricesSize){
        if(buy < prices[i]){
            profit += prices[i] - buy;
        }
        buy = prices[i];
        i++;
    }
    return profit;
}