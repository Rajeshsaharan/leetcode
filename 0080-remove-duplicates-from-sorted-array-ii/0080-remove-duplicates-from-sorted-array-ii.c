int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j = 0, k = 0, z= 0;
    while (i < numsSize) {
        if (nums[i] != nums[j]) {
            int size = z < 2 ? z : 2;
            int x = 0;
            while(x++ < size) nums[k++] = nums[j];
            z = 0, j = i; // reset and new unique
        }
        else z++, i++;
    }
    //edge case handling important ! 
    i = j;
    int size = numsSize -j < 2 ? numsSize-j : 2;
    int x = 0;
    while(x++ < size) nums[k++] = nums[j];
    return k;
}