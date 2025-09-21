struct hash_entry {
    int val;           //key
    int freq;
    int visited;
    UT_hash_handle hh; /* makes this structure hashable */
};


int longestConsecutive(int* nums, int numsSize) {
    struct hash_entry * hash = NULL;
    int i =0;
    while(i < numsSize){
        struct hash_entry * node;
        HASH_FIND_INT(hash, nums+i, node);
        if(node == NULL){
            struct hash_entry * new_node = malloc(sizeof(struct hash_entry));
            new_node->val = nums[i];
            new_node->freq = 1;
            new_node->visited = 0;
            int val = nums[i];
            HASH_ADD_INT(hash, val, new_node);
        }else{
            node->freq++;
        }
        i++;
    }
    int max = INT_MIN;
    i = 0;
    while(i < numsSize){
        struct hash_entry * current;
        HASH_FIND_INT(hash, nums+i, current);
        if(current != NULL && current->visited){
            i++;
            continue;
        }
        struct hash_entry *  prev;
        int val   = nums[i]-1;
        HASH_FIND_INT(hash, &val, prev);
        if(prev == NULL){
            int count = 0;
            //means we are at starting position on consequative sequence
            val = nums[i];
            while(1){
                struct hash_entry * nd;
                HASH_FIND_INT(hash,&val, nd);
                if(nd == NULL) break;
                nd->visited = 1;
                count++;
                val++;
            }
            max = fmax(count, max);
            
        }
        i++;
    }
    if(max == INT_MIN) return 0;
    return max;
}