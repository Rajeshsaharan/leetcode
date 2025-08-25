int majorityElement(int* nums, int numsSize) {
    int i =0 , vote =0, select = -1;
    while(i < numsSize){
        if(vote ==0){
            select= nums[i++];
            vote = 1;
        }else{
            if(nums[i++] == select) vote++;
            else vote--;
        }
    }
    int count = 0; i =0;;
    while(i < numsSize) if(select == nums[i++]) count++;
    if(count > numsSize/2) return select;
    return -1;
}