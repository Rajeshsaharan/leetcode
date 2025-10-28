int countValidSelections(int* nums, int numsSize) {
    int result_arr[numsSize];
    result_arr[0] = nums[0];
    int i = 1;
    while(i < numsSize){
        result_arr[i] = nums[i] + result_arr[i-1];
        i++;
    }
    int total = result_arr[numsSize -1];
    i = 0;
    while(i < numsSize){
        printf(" %d", result_arr[i]);
        i++;
    }
    printf("total is %d", total);
    i = 1;
    int ans = 0;
    if(total == 0){
        return numsSize * 2;
    }
    if(total == 1 && nums[0] == 0){
        ans =ans+1;
    }
    while(i < numsSize){
        if(nums[i] == 0){
            if(total - result_arr[i-1]== result_arr[i-1]){
                ans = ans+2;
            }
            if(total-result_arr[i-1] +1 == result_arr[i-1] || total- result_arr[i-1]-1 == result_arr[i-1]){
                ans = ans+1;
            }
        }
        i++;
    }
    return ans;
}