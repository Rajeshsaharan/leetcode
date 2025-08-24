void moveZeroes(int* nums, int numsSize) {
//we need to collect non zero elements
    int count = 0;
    int i =0;
    while (i < numsSize)  { if(nums[i] != 0) count++; i++; }
    if(count ==0) return;
    int non_zero_array[count];
    i = 0;
    int j =0;
    while(i < numsSize) { if(nums[i] != 0) non_zero_array[j++] = nums[i]; i++; };
    i =0;
    while(i < count){nums[i] = non_zero_array[i]; i++;}
    i = count;
    while(i < numsSize){ nums[i] = 0; i++;}

}