int numIdenticalPairs(int* nums, int numsSize) {
    int arr[101], i =0; //arr set to according to constrainsts
    while(i < numsSize) arr[nums[i++]]++;
    i = 1; int count =0;
    while(i < 101){
       if(arr[i] > 1){
        count += arr[i] * (arr[i] -1) /2;
       }
       i++;
    }
   
   return count;


}