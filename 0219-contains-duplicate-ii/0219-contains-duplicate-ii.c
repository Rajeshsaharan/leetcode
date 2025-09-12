struct hash_entry {
    int value;
    int index;
    UT_hash_handle hh; /* makes this structure hashable */
};

int my_abs(int a, int b) {
    __asm__ volatile("sub %1, %0;"
                     "cmpl $0 ,%0;"
                     "jl 2f;"
                     "2:\n\t"
                     "neg %0;"
                     : "+r"(b)
                     : "r"(a)
                     :);
    return b;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int i = 0;
    struct hash_entry* ht = NULL;
    while (i < numsSize) {
        struct hash_entry* h;
        int value = nums[i];
        HASH_FIND_INT(ht, &value, h);
        struct hash_entry* node = malloc(sizeof(struct hash_entry));
        if (h == NULL) {
            node->index = i, node->value = value;
            HASH_ADD_INT(ht, value, node);
        }else{
            if(abs(i-(h->index)) <= k) return true;
             node->index = i, node->value = value;
            HASH_ADD_INT(ht, value, node);

        }
        i++;
    }
    return false;
}