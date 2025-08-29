long long zeroFilledSubarray(int* nums, int numsSize) {
    int i =0;
    long long int total_possible_subarray = 0;
    long long int start_index_of_zero_subarray = 0;;
    while(i < numsSize){
        if(nums[i] == 0){
            start_index_of_zero_subarray++;
        }else{
            total_possible_subarray += start_index_of_zero_subarray * (start_index_of_zero_subarray +1) /2;
            start_index_of_zero_subarray = 0;
        }


        i++;
    }

    if(nums[i-1] == 0){ total_possible_subarray += start_index_of_zero_subarray * (start_index_of_zero_subarray +1) /2;};
    return total_possible_subarray;
}