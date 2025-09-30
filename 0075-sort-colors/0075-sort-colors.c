void sortColors(int* nums, int numsSize) {
    int arr[3] ={0}; //store color
      int  i =0;
    while(i< numsSize){
        arr[nums[i]]++;
        i++;
    }


    i =0;
    int k =0;
    int j =0;
    while(i < numsSize){
        while(arr[j] <= 0) j++;
        nums[k++] = j;
        arr[j]--;
        i++;
    }
}