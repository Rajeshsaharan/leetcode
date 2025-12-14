class Solution {
private:
    Node* helper(Node* head) { 
        Node* current = head;
        while (current) {

            if (current->child) {

                Node* nextNode = current->next;
                Node* childHead = helper(current->child);
                current->next = childHead;
                childHead->prev = current;
                current->child = NULL;
                Node* tail = childHead;
                while (tail->next) {
                    tail = tail->next;
                }
                tail->next = nextNode;
                if (nextNode)
                    nextNode->prev = tail;
            }

            current = current->next;
        }

        return head;
    }

public:
    Node* flatten(Node* head) {
        return helper(head);
    }
};
