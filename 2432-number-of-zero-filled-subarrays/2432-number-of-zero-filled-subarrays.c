long long zeroFilledSubarray(int* nums, int numsSize) {
    long long int total_subarray = 0, zero_count = 0;
    int i = 0;
    while(i < numsSize){
        if(nums[i] ==0){
            zero_count++;
        }else{
            total_subarray += zero_count *(zero_count +1)/2;
            zero_count  =0;
        }
        i++;
    }
    //handling endge case
    if(nums[i-1] == 0) total_subarray += zero_count *(zero_count +1) /2;
    return total_subarray;
}