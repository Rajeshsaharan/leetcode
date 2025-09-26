struct hash_entry {
    struct ListNode * nd; //also works like key
    UT_hash_handle hh;
};




bool hasCycle(struct ListNode *head) {
    struct hash_entry * hash = NULL;
    while(head){
        struct hash_entry * node, *new_node;
        struct ListNode * nd = head;
        HASH_FIND_INT(hash, &nd, node);
        if(node != NULL)return true;
        new_node = malloc(sizeof(*new_node));
        new_node->nd = head;
        HASH_ADD_INT(hash,nd, new_node);
        head = head->next;
    }
    return false;
}
