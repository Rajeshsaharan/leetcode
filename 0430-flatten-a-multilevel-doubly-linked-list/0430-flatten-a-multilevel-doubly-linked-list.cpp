class Solution {
private:
    Node * helper(Node * head){
        if(head == NULL) return NULL;
        Node * current = head;
        while(current->next != NULL && current->child == NULL){
            current = current->next;
        }
        if(current->child != NULL){
            Node * from_ret = helper(current->child);
            Node * temp = current->next;

            current->next = from_ret;
            from_ret->prev = current;
            current->child = NULL;

            Node * tail = from_ret;
            while(tail->next != NULL){
                tail = tail->next;
            }

            tail->next = temp;
            if(temp != NULL){
                temp->prev = tail;
                helper(temp);
            }
        }
        return head;
    }

public:
    Node* flatten(Node* head) {
       return helper(head);
    }
};