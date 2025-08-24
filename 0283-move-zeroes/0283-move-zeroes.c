void swap(int * a ,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void moveZeroes(int* nums, int numsSize) {
    int zp = 0; // zp pointer points to zero element
    int nzp = 0; //nzp pointer points to non zero element
    //finding first nzp value
    while(nzp < numsSize){
        if(nums[nzp] != 0){
            swap(nums + zp, nums+nzp);
            zp++;
        }
        nzp++;
    }

}