struct ht{
    int key;
    int data;
    UT_hash_handle hh;
};

int firstMissingPositive(int* nums, int numsSize) {
    int i = 0, min = INT_MAX;
    struct ht * hash = NULL;
    while(i < numsSize){
        if(nums[i] <= min && nums[i] > 0){
            min = nums[i];
        }
        if(nums[i] > 0) {
            int key = nums[i];
            struct ht * s = malloc(sizeof(struct ht));
            s->key =nums[i];
            s->data = 1;
           HASH_ADD_INT(hash, key, s);
        }
        i++;
    }
    if (min > 1) return 1;
    i = 1;
    while(i <= numsSize){
            struct ht * s;
            HASH_FIND_INT(hash, &i, s);
            if(s == NULL){
                break;
            }
        i++;
    }
    return i;
}