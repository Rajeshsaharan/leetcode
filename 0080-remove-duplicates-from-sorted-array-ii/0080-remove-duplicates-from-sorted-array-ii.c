int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int j = 0;
    int k = 0;
    int z = 0;
    while (i < numsSize) {
        if (nums[i] != nums[j]) {
            int size = fmin(z, 2);
            int x = 0;
            while(x < size){
                nums[k++] = nums[j];
                x++;
            }
            z= 0;
            j = i;
        }else{
            z++;
            i++;
        }
    }
    //edge case handinlg
    i = j;
    z  = 0;
    while(i < numsSize){
        z++;
        i++;
    }
    printf("i is %d", i);
    int size = fmin(z, 2);
    int x = 0;
    while(x < size){
        nums[k++] = nums[j];
        x++;
    }

    return k;
}