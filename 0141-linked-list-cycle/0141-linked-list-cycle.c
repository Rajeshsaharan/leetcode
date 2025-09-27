/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL ) return false;
   struct ListNode * current1,*current2;
   current1 = head, current2 = head;
   while(current2 && current2->next){
     current1   = current1->next;
    current2 = current2->next->next;

    if(current1 == current2){
        return true;
    }
   
   }
   return false;
}