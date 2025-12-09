int specialTriplets(int* nums, int numsSize) {
    int freq[200001]= {0};
    int l_freq[200001]= {0};
    const int mod = 1000000007;
    int i = 0;
    while(i < numsSize) freq[nums[i++]]++;
    i = 0;
    long long count = 0;
    while(i < numsSize){
        freq[nums[i]]--;
        int value = nums[i] * 2;
        count += 1LL * freq[value] * l_freq[value];
        l_freq[nums[i]]++;
        i++;
    }
    return count % mod;
}