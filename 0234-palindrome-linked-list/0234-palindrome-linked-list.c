
struct ListNode * current;
bool helper(struct ListNode * head){
    if(head == NULL) return true;
    bool ans = helper(head->next) && current->val == head->val;
    current = current->next;
    return ans;
}


bool isPalindrome(struct ListNode* head) {
    current = head;
    return helper(head);
}