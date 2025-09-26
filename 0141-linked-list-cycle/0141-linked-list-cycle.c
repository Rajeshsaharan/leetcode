struct hash_entry {
    struct ListNode * nd; //also works like key
    UT_hash_handle hh;
};




bool hasCycle(struct ListNode *head) {
    struct hash_entry * hash = NULL;
    struct ListNode * current = head;
    while(current){
        struct hash_entry * node;
        struct ListNode * nd = current;
        HASH_FIND_INT(hash, &nd, node);
        if(node != NULL){
            return true;
        }
        printf("node->val %d\n", current->val);
        struct hash_entry * new_node;
        new_node = malloc(sizeof(*new_node));
        new_node->nd = current;
        HASH_ADD_INT(hash,nd, new_node);
        current = current->next;
    }

    return false;
}
