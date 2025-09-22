int maxArea(int* height, int heightSize) {
    int i = 0;
    int j = heightSize - 1;
    int max = INT_MIN;
    while(i < j){
        int min = fmin(height[i] , height[j]);
        int side = j - i;
        int area = min * side;
        max  = fmax(max, area);
        if(height[i] < height[j]){
            i++;
        }else{
            j--;
        }
    }

    return max;
}