struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *current = head;
    int count = 0;

    // Check if there are at least k nodes
    while (current != NULL && count != k) {
        current = current->next;
        count++;
    }

    if (count == k) {
        // Recursively reverse the remaining list from 'current'
        current = reverseKGroup(current, k);

        // Reverse first k nodes
        while (count--) {
            struct ListNode *temp = head->next;
            head->next = current;
            current = head;
            head = temp;
        }

        return current;  // new head of this segment
    }

    // Less than k nodes remaining, do not reverse
    return head;
}
