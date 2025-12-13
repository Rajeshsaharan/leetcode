
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL || p->val != q->val) return false;
    bool left_decision = isSameTree(p->left, q->left);
    bool right_decision = isSameTree(p->right, q->right);
    return left_decision && right_decision;    
}