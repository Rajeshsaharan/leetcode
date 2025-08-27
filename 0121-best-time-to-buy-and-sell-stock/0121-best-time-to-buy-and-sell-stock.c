



int maxProfit(int* prices, int pricesSize) {
    int min  = INT_MAX, result = INT_MIN, i =0;
    while(i < pricesSize){
        if(prices[i] <  min){
            // got min value
            min = prices[i];
            int j = i+1;
            while(j < pricesSize && prices[j] >= min){
                int diff = prices[j] - min;
                result = fmax(diff, result);
                j++;
            }
        }
        i++;
    }
    if ( result == INT_MIN){
        return 0;
    }else{
        return result;
    }

}