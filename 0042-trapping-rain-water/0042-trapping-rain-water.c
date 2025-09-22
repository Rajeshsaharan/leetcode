int trap(int* height, int heightSize) {
    int dpi[heightSize];
    int dpj[heightSize];
    dpi[0] = height[0];
    dpj[heightSize - 1] = height[heightSize - 1];
    int water = 0;
    int i = 1;
    while (i < heightSize) {
        if (height[i] > dpi[i - 1]) {
            dpi[i] = height[i];
        } else {
            dpi[i] = dpi[i - 1];
        }
        i++;
    }
    int j = heightSize -2;
    while(j >= 0){
            if(height[j] > dpj[j+1]){
                dpj[j] = height[j];
            }else{
                dpj[j] = dpj[j+1];
            }
        j--;
    }
    i = 0;
    while(i < heightSize){
        water += fmin(dpi[i],dpj[i])- height[i];
        i++;
    }

    return water;
}