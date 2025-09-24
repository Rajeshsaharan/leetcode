struct hash_entry {
    int key;          
    int freq;
    UT_hash_handle hh;
};

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    struct hash_entry * hash = NULL;
    int i =0;
    while(i < nums1Size){
        struct hash_entry * node;
        HASH_FIND_INT(hash, nums1+i, node);
        int key = nums1[i];
        if(node == NULL){
            struct hash_entry * new_node = malloc(sizeof(struct hash_entry));
            new_node->key = nums1[i];
            new_node->freq = 1;
            HASH_ADD_INT(hash, key, new_node);
        }
        i++;
    }
    int size = nums1Size < nums2Size ? nums1Size : nums2Size;
    int * result = malloc(sizeof(int ) * size);
    int j = 0;
    int k = 0;
    while(j < nums2Size && k < size){
        struct hash_entry * node ;
        HASH_FIND_INT(hash, nums2+j , node);
        if(node != NULL && node->freq == 1){
            result[k++] = nums2[j];
            node->freq--;
        }

        j++;
    }
    *returnSize = k;
    return result;
}