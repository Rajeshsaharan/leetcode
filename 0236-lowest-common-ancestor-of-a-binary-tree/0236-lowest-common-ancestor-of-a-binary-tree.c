
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL || root->val == p->val || root->val == q->val) return root;
    struct TreeNode * left_found = lowestCommonAncestor(root->left,p,q);
    struct TreeNode * right_found = lowestCommonAncestor(root->right, p, q);
    if(left_found != NULL && right_found != NULL) return root;
    return left_found ? left_found : right_found;
}