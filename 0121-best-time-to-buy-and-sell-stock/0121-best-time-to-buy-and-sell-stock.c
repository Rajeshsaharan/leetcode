

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int min_cost = prices[0], i = 0;
    while (i < pricesSize) {
        if(min_cost > prices[i]){ min_cost = prices[i];};
        profit = fmax(profit, prices[i]- min_cost);
        i++;    }

    return profit;
}