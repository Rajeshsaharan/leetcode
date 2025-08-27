//first solution -> using extra array;
//cyclic index 
void rotate(int* nums, int numsSize, int k) {
   int i = 0;
   int rotated[numsSize];
   //for left rotate i+k 
   //for right rotoate i+k-1 
   while(i < numsSize) rotated[(i+k-1) % numsSize] = nums[i++];
   i= 0;
   while(i < numsSize){
    nums[i] = rotated[i];
    i++;
   }
}
