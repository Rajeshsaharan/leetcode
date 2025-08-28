int gcd(int a,int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}
int findGCD(int* nums, int numsSize) {
    int min = INT_MAX, max = INT_MIN, i =0;
    while(i < numsSize){
        if(nums[i] < min) min = nums[i];
        if(nums[i] > max) max = nums[i];
        i++;
    }
    return gcd(min, max);
}