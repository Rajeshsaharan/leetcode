/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void print(int * arr, int n){
    int i = 0;
    while(i < n){
        printf("index %d and item -> %d\n", i ,arr[i]);
        i++;
    }
}




int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
   int left_perfix[numsSize];
   int right_perfix[numsSize];
   left_perfix[0] = 1; int  i =1;
   while(i< numsSize){
    left_perfix[i] = left_perfix[i-1] * nums[i-1];
    i++;
   }
   print(left_perfix , numsSize);
   // [1,1,2,6]
    right_perfix[numsSize -1] = 1; i = numsSize -2;
    while(i >= 0){
        right_perfix[i] = right_perfix[i+1] * nums[i+1];
        i--;
    }
    print(right_perfix, numsSize);
    int  * result = (int * ) malloc(numsSize * sizeof(int));
    i = 0 ;
    while(i < numsSize){
        result[i] = left_perfix[i] * right_perfix[i];
        i++;
    }
    *returnSize = numsSize;
    return result;
}